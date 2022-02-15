cmake_minimum_required(VERSION 3.0.0)
project(my-test-project VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE "Debug")


include(CTest)
enable_testing()
include_directories(tree)
include_directories(chain)


add_executable(my-test-project main.cpp)
add_executable(haha test.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
