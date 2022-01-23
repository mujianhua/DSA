cmake_minimum_required(VERSION 3.17)
project(AVL)

set(CMAKE_CXX_STANDARD 14)
include_directories(../BinarySearchTree/include)
include_directories(../binTree_temp/include)
include_directories(../../_share)
include_directories(include)

add_executable(AVL main.cpp)