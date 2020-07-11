cmake_minimum_required(VERSION 3.2)
project(telephony)
set(TARGET_NAME ${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -fPIC")


set(INC_DIR ${PROJ_ROOT_DIR}/includes )

include_directories(
  ${INC_DIR}
)


set(SOURCES 
    main.cpp 
    Calculator.cpp 
)

add_executable(${TARGET_NAME} 
    ${SOURCES} 
)