# Install script for directory: /home/mafo/dev/ProjetTIR/Quad-Remeshing/Plugin

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
  if(EXISTS "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so"
         RPATH "@loader_path:$ORIGIN:$ORIGIN/../lib:/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/stage/Radium-external/install/Debug/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib" TYPE SHARED_LIBRARY FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Plugin/Plugins/lib/libQuadRemeshingPlugin.so")
  if(EXISTS "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so"
         OLD_RPATH "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Library:/home/mafo/dev/stage/Radium-external/install/Debug/lib:/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/libs/quadwild/quadwild:"
         NEW_RPATH "@loader_path:$ORIGIN:$ORIGIN/../lib:/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/stage/Radium-external/install/Debug/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshingPlugin.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/Resources/QuadRemeshingResources/welcome.txt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/Resources/QuadRemeshingResources" TYPE FILE FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/Library/QuadRemeshingResources/welcome.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so"
         RPATH "$ORIGIN:$ORIGIN/../lib:/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/stage/Radium-external/install/Debug/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib" TYPE SHARED_LIBRARY FILES "/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/Library/libQuadRemeshing.so")
  if(EXISTS "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so"
         OLD_RPATH "/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/ProjetTIR/Quad-Remeshing/build-debug/libs/quadwild/quadwild:/home/mafo/dev/stage/Radium-external/install/Debug/lib:"
         NEW_RPATH "$ORIGIN:$ORIGIN/../lib:/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/lib:/home/mafo/dev/stage/Radium-external/install/Debug/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/mafo/dev/stage/Radium-Engine/Bundle-GNU-Debug/Plugins/lib/libQuadRemeshing.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

