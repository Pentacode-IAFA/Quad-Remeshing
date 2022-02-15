//
// Created by bordes on 03/02/2022.
//
#pragma once

#include <Core/CoreMacros.hpp>

/// Defines the correct macro to export dll symbols.
#if defined QuadRemeshing_EXPORTS
#    define QuadRemeshing_API DLL_EXPORT
#else
#    define QuadRemeshing_API DLL_IMPORT
#endif

#include <string>

namespace QuadRemeshing {

    struct QuadRemeshingParameter {
        std::string entityName;
        std::string componentName;
    };

    QuadRemeshing_API bool initializeQuadRemeshing();
    QuadRemeshing_API bool finalizeQuadRemeshing();
} // namespace RadiumMeshProcessing
