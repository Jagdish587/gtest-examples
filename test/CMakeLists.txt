cmake_minimum_required(VERSION 3.2)
project(telephony-ut)
set(TARGET_NAME ${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fprofile-arcs -ftest-coverage -std=c++11 -fPIC")


set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(INC_DIR ${PROJ_ROOT_DIR}/includes )

# GTEST and GMOCK Directtories Path
set(GTEST_GMOCK_INC ${PROJ_ROOT_DIR}/test-utils/gtest-gmock/include)

include_directories(
  ${INC_DIR}
  ${GTEST_GMOCK_INC}
)

# GTEST and GMOCK Libs Path
link_directories(${PROJ_ROOT_DIR}/test-utils/gtest-gmock/lib)

SET(SRC
  ${PROJ_ROOT_DIR}/src/Calculator.cpp
)

set(SOURCES main.cpp  test_calculator.cpp gmockExample.cpp gmockTurtleExample.cpp ${SRC})

add_executable(${TARGET_NAME} 
    ${SOURCES} 
)

target_link_libraries(${TARGET_NAME} gtest gtest_main gmock gmock_main pthread)

add_test( runUnitTestCases ${TARGET_NAME} )

add_custom_target(coverage
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND lcov -c -d . -o main_coverage.info --no-external
    COMMAND lcov --remove main_coverage.info '${CMAKE_SOURCE_DIR}/test-utils/*' '${CMAKE_SOURCE_DIR}/test/*' -o main_coverage.info
    COMMAND genhtml -o res main_coverage.info
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/coverage
    COMMAND mkdir -p ${CMAKE_BINARY_DIR}/coverage
    COMMAND mv main_coverage.info ${CMAKE_BINARY_DIR}/coverage
    COMMAND mv res ${CMAKE_BINARY_DIR}/coverage
    
    )

add_custom_target(launch-coverage-report
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND firefox ${CMAKE_BINARY_DIR}/coverage/res/index.html
)

    
    
   

  
