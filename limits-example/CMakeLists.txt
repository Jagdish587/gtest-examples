cmake_minimum_required(VERSION 3.2)

project(gtest-examples)

set(PROJ_ROOT_DIR ${CMAKE_SOURCE_DIR})

set(test 1)

if(NOT test )
message("running your source folder ")
add_subdirectory(src)
endif()

# Turn on with cmake -Dtest=ON ..
if(test)

message("PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})
message("PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})

message("running unit test cases ")

enable_testing()
add_subdirectory(test)

endif()
