# 
# cmake -DCMAKE_BUILD_TYPE=Debug ..
#
cmake_minimum_required(VERSION 2.8)
project(thread)


if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR}  )
        file(REMOVE test.txt)
        message( FATAL_ERROR "In-source builds not allowed. Please make a new
        directory (called a build directory) and run CMake from there. You may
        need to remove CMakeCache.txt."  )
endif()


# set c99 
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -std=c99")
set(CMAKE_C_FLAGS_DEBUG  "${CMAKE_C_FLAGS_DEBUG} -Wall -g -std=c99")

# set c++11 support
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_CFLAGS} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

find_package( Threads )
link_libraries(${CMAKE_THREAD_LIBS_INIT})
add_definitions(-DDEBUG)


add_executable(thread_error thread_error.c)
add_executable(alarm_mutex alarm_mutex.c)
add_executable(trylock trylock.c)
