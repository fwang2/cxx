cmake_minimum_required(VERSION 2.8)
project(trial-aio)


if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR}  )
        file(REMOVE test.txt)
        message( FATAL_ERROR "In-source builds not allowed. Please make a new
        directory (called a build directory) and run CMake from there. You may
        need to remove CMakeCache.txt."  )
endif()


# set c99 
# set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -std=c99")
# set(CMAKE_C_FLAGS_DEBUG  "${CMAKE_C_FLAGS_DEBUG} -Wall -std=c99")

# set c++11 support
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_CFLAGS} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# Compiler-specific C++11 activation.
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    if (NOT (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7))
        message(FATAL_ERROR "${PROJECT_NAME} requires g++ 4.7 or greater.")
    endif ()
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else ()
    message(FATAL_ERROR "Your C++ compiler does not support C++11.")
endif ()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeScripts)

#####
## Linux specific 
#####

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_executable(aio1 aio1.cc)
    add_executable(aio2 aio2.cc)
    add_executable(aio-stress aio-stress.c)
    target_link_libraries(aio-stress aio pthread)

    add_executable(fair-lio fair-lio.c)
    target_link_libraries(fair-lio aio)

    # demo: POSIX AIO
    # no need to link libaio, just need librt for posix aio

    add_executable(paio1 paio1.c)
    target_link_libraries(paio1 rt)
else ()
    message(FATAL_ERROR "Can't do native AIO on this platform")
endif()

