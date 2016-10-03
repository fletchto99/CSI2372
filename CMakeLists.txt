# General stuffs
cmake_minimum_required(VERSION 3.6)
project(CSI2372)

#Compiler flags (C++ 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Lectures
add_executable(lecture1 "Lectures/Lecture 1/main.cpp")
add_executable(lecture4 "Lectures/Lecture 4/union.cpp")


# Labs
add_executable(lab1 "Labs/Lab 1/main.cpp"
                    "Labs/Lab 1/verbose_binary.cpp" "Labs/Lab 1/verbose_binary.h")

# Labs
add_executable(lab2 "Labs/Lab 2/main.cpp"
        "Labs/Lab 2/number_array.cpp" "Labs/Lab 2/number_array.h")