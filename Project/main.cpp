#include <iostream>
#include <fstream>

#include "Table.h"

int main() {
    std::cout << "Where would you like to load the game from? Press enter to start a new game.";
    std::string file = "";
    std::cin >> file;
    std::ifstream in;
    in.open(file);
    (new Table(in)) -> play();
    in.close();
    return 0;
}