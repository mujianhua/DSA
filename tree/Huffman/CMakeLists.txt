cmake_minimum_required(VERSION 3.17)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

include_directories(../binTree_temp/include)

add_executable(Huffman main.cpp)