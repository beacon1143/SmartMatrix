cmake_minimum_required(VERSION 3.0)

project(SmartMatrix)
add_executable(${PROJECT_NAME} "main.cpp" "ForwardList.cpp" "ForwardList.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
