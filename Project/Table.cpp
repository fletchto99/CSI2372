#include <iostream>

#include "table.h"

string &getName(int player) {
    string name;
    while (name == "") {
        cout << "What is player " << player << "'s name?" << endl;
        cin >> name;
    }
    return name;
}

Table::Table(std::istream &file) {
    players.push_back(new Player(getName(1)));
    players.push_back(new Player(getName(2)));

    for(auto const &player: players) {
        for (int i = 0; i < 5; i++) {
            *player->getHand() += CardFactory::getFactory()->getDeck().draw();
        }
    }
}

bool Table::win(std::string &winner) {
    if (CardFactory::getFactory()->getDeck().empty()) {
        Player* win = nullptr;
        for(auto const &player: players) {
            if (win == nullptr || win->getNumCoins() < player->getNumCoins()) {
                win = player;
            }
        }
        winner->
    }
    return false;
}


void Table::print(std::ostream &) {

}