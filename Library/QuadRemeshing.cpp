//
// Created by bordes on 03/02/2022.
//

#include "QuadRemeshing.hpp"

namespace QuadRemeshing {

QuadRemeshing_API QuadRemesher::QuadRemesher() : m_mesh{nullptr} {}

QuadRemeshing_API void QuadRemesher::setMesh(Ra::Engine::Data::Mesh *mesh) {
  m_mesh = mesh;
}

QuadRemeshing_API void QuadRemesher::step1() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step1";
}
QuadRemeshing_API void QuadRemesher::step2() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step2";
}
QuadRemeshing_API void QuadRemesher::step3() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step3";
}
QuadRemeshing_API void QuadRemesher::step4() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step4";
}
QuadRemeshing_API void QuadRemesher::step5() {
  LOG(Ra::Core::Utils::logINFO) << "Remesher: step5";
}

QuadRemeshing_API Ra::Core::Geometry::PolyMesh *
remesh(Ra::Engine::Data::Mesh *mesh) {
  return nullptr;
}

} // namespace QuadRemeshing
