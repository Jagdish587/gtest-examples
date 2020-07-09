cmake_minimum_required(VERSION 3.2)
project(telephony-ut)
set(TARGET_NAME ${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -fPIC")


set(INC_DIR ${PROJ_ROOT_DIR}/includes )

include_directories(
  ${INC_DIR}
)

SET(SRC
  ${PROJ_ROOT_DIR}/src/Calculator.cpp
)

set(SOURCES main.cpp  test_calculator.cpp gmockExample.cpp ${SRC})

add_executable(${TARGET_NAME} 
    ${SOURCES} 
)

target_link_libraries(${TARGET_NAME} gtest gtest_main gmock gmock_main pthread)

add_test( runUnitTestCases ${TARGET_NAME} )
