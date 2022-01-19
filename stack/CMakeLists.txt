cmake_minimum_required(VERSION 3.17)
project(stack)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

aux_source_directory(src SRC_LIST)

add_executable(stack main.cpp ${SRC_LIST})