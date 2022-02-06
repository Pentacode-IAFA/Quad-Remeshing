#pragma once

#include <Core/CoreMacros.hpp>

/// Defines the correct macro to export dll symbols.
#if defined RadiumMeshProcessing_EXPORTS
#    define RadiumMeshProcessing_API DLL_EXPORT
#else
#    define RadiumMeshProcessing_API DLL_IMPORT
#endif

#include <string>

namespace RadiumMeshProcessing {

struct ProcessingParameter {
    std::string entityName;
    std::string componentName;
};


RadiumMeshProcessing_API bool initializeRadiumMeshProcessing();
RadiumMeshProcessing_API bool finalizeRadiumMeshProcessing();

RadiumMeshProcessing_API void RadiumMeshProcessingWelcome( const std::string& message );

RadiumMeshProcessing_API void LaplacianSmoothing( ProcessingParameter p );

} // namespace RadiumMeshProcessing
