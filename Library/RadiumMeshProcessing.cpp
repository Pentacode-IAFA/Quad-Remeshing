
#include "PrivateHeader.hpp"
#include <RadiumMeshProcessing.hpp>

#include <Core/Resources/Resources.hpp>
#include <Core/Utils/Log.hpp>

#include <fstream>
#include <string>

#include <Core/Geometry/TopologicalMesh.hpp>
#include <Engine/Data/Mesh.hpp>
#include <Engine/RadiumEngine.hpp>

namespace RadiumMeshProcessing {
using namespace Ra::Core::Utils;

// This symbol will be used to identify the library and find its directory using
// Ra::Core::Resources::ResourcesLocator.
static int RadiumMeshProcessingMagick = 0xAFBFCFDF;

RadiumMeshProcessing_API bool initializeRadiumMeshProcessing() { return false; }

RadiumMeshProcessing_API bool finalizeRadiumMeshProcessing() { return false; }

void RadiumMeshProcessingWelcome(const std::string &message) {
  auto resourcesPath = Ra::Core::Resources::getResourcesPath(
      reinterpret_cast<void *>(&RadiumMeshProcessingMagick),
      "Resources/QuadRemeshingResources");
  if (!resourcesPath) {
    LOG(logERROR) << RadiumMeshProcessingPrefix
                  << " -- Unable to find resource directory. Abort";
    abort();
  }
  std::string welcomeMsg = *resourcesPath + "/welcome.txt";
  std::ifstream inputMsg(welcomeMsg);
  if (inputMsg.is_open()) {
    std::stringstream buffer;
    buffer << inputMsg.rdbuf();
    LOG(logINFO) << RadiumMeshProcessingPrefix << " -- " << message
                 << buffer.str() << " at " << welcomeMsg;
  } else {
    LOG(Ra::Core::Utils::logINFO)
        << RadiumMeshProcessingPrefix << " -- " << message << " -- "
        << "Unable to open resource file " << welcomeMsg;
  }
}

void LaplacianSmoothing(ProcessingParameter p) {
  using Ra::Core::Geometry::TopologicalMesh;
  using Ra::Engine::Data::Mesh;
  using Ra::Engine::Data::PolyMesh;

  LOG(logINFO) << RadiumMeshProcessingPrefix << " -- Laplacian smoothing on "
               << p.entityName << " // " << p.componentName;

  auto trianglemesh =
      dynamic_cast<Mesh *>(Ra::Engine::RadiumEngine::getInstance()->getMesh(
          p.entityName, p.componentName));
  auto polymesh =
      dynamic_cast<PolyMesh *>(Ra::Engine::RadiumEngine::getInstance()->getMesh(
          p.entityName, p.componentName));

  bool isPolyMesh = polymesh != nullptr ? true : false;
  TopologicalMesh *topologicalMesh;
  if (isPolyMesh) {
    LOG(logINFO) << "Start processing polymesh " << polymesh->getName();
    topologicalMesh = new TopologicalMesh(polymesh->getCoreGeometry());
  } else {
    LOG(logINFO) << "Start processing trianglemesh" << trianglemesh->getName();
    topologicalMesh = new TopologicalMesh(trianglemesh->getCoreGeometry());
  }

  OpenMesh::VPropHandleT<Scalar> vertex_weights_;
  topologicalMesh->add_property(vertex_weights_);

  for (auto v_it = topologicalMesh->vertices_begin();
       v_it != topologicalMesh->vertices_end(); ++v_it) {
    topologicalMesh->property(vertex_weights_, *v_it) = 0.0_ra;
  }

  TopologicalMesh::Scalar lb(-1.0_ra), ub(1.0_ra);

  TopologicalMesh::EdgeIter e_it, e_end(topologicalMesh->edges_end());
  for (e_it = topologicalMesh->edges_begin(); e_it != e_end; ++e_it) {
    auto weight = 0.0_ra;

    auto heh0 = topologicalMesh->halfedge_handle(*e_it, 0);
    auto p0 = &topologicalMesh->point(topologicalMesh->to_vertex_handle(heh0));

    auto heh1 = topologicalMesh->halfedge_handle(*e_it, 1);
    auto p1 = &topologicalMesh->point(topologicalMesh->to_vertex_handle(heh1));

    auto heh2 = topologicalMesh->next_halfedge_handle(heh0);
    auto p2 = &topologicalMesh->point(topologicalMesh->to_vertex_handle(heh2));
    TopologicalMesh::Normal d0 = (*p0 - *p2);
    d0.normalize();
    TopologicalMesh::Normal d1 = (*p1 - *p2);
    d1.normalize();
    weight += 1.0_ra / std::tan(acos(std::max(lb, std::min(ub, d0.dot(d1)))));

    heh2 = topologicalMesh->next_halfedge_handle(heh1);
    p2 = &topologicalMesh->point(topologicalMesh->to_vertex_handle(heh2));
    d0 = (*p0 - *p2);
    d0.normalize();
    d1 = (*p1 - *p2);
    d1.normalize();
    weight += 1.0_ra / std::tan(acos(std::max(lb, std::min(ub, d0.dot(d1)))));

    topologicalMesh->property(
        vertex_weights_, topologicalMesh->to_vertex_handle(heh0)) += weight;
    topologicalMesh->property(
        vertex_weights_, topologicalMesh->to_vertex_handle(heh1)) += weight;
  }

  // invert vertex weights:
  // before: sum of edge weights
  // after: one over sum of edge weights
  for (auto v_it = topologicalMesh->vertices_begin();
       v_it != topologicalMesh->vertices_end(); ++v_it) {
    auto weight = topologicalMesh->property(vertex_weights_, *v_it);
    if (weight != 0._ra)
      topologicalMesh->property(vertex_weights_, *v_it) = 1.0_ra / weight;
  }

  std::vector<TopologicalMesh::Point> cogs;

  cogs.reserve(topologicalMesh->n_vertices());
  TopologicalMesh::Point cog;

  for (auto v_it = topologicalMesh->vertices_begin();
       v_it != topologicalMesh->vertices_end(); ++v_it) {
    cog[0] = cog[1] = cog[2] = 0.f;
    TopologicalMesh::Scalar sum = 0.f;

    for (auto vv_it = topologicalMesh->vv_iter(*v_it); vv_it.is_valid();
         ++vv_it) {
      // Note: if we set w = 1.0f then the procedures operates
      // an uniform smoothing, the initial distribution of
      // the triangles will not be preserved
      // TopologicalMesh::Scalar w = 1.f;

      TopologicalMesh::Scalar w =
          topologicalMesh->property(vertex_weights_, *vv_it);

      cog += topologicalMesh->point(*vv_it) * w;
      sum += w;
    }
    assert(sum);
    cogs.emplace_back(cog / sum);
  }

  auto cog_it = cogs.begin();
  for (auto v_it = topologicalMesh->vertices_begin();
       v_it != topologicalMesh->vertices_end(); ++v_it, ++cog_it) {
    topologicalMesh->set_point(*v_it, (*cog_it));
  }
  topologicalMesh->copyPointsPositionToWedges();

  if (isPolyMesh) {
    auto plm = topologicalMesh->toPolyMesh();
    polymesh->getCoreGeometry().setVertices(plm.vertices());
    LOG(logINFO) << "End processing polymesh " << polymesh->getName();
  } else {
    auto plm = topologicalMesh->toTriangleMesh();
    trianglemesh->getCoreGeometry().setVertices(plm.vertices());
    LOG(logINFO) << "End processing trianglemesh" << trianglemesh->getName();
  }
  delete topologicalMesh;
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
void customFonction(int value) {
  std::cout << "Called custom function, got value: " << value << std::endl;
}

} // namespace RadiumMeshProcessing
