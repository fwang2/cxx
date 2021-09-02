cmake_minimum_required(VERSION 2.8)
project(trial-cxx)


if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR}  )
        file(REMOVE test.txt)
        message( FATAL_ERROR "In-source builds not allowed. Please make a new
        directory (called a build directory) and run CMake from there. You may
        need to remove CMakeCache.txt."  )
endif()


# set c99 
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -std=c99")
set(CMAKE_C_FLAGS_DEBUG  "${CMAKE_C_FLAGS_DEBUG} -Wall -std=c99")

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

find_package( PkgConfig )
find_package( Threads )
find_package( Boost )
find_package( BZip2 )



##########
## OpenSSL
#
# This needs a bit work on MacOS (El-Capitan)
#       cd /usr/local/include
#       ln -s ../opt/openssl/include/openssl .
# 
##########

find_package( OpenSSL )


if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    # use boost "format"
    add_executable(format format.cc)
    target_link_libraries(format ${Boost_LIBRARIES})
else()
    message(WARNING "Skip Boost programs")
endif()

if(BZIP2_FOUND)
    include_directories(${BZIP2_INCLUDE_DIRS})
    add_executable(bzip bzip.c)
    target_link_libraries(bzip ${BZIP2_LIBRARIES})
endif()    


#####
##  C 
#####
add_executable(show_bytes show_bytes.c)
add_executable(switch switch.c)
add_executable(sizeof_struct sizeof_struct.c)
add_executable(malloc_max malloc_max.c)


#####
## Linux specific 
#####

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_executable(xattr xattr.c)
endif()

#####
## C++
#####

if (OPENSSL_FOUND)
    # demo: sha2
    message(STATUS "openssl include dirs:  ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "openssl libraries:  ${OPENSSL_LIBRARIES}")
    include_directories(OPENSSL_INCLUDE_DIR)

    add_executable(sha1 sha1.cc)
    target_link_libraries(sha1 ${OPENSSL_LIBRARIES})
endif()


# demo: random generator
add_executable(random_gen random_gen.cc)


# demo: time 2 string
add_executable(time2str time2str.cc)

# demo: system limits
add_executable(limits limits.cc)

# demo how to use "auto" keyword 
add_executable(auto auto.cpp )

# demo: initializer list
add_executable(initializer_list initializer_list.cpp)
add_executable(init_var init_var.cc)


# demo: class static const, can be initialized at def time 
add_executable(class_static class_static.cpp)

# demonstrate how to use
# assert in different mode (release will strip it)
add_executable(assert assert.cc)

# demo: create a vector, with initial value set
add_executable(vect_init vect_init.cc)


# demo: C11 features
add_executable(cxx11_sharedptr cxx11_sharedptr.cc)


# demo: I/O
add_executable(io_file1 io_file1.cc)
add_executable(io_string io_string.cc)

# demo: loop

add_executable(loop_foreach loop_foreach.cc)
add_executable(loop_forrange loop_forrange.cc)
add_executable(loop_iter1 loop_iter1.cc)

# demo: std containers
add_executable(std_array1 std_array1.cc)
add_executable(std_mem std_mem.cc)
add_executable(std_set std_set.cc)

# demo: rvalue.cc 
add_executable(rvalue rvalue.cc)

# demo: smart pointer
add_executable(smart_ptr1 smart_ptr1.cc)
