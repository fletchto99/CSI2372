#include <iostream>
#include <fstream>

#include "Table.h"

int main() {
    std::cout << "Where would you like to load the game from? Type 'new' to start a new game." << std::endl;
    std::string file;
    std::cin >> file;
    std::ifstream in;
    if (file != "new") {
        in.open(file);
    }
    //Creates an instance of the table
    Table *table = new Table(in);
    //Plays the game
    table->play();
    in.close();
    return 0;
}