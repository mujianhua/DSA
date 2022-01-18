cmake_minimum_required(VERSION 3.17)
project(queue)

set(CMAKE_CXX_STANDARD 11)

add_executable(queue main.cpp include/queue.h include/arrayQueue.h)