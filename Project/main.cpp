#include <iostream>
#include <fstream>

#include "Table.h"

int main() {
    std::cout << "Where would you like to load the game from? Type 'new' to start a new game." << std::endl;
    std::string file;
    std::cout << "-3";
    std::cin >> file;
    std::cout << "-2";
    std::ifstream in;
    if (file != "new") {
        in.open(file);
    }
    std::cout << "-1";
    //Creates an instance of the table
    Table *table = new Table(in);
    std::cout << "0";
    //Plays the game
    table->play();
    in.close();
    return 0;
}