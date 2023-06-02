cmake_minimum_required(VERSION 3.0)

project(SmartMatrix)
set(SMART_MATRIX_SRC main.cpp ForwardList.cpp SmartMatrix.cpp)
set(SMART_MATRIX_HDR ForwardList.h SmartMatrix.h)
add_executable(${PROJECT_NAME} ${SMART_MATRIX_SRC} ${SMART_MATRIX_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data.dat
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
