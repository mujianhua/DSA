cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)


include(CTest)
enable_testing()
include_directories(tree)
include_directories(chain)
include_directories(DynamicProgramming)


add_executable(dp DynamicProgramming/test_2_wei_bag_problem1.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
