cmake_minimum_required(VERSION 3.17)
project(stack)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(stack main.cpp include/linkedStack.h)