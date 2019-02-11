# Build for ufs
#
# fwang2@ornl.gov

cmake_minimum_required(VERSION 2.8)
project(ufs)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmk)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR}  )
        file(REMOVE test.txt)
        message( FATAL_ERROR "In-source builds not allowed. Please make a new
        directory (called a build directory) and run CMake from there. You may
        need to remove CMakeCache.txt."  )
endif()

# pkg-config 
find_package(PkgConfig)


# set c++11 support
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_CFLAGS} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# Boost, RHEL7 vanilla 
find_package(Boost 1.53 
    COMPONENTS program_options log date_time thread system REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
link_libraries(${Boost_LIBRARIES})


add_executable(cast cast.cc)

