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
                    "Labs/Lab 1/verbose_binary.cpp" "Labs/Lab 1/verbose_binary.h" Project/main.cpp Project/trade_area.cpp Project/trade_area.h Project/hand.cpp Project/hand.h)
add_executable(lab2 "Labs/Lab 2/main.cpp"
        "Labs/Lab 2/number_array.cpp" "Labs/Lab 2/number_array.h")
add_executable(lab3 "Labs/Lab 3/main.cpp" "Labs/Lab 3/bikerides.h" "Labs/Lab 3/bikerides.cpp")
add_executable(lab4 "Labs/Lab 4/main.cpp" "Labs/Lab 4/fruit_grower.cpp" "Labs/Lab 4/fruit_grower.h")
add_executable(lab5 "Labs/Lab 5/text_entry.cpp" "Labs/Lab 5/main.cpp" "Labs/Lab 5/questionaire.h" "Labs/Lab 5/text_entry.h" "Labs/Lab 5/questionaire.cpp")

# Project

add_executable(project Project/cardfactory.cpp Project/cardfactory.h Project/chain.h Project/deck.cpp Project/deck.h Project/discard_pile.cpp Project/discard_pile.h Project/gemstones.cpp project/gemstones.h Project/hand.cpp Project/hand.h Project/main.cpp Project/players.cpp Project/players.h Project/table.cpp Project/table.h Project/trade_area.cpp Project/trade_area.h)
