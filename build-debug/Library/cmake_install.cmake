# Install script for directory: /home/mafo/dev/ProjetTIR/Quad-Remeshing/Library

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQuadRemeshing.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQuadRemeshing.so")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQuadRemeshing.so"
           RPATH "$ORIGIN:$ORIGIN/../lib:/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/stage/Radium-external/install/Debug/lib")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Library/libQuadRemeshing.so")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQuadRemeshing.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQuadRemeshing.so")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQuadRemeshing.so"
           OLD_RPATH "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/libs/quadwild/quadwild:/home/mafo/dev/stage/Radium-external/install/Debug/lib:"
           NEW_RPATH "$ORIGIN:$ORIGIN/../lib:/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/stage/Radium-external/install/Debug/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQuadRemeshing.so")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets.cmake"
         "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Library/CMakeFiles/Export/_home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake" TYPE FILE FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Library/CMakeFiles/Export/_home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets-debug.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake" TYPE FILE FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Library/CMakeFiles/Export/_home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake/QuadRemeshingConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/installed-GNU/lib/cmake" TYPE FILE FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Library/QuadRemeshingConfig.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QuadRemeshing" TYPE FILE FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/Library/QuadRemeshing.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QuadRemeshing" TYPE FILE FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/Library/quadwildFuncs.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Resources//QuadRemeshingResources" TYPE FILE FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/Library/QuadRemeshingResources/welcome.txt")
endif()

