cmake_minimum_required(VERSION 3.17)
project(arrayList)

set(CMAKE_CXX_STANDARD 14)

include_directories("./include")
aux_source_directory(src SRC_LIST)
add_executable(arrayList main.cpp)