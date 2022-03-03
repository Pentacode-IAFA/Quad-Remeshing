//
// Created by bordes on 03/02/2022.
//
#pragma once

#include <Core/CoreMacros.hpp>
#include <Core/Geometry/IndexedGeometry.hpp>

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

  QuadRemeshing_API void setMesh(Ra::Core::Geometry::TriangleMesh *mesh);

  QuadRemeshing_API void setp1();
  QuadRemeshing_API void setp2();
  QuadRemeshing_API void setp3();
  QuadRemeshing_API void setp4();
  QuadRemeshing_API void setp5();

private:
  Ra::Core::Geometry::TriangleMesh *m_mesh;
};

QuadRemeshing_API Ra::Core::Geometry::PolyMesh *
remesh(Ra::Core::Geometry::TriangleMesh *mesh);

QuadRemeshing_API bool initializeQuadRemeshing();
QuadRemeshing_API bool finalizeQuadRemeshing();
} // namespace QuadRemeshing
