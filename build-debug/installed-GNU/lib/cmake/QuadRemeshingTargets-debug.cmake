#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QuadRemeshing::QuadRemeshing" for configuration "Debug"
set_property(TARGET QuadRemeshing::QuadRemeshing APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(QuadRemeshing::QuadRemeshing PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libQuadRemeshing.so"
  IMPORTED_SONAME_DEBUG "libQuadRemeshing.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS QuadRemeshing::QuadRemeshing )
list(APPEND _IMPORT_CHECK_FILES_FOR_QuadRemeshing::QuadRemeshing "${_IMPORT_PREFIX}/lib/libQuadRemeshing.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
