cmake_minimum_required(VERSION 3.17)
project(dictionary)

set(CMAKE_CXX_STANDARD 11)

add_executable(dictionary main.cpp include/hashTable.h include/hash.h)