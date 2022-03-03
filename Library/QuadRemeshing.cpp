//
// Created by bordes on 03/02/2022.
//

#include "QuadRemeshing.hpp"

namespace QuadRemeshing {

QuadRemeshing_API QuadRemesher::QuadRemesher() : m_mesh{nullptr} {}

QuadRemeshing_API void
QuadRemesher::setMesh(Ra::Core::Geometry::TriangleMesh *mesh) {
  m_mesh = mesh;
}

QuadRemeshing_API void QuadRemesher::setp1() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step1";
}
QuadRemeshing_API void QuadRemesher::setp2() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step2";
}
QuadRemeshing_API void QuadRemesher::setp3() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step3";
}
QuadRemeshing_API void QuadRemesher::setp4() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step4";
}
QuadRemeshing_API void QuadRemesher::setp5() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step5";
}

QuadRemeshing_API Ra::Core::Geometry::PolyMesh *
remesh(Ra::Core::Geometry::TriangleMesh *mesh) {
  return nullptr;
}

} // namespace QuadRemeshing
