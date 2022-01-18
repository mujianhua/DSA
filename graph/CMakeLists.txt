cmake_minimum_required(VERSION 3.17)
project(graph)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(graph main.cpp include/weightedGraph.h include/unweightedEdge.h)