cmake_minimum_required(VERSION 3.6)
project(CSI2372)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "Lectures/Lecture 1/main.cpp")
add_executable(CSI2372 ${SOURCE_FILES})