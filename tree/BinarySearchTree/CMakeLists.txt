cmake_minimum_required(VERSION 3.17)
project(BinarySearchTree)

set(CMAKE_CXX_STANDARD 14)

include_directories(../binTree_temp/include)
include_directories(include)
add_executable(BinarySearchTree main.cpp)