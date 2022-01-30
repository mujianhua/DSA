cmake_minimum_required(VERSION 3.17)
project(_LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(_LeetCode main.cpp)
add_executable(P797AllPathsFromSourceToTarget leetcode/editor/cn/Graph/P797AllPathsFromSourceToTarget.cpp)
add_executable(P455AssignCookies leetcode/editor/Greedy/P455AssignCookies.cpp)