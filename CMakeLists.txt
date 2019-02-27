cmake_minimum_required(VERSION 3.10.2)
project(trial-cxx)

# include
LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")


if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR}  )
        file(REMOVE test.txt)
        message( FATAL_ERROR "In-source builds not allowed. Please make a new
        directory (called a build directory) and run CMake from there. You may
        need to remove CMakeCache.txt."  )
endif()

# activate C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# assume GNU file layout
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_subdirectory(externals/fmt-5.3.0 EXCLUDE_FROM_ALL)
add_subdirectory(Utility)
