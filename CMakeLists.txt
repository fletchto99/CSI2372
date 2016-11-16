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
                    "Labs/Lab 1/verbose_binary.cpp" "Labs/Lab 1/verbose_binary.h" Project/main.cpp Project/TradeArea.cpp Project/TradeArea.h Project/Hand.cpp Project/Hand.h)
add_executable(lab2 "Labs/Lab 2/main.cpp"
        "Labs/Lab 2/number_array.cpp" "Labs/Lab 2/number_array.h")
add_executable(lab3 "Labs/Lab 3/main.cpp" "Labs/Lab 3/bikerides.h" "Labs/Lab 3/bikerides.cpp")
add_executable(lab4 "Labs/Lab 4/main.cpp" "Labs/Lab 4/fruit_grower.cpp" "Labs/Lab 4/fruit_grower.h")
add_executable(lab5 "Labs/Lab 5/text_entry.cpp" "Labs/Lab 5/main.cpp" "Labs/Lab 5/questionaire.h" "Labs/Lab 5/text_entry.h" "Labs/Lab 5/questionaire.cpp")

# Project

add_executable(project Project/gemstones.cpp Project/gemstones.h Project/cardfactory.cpp Project/cardfactory.h Project/deck.cpp Project/deck.h Project/DiscardPile.cpp Project/DiscardPile.h Project/Table.cpp Project/Table.h Project/Players.cpp Project/Players.h Project/Chain.h)
