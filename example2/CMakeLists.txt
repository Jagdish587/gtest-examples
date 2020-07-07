cmake_minimum_required(VERSION 3.2)

project(gtest-examples)

set(PROJ_ROOT_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(test-utils/googletest)
add_subdirectory(src)
add_subdirectory(test)