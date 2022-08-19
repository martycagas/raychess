# Define the minimum required version of CMake
# I'm starting a new project with the newest version of CMake
cmake_minimum_required(VERSION 3.11...3.24)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file).
                         Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles."
    )
endif()

# Project name and a few useful settings. Other commands can pick up the results
project(
    "RayChess"
    VERSION 0.1
    DESCRIPTION "A chess game written in C++ using the raylib library"
    LANGUAGES CXX
)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    #set(CMAKE_CXX_STANDARD 14)
    #set(CMAKE_CXX_STANDARD_REQUIRED ON)

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # I want the default build type to be Debug as it will be the most frequently used one
    # The Release build type can be always specified on demand on... well, release
    set(default_build_type "Debug")

    if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        message(STATUS "Setting build type to '${default_build_type}' as none was specified.")

        set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)

        # Set the possible values of build type for cmake-gui
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
    endif()
endif()

# Include the Vcpkg toolchain file if installed via vcpkg
#include(C:/PATH/TO/vcpkg/scripts/buildsystems/vcpkg.cmake)
include(FeatureSummary)

# Find the raylib library
find_package(raylib CONFIG REQUIRED)

# The compiled library code is here
add_subdirectory(src)
