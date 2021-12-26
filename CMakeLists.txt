cmake_minimum_required(VERSION 3.1)

project(BinaryTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

file(GLOB CPP_SOURCE "source/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/headers")

add_executable(${PROJECT_NAME} ${CPP_SOURCE})