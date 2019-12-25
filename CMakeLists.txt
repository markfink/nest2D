cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_VERBOSE_MAKEFILE ON)

project(nest2d)

# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )

    message(STATUS "This project requires the Boost library, and will not be compiled.")

    return()

endif()

add_subdirectory(lib/pybind11)
add_subdirectory(lib/libnest2d)

pybind11_add_module(nest2d src/main.cpp)
target_link_libraries(nest2d PUBLIC libnest2d)
