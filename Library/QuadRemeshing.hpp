//
// Created by bordes on 03/02/2022.
//
#pragma once

#include <Core/CoreMacros.hpp>
#include <Core/Geometry/IndexedGeometry.hpp>
#include <Engine/Data/DisplayableObject.hpp>
#include <Engine/Data/Mesh.hpp>

/// Defines the correct macro to export dll symbols.
#if defined QuadRemeshing_EXPORTS
#define QuadRemeshing_API DLL_EXPORT
#else
#define QuadRemeshing_API DLL_IMPORT
#endif

#include <string>

namespace QuadRemeshing {

struct QuadRemeshingParameter {
  std::string entityName;
  std::string componentName;
};

class QuadRemeshing_API QuadRemesher {
public:
  QuadRemeshing_API QuadRemesher();
  QuadRemeshing_API ~QuadRemesher();

  QuadRemeshing_API void setMesh(Ra::Engine::Data::Mesh *mesh);

  QuadRemeshing_API void step1();
  QuadRemeshing_API void step2();
  QuadRemeshing_API void step3();
  QuadRemeshing_API void step4();
  QuadRemeshing_API void step5();

private:
  Ra::Engine::Data::Mesh *m_mesh;
};

QuadRemeshing_API Ra::Core::Geometry::PolyMesh *
remesh(Ra::Core::Geometry::TriangleMesh *mesh);

QuadRemeshing_API bool initializeQuadRemeshing();
QuadRemeshing_API bool finalizeQuadRemeshing();
} // namespace QuadRemeshing
