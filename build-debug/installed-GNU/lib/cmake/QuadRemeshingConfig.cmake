#------------------------------------------------------------------------------------------------------------
include(CMakeFindDependencyMacro)
if ( NOT Radium_FOUND)
    find_dependency(Radium COMPONENTS Core Engine REQUIRED)
endif()
include("${CMAKE_CURRENT_LIST_DIR}/QuadRemeshingTargets.cmake" )
radium_exported_resources(
        TARGET QuadRemeshing::QuadRemeshing
        ACCESS_FROM_PACKAGE "../.."
        PREFIX MeshProcessingResources
)
