#include <iostream>
#include <fstream>

#include "Table.h"

using namespace std;


int main() {
    cout << "Where would you like to load the game from? Press enter to start a new game.";
    string file = "";
    cin >> file;
    ifstream in;
    in.open(file);
    (new Table(in)) -> play();
    in.close();
    return 0;
}