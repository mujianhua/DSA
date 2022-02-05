cmake_minimum_required(VERSION 3.17)
project(_LeetCode)

set(CMAKE_CXX_STANDARD 14)
include_directories(leetcode/editor/cn/leetcode_include.h)
add_executable(_LeetCode main.cpp)
add_executable(P797AllPathsFromSourceToTarget leetcode/editor/cn/Graph/P797AllPathsFromSourceToTarget.cpp)
add_executable(P455AssignCookies leetcode/editor/cn/Greedy/P455AssignCookies.cpp)
add_executable(P383RansomNote leetcode/editor/cn/Hash/P383RansomNote.cpp)