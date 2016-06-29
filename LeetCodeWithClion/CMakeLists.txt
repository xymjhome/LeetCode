cmake_minimum_required(VERSION 3.5)
project(LeetCodeWithClion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 42.Trapping Rain Water.cpp)

add_executable(LeetCodeWithClion ${SOURCE_FILES})