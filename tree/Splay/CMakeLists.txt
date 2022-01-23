cmake_minimum_required(VERSION 3.17)
project(Splay)

set(CMAKE_CXX_STANDARD 14)
include_directories(../BinarySearchTree/include)
include_directories(include)
include_directories(../binTree_temp/include)
include_directories(../../_share)
add_executable(Splay main.cpp)