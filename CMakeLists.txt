cmake_minimum_required(VERSION 3.0)

project(SmartMatrix)
set(SMART_MATRIX_SRC main.cpp ForwardList.cpp)
set(SMART_MATRIX_HDR ForwardList.h)
add_executable(${PROJECT_NAME} ${SMART_MATRIX_SRC} ${SMART_MATRIX_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
