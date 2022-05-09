
#include "QuadRemeshing.hpp"
#include "../libs/quadwild/components/field_computation/AutoRemesher.h"
#include "../libs/quadwild/components/field_computation/mesh_manager.h"
#include "../libs/quadwild/components/field_computation/triangle_mesh_type.h"
#include "../libs/quadwild/components/quad_from_patches/load_save.h"
#include "../libs/quadwild/components/quad_from_patches/mesh_types.h"
#include "../libs/quadwild/components/quad_from_patches/quad_from_patches.h"
#include "../libs/quadwild/components/quad_from_patches/smooth_mesh.h"
#include "../libs/quadwild/libs/libigl/include/igl/writeOBJ.h"
#include "quadwildFuncs.hpp"
#include <Core/Utils/Color.hpp>
#include <Engine/RadiumEngine.hpp>
#include <tracing/mesh_type.h>
#include <tracing/tracer_interface.h>

std::array<Ra::Core::Utils::Color, 10> m_colors{
    Ra::Core::Utils::Color::Green(),  Ra::Core::Utils::Color::Blue(),
    Ra::Core::Utils::Color::Yellow(), Ra::Core::Utils::Color::Magenta(),
    Ra::Core::Utils::Color::Cyan(),   Ra::Core::Utils::Color::White(),
    Ra::Core::Utils::Color::Grey(),   Ra::Core::Utils::Color::Black(),
    Ra::Core::Utils::Color::Skin(),   Ra::Core::Utils::Color::Red()};

typename TriangleMesh::ScalarType avgEdge(const TriangleMesh &trimesh) {
  typedef typename TriangleMesh::ScalarType ScalarType;

  ScalarType avg = 0;
  size_t num = 0;

  for (size_t i = 0; i < trimesh.face.size(); i++) {
    for (int j = 0; j < trimesh.face[i].VN(); j++) {
      avg += (trimesh.face[i].cP0(j) - trimesh.face[i].cP1(j)).Norm();
      num++;
    }
  }

  return avg / num;
}

bool loadConfigFile(const std::string &filename, Parameters &parameters) {
  FILE *f = fopen(filename.c_str(), "rt");

  if (f == NULL)
    return false;

  std::cout << "READ CONFIG FILE" << std::endl;

  int IntVar;
  fscanf(f, "do_remesh %d\n", &IntVar);
  if (IntVar == 0)
    parameters.remesh = false;
  else
    parameters.remesh = true;

  fscanf(f, "sharp_feature_thr %f\n", &parameters.sharpAngle);

  fscanf(f, "alpha %f\n", &parameters.alpha);

  fscanf(f, "scaleFact %f\n", &parameters.scaleFact);

  fclose(f);

  std::cout << "Successful config import" << std::endl;

  return true;
}

void remeshAndField(FieldTriMesh &trimesh, const Parameters &parameters,
                    const std::string &meshFilename,
                    const std::string &sharpFilename,
                    const std::string &fieldFilename) {
  typename MeshPrepocess<FieldTriMesh>::BatchParam BPar;
  BPar.DoRemesh = parameters.remesh;
  BPar.feature_erode_dilate = 4;
  BPar.remesher_aspect_ratio = 0.3;
  BPar.remesher_iterations = 15;
  BPar.remesher_termination_delta = 10000;
  BPar.SharpFactor = 6;
  BPar.sharp_feature_thr = parameters.sharpAngle;
  BPar.surf_dist_check = true;
  BPar.UpdateSharp = (!parameters.hasFeature);

  typename vcg::tri::FieldSmoother<FieldTriMesh>::SmoothParam FieldParam;
  FieldParam.alpha_curv = 0.3;
  FieldParam.curv_thr = 0.8;

  if (parameters.hasFeature) {
    bool loaded = trimesh.LoadSharpFeatures(sharpFilename);
    if (!loaded) {
      std::cout << "ERROR: Wrong Sharp Feature File" << std::endl;
      exit(0);
    }
    std::cout << "Sharp Feature Length:" << trimesh.SharpLenght() << std::endl;
  }
  if (!parameters.hasField) {
    MeshPrepocess<FieldTriMesh>::BatchProcess(trimesh, BPar, FieldParam);
  } else {
    trimesh.LoadField(fieldFilename.c_str());
  }

  MeshPrepocess<FieldTriMesh>::SaveAllData(trimesh, meshFilename);
}

void trace(const std::string &filename, TraceMesh &traceTrimesh) {
  // Get base filename
  std::string baseFilename = filename;
  baseFilename.erase(baseFilename.find_last_of("."));

  std::string meshFilename = baseFilename;
  meshFilename.append("_rem.obj");
  std::cout << "Loading Remeshed M:" << meshFilename.c_str() << std::endl;

  std::string fieldFilename = baseFilename;
  fieldFilename.append("_rem.rosy");
  std::cout << "Loading Rosy Field:" << fieldFilename.c_str() << std::endl;

  std::string sharpFilename = baseFilename;
  sharpFilename.append("_rem.sharp");
  std::cout << "Loading Sharp F:" << sharpFilename.c_str() << std::endl;

  // Mesh load
  printf("Loading the mesh \n");
  bool loadedMesh = traceTrimesh.LoadMesh(meshFilename);
  assert(loadedMesh);
  traceTrimesh.UpdateAttributes();

  // Field load
  bool loadedField = traceTrimesh.LoadField(fieldFilename);
  assert(loadedField);
  traceTrimesh.UpdateAttributes();

  // Sharp load
  bool loadedFeatures = traceTrimesh.LoadSharpFeatures(sharpFilename);
  assert(loadedFeatures);
  traceTrimesh.SolveGeometricIssues();
  traceTrimesh.UpdateSharpFeaturesFromSelection();

  // preprocessing mesh
  PreProcessMesh(traceTrimesh);

  // initializing graph
  VertexFieldGraph<TraceMesh> VGraph(traceTrimesh);
  VGraph.InitGraph(false);

  // INIT TRACER
  typedef PatchTracer<TraceMesh> TracerType;
  TracerType PTr(VGraph);
  TraceMesh::ScalarType Drift = 100;
  bool add_only_needed = true;
  bool final_removal = true;
  bool meta_mesh_collapse = true;
  bool force_split = false;
  PTr.sample_ratio = 0.01;
  PTr.CClarkability = 1;
  PTr.split_on_removal = true;
  PTr.away_from_singular = true;
  PTr.match_valence = true;
  PTr.check_quality_functor = false;
  PTr.MinVal = 3;
  PTr.MaxVal = 5;
  PTr.Concave_Need = 1;

  // TRACING
  PTr.InitTracer(Drift, false);
  RecursiveProcess<TracerType>(PTr, Drift, add_only_needed, final_removal, true,
                               meta_mesh_collapse, force_split, true, false);
  PTr.SmoothPatches();
  SaveAllData(PTr, baseFilename, 0, false, false);
}

void quadrangulate(const std::string &filename,
                   TriangleMesh &trimeshToQuadrangulate, PolyMesh &quadmesh,
                   std::vector<std::vector<size_t>> &trimeshPartitions,
                   std::vector<std::vector<size_t>> &trimeshCorners,
                   std::vector<std::pair<size_t, size_t>> &trimeshFeatures,
                   std::vector<size_t> &trimeshFeaturesC,
                   std::vector<std::vector<size_t>> quadmeshPartitions,
                   std::vector<std::vector<size_t>> quadmeshCorners,
                   std::vector<int> ilpResult, const Parameters &parameters) {
  // Get base filename
  std::string baseFilename = filename;
  baseFilename.erase(baseFilename.find_last_of("."));

  std::string meshFilename = baseFilename;
  meshFilename.append("_p0.obj");

  int mask;
  vcg::tri::io::ImporterOBJ<TriangleMesh>::LoadMask(meshFilename.c_str(), mask);
  int err = vcg::tri::io::ImporterOBJ<TriangleMesh>::Open(
      trimeshToQuadrangulate, meshFilename.c_str(), mask);
  if ((err != 0) && (err != 5))
    assert(0);

  // FACE PARTITIONS
  std::string partitionFilename = baseFilename;
  partitionFilename.append("_p0.patch");
  trimeshPartitions = loadPatches(partitionFilename);
  std::cout << "Loaded " << trimeshPartitions.size() << " patches" << std::endl;

  // PATCH CORNERS
  std::string cornerFilename = baseFilename;
  cornerFilename.append("_p0.corners");
  trimeshCorners = loadCorners(cornerFilename);
  std::cout << "Loaded " << trimeshCorners.size() << " corners set"
            << std::endl;

  // FEATURES
  std::string featureFilename = baseFilename;
  featureFilename.append("_p0.feature");
  trimeshFeatures = LoadFeatures(featureFilename);
  std::cout << "Loaded " << trimeshFeatures.size() << " features" << std::endl;

  // FEATURE CORNERS
  std::string featureCFilename = baseFilename;
  featureCFilename.append("_p0.c_feature");
  trimeshFeaturesC = loadFeatureCorners(featureCFilename);
  std::cout << "Loaded " << featureCFilename.size() << " corner features"
            << std::endl;
  loadFeatureCorners(featureCFilename);

  std::cout << "Alpha: " << parameters.alpha << std::endl;

  OrientIfNeeded(trimeshToQuadrangulate, trimeshPartitions, trimeshCorners,
                 trimeshFeatures, trimeshFeaturesC);

  // COMPUTE QUADRANGULATION
  QuadRetopology::internal::updateAllMeshAttributes(trimeshToQuadrangulate);

  QuadRetopology::Parameters qParameters;
  float scaleFactor;
  int fixedChartClusters;

  qParameters.alpha = parameters.alpha;
  qParameters.ilpMethod = QuadRetopology::ILPMethod::LEASTSQUARES;
  qParameters.timeLimit = 200;
  qParameters.gapLimit = 0.0;
  qParameters.callbackTimeLimit.push_back(3.0);
  qParameters.callbackTimeLimit.push_back(5.0);
  qParameters.callbackTimeLimit.push_back(10.0);
  qParameters.callbackTimeLimit.push_back(20.0);
  qParameters.callbackTimeLimit.push_back(30.0);
  qParameters.callbackTimeLimit.push_back(60.0);
  qParameters.callbackTimeLimit.push_back(90.0);
  qParameters.callbackTimeLimit.push_back(120.0);

  qParameters.callbackGapLimit.push_back(0.005);
  qParameters.callbackGapLimit.push_back(0.02);
  qParameters.callbackGapLimit.push_back(0.05);
  qParameters.callbackGapLimit.push_back(0.1);
  qParameters.callbackGapLimit.push_back(0.15);
  qParameters.callbackGapLimit.push_back(0.20);
  qParameters.callbackGapLimit.push_back(0.25);
  qParameters.callbackGapLimit.push_back(0.3);

  qParameters.minimumGap = 0.4;

  qParameters.isometry = true;

  qParameters.regularityQuadrilaterals = true;

  qParameters.regularityNonQuadrilaterals = true;

  qParameters.regularityNonQuadrilateralsWeight = 0.9;

  qParameters.alignSingularities = true;

  qParameters.alignSingularitiesWeight = 0.1;

  qParameters.repeatLosingConstraintsIterations = true;

  qParameters.repeatLosingConstraintsQuads = false;

  qParameters.repeatLosingConstraintsNonQuads = false;

  qParameters.repeatLosingConstraintsAlign = true;

  qParameters.hardParityConstraint = true;

  scaleFactor = parameters.scaleFact;

  fixedChartClusters = 300;

  qParameters.chartSmoothingIterations = 0; // Chart smoothing
  qParameters.quadrangulationFixedSmoothingIterations =
      0; // Smoothing with fixed borders of the patches
  qParameters.quadrangulationNonFixedSmoothingIterations =
      0; // Smoothing with fixed borders of the quadrangulation
  qParameters.feasibilityFix = false;

  double edgeSize = avgEdge(trimeshToQuadrangulate) * scaleFactor;
  std::cout << "Edge size: " << edgeSize << std::endl;
  const std::vector<double> edgeFactor(trimeshPartitions.size(), edgeSize);

  qfp::quadrangulationFromPatches(
      trimeshToQuadrangulate, trimeshPartitions, trimeshCorners, edgeFactor,
      qParameters, fixedChartClusters, quadmesh, quadmeshPartitions,
      quadmeshCorners, ilpResult);

  // SAVE OUTPUT
  std::string outputFilename = baseFilename;
  outputFilename += std::string("_quadrangulation") + std::string(".obj");
  vcg::tri::io::ExporterOBJ<PolyMesh>::Save(quadmesh, outputFilename.c_str(),
                                            0);

  // SMOOTH
  std::vector<size_t> QuadPart(quadmesh.face.size(), 0);
  for (size_t i = 0; i < quadmeshPartitions.size(); i++)
    for (size_t j = 0; j < quadmeshPartitions[i].size(); j++)
      QuadPart[quadmeshPartitions[i][j]] = i;

  std::vector<size_t> TriPart(trimeshToQuadrangulate.face.size(), 0);
  for (size_t i = 0; i < trimeshPartitions.size(); i++)
    for (size_t j = 0; j < trimeshPartitions[i].size(); j++)
      TriPart[trimeshPartitions[i][j]] = i;

  std::vector<size_t> QuadCornersVect;
  for (size_t i = 0; i < quadmeshCorners.size(); i++)
    for (size_t j = 0; j < quadmeshCorners[i].size(); j++)
      QuadCornersVect.push_back(quadmeshCorners[i][j]);

  std::sort(QuadCornersVect.begin(), QuadCornersVect.end());
  auto last = std::unique(QuadCornersVect.begin(), QuadCornersVect.end());
  QuadCornersVect.erase(last, QuadCornersVect.end());

  std::cout << "** SMOOTHING **" << std::endl;
  MultiCostraintSmooth(quadmesh, trimeshToQuadrangulate, trimeshFeatures,
                       trimeshFeaturesC, TriPart, QuadCornersVect, QuadPart,
                       0.5, edgeSize, 30, 1);

  // SAVE OUTPUT
  std::string smoothOutputFilename = baseFilename;
  smoothOutputFilename +=
      std::string("_quadrangulation_smooth") + std::string(".obj");

  vcg::tri::io::ExporterOBJ<PolyMesh>::Save(quadmesh,
                                            smoothOutputFilename.c_str(), 0);
}

namespace QuadRemeshing {

QuadRemeshing_API QuadRemesher::QuadRemesher() : m_mesh{nullptr} {
  m_meshFilepath =
      "/home/lowin/Documents/assets/300/300/Mechanical/twirl20k.obj";
  m_setupPath = "/home/lowin/Documents/projects/univ/PentaCode/Quad-Remeshing/"
                "libs/quadwild/quadwild/"
                "basic_setup.txt";
}

QuadRemeshing_API void QuadRemesher::setMesh(Ra::Engine::Data::Mesh *mesh) {
  m_mesh = mesh;
}

QuadRemeshing_API void QuadRemesher::step1() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step1";

  // igl::writeOBJ(std::string("buc.obj"),
  // m_mesh->getCoreGeometry().vertices().data()->derived(),
  // m_mesh->getCoreGeometry().getIndices().data()->derived());

  Parameters parameters;

  FieldTriMesh trimesh;

  std::string sharpFilename;
  std::string fieldFilename;

  // Use "." as decimal separator
  std::setlocale(LC_NUMERIC, "en_US.UTF-8");

  LOG(Ra::Core::Utils::logINFO) << "Reading input...";
  loadConfigFile(m_setupPath, parameters);

  int position;

  // std::string pathTest = "/home/mafo/Downloads/300/300/Mechanical/twirl20k";
  // position=m_meshFilepath.find(".sharp");
  // if (position!=-1)
  //{
  //     sharpFilename=m_meshFilepath;
  //     parameters.hasFeature=true;
  // }

  // position=m_meshFilepath.find(".txt");
  // if (position!=-1)
  //{
  //    loadConfigFile(m_meshFilepath.c_str(), parameters);
  // }

  // position=m_meshFilepath.find(".rosy");
  // if (position!=-1)
  //{
  //    fieldFilename=m_meshFilepath;
  //    parameters.hasField=true;
  // }

  LOG(Ra::Core::Utils::logINFO) << "Loading:" << m_meshFilepath.c_str();

  bool allQuad;
  bool loaded = trimesh.LoadTriMesh(m_meshFilepath, allQuad);
  trimesh.UpdateDataStructures();

  if (!loaded) {
    LOG(Ra::Core::Utils::logINFO) << "Wrong mesh filename";
    exit(0);
  }

  LOG(Ra::Core::Utils::logINFO)
      << "Loaded " << trimesh.fn << " faces and " << trimesh.vn << " vertices";

  LOG(Ra::Core::Utils::logINFO)
      << "--------------------- 1 - Remesh and field ---------------------";
  remeshAndField(trimesh, parameters, m_meshFilepath, sharpFilename,
                 fieldFilename);

  // std::string remeshFileName = m_meshFilepath;
  // remeshFileName.erase(remeshFileName.end() - 4, remeshFileName.end());

  // remeshFileName += "_rem.obj";

  // auto engine = Ra::Engine::RadiumEngine::getInstance();
  // engine->loadFile(remeshFileName);
}

QuadRemeshing_API void QuadRemesher::step2() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step2";
  LOG(Ra::Core::Utils::logINFO)
      << "--------------------- 2 - Tracing ---------------------";
  TraceMesh traceTrimesh;
  trace(m_meshFilepath, traceTrimesh);
}

QuadRemeshing_API void QuadRemesher::step3() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step3";
  m_mesh->getAttribArrayGeometry().addAttrib(
      "in_color", Ra::Core::Vector4Array{m_mesh->getNumVertices(),
                                         Ra::Core::Utils::Color::White()});

  auto &attrib = m_mesh->getAttribArrayGeometry().getAttrib(
      m_mesh->getAttribArrayGeometry().getAttribHandle<Ra::Core::Vector4>(
          "in_color"));

  auto &cont = attrib.getDataWithLock();

  // std::cout << m_mesh.vertices().size() << std::endl;

  int i = 0;
  std::string filename = m_meshFilepath;
  filename.erase(filename.end() - 4, filename.end());
  filename += "_p0.patch";

  std::ifstream stream(filename);
  if (stream.is_open()) {
    std::cout << "Fichier ouvert" << std::endl;
  } else {
    std::cout << "Echec ouverture fichier" << std::endl;
  }
  std::string line;
  std::getline(stream, line);
  // std::cout << cont.size() << std::endl;
  while (std::getline(stream, line)) {
    for (int j = 0; j < 3; j++) {
      cont[i + j] = m_colors[std::atoi(line.c_str()) % m_colors.size()];
    }
    i += 3;
    // printf("%d - %s\n",i , line.c_str());
  }

  attrib.unlock();
}

QuadRemeshing_API void QuadRemesher::step4() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step4";
  std::cout << std::endl
            << "--------------------- 3 - Quadrangulation ---------------------"
            << std::endl;
  TriangleMesh trimeshToQuadrangulate;
  std::vector<std::vector<size_t>> trimeshPartitions;
  std::vector<std::vector<size_t>> trimeshCorners;
  std::vector<std::pair<size_t, size_t>> trimeshFeatures;
  std::vector<size_t> trimeshFeaturesC;

  PolyMesh quadmesh;
  std::vector<std::vector<size_t>> quadmeshPartitions;
  std::vector<std::vector<size_t>> quadmeshCorners;
  std::vector<int> ilpResult;
  quadrangulate(m_meshFilepath, trimeshToQuadrangulate, quadmesh,
                trimeshPartitions, trimeshCorners, trimeshFeatures,
                trimeshFeaturesC, quadmeshPartitions, quadmeshCorners,
                ilpResult, parameters);
}

QuadRemeshing_API void QuadRemesher::step5() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step5";
}

QuadRemeshing_API Ra::Core::Geometry::PolyMesh *
remesh(Ra::Engine::Data::Mesh *mesh) {
  return nullptr;
}

} // namespace QuadRemeshing
