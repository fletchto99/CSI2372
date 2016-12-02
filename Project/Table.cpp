#include <iostream>
#include <fstream>

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
    deck = CardFactory::getFactory()->getDeck();
    discardPile = new DiscardPile(file, CardFactory::getFactory());
    tradeArea = new TradeArea(file, CardFactory::getFactory());
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
        winner = win->getName();
        return true;
    }
    return false;
}


void Table::print(std::ostream &) {

}

void Table::play() {

    while(!deck.empty()) {

        string choice = "";
        while (choice != "Y" || choice != "N") {
            cout << "Would you like to pause the game? [Y/N]";
            cin >> choice;
        }

        fstream out;


        if (choice == "Y") {
            out.open ("");
            out.close();
            return;
        }
        for (auto const &player : players) {

            print(out);

            if (player->getMaxNumChains() < 3) {
                choice = "";
                while (choice != "Y" || choice != "N") {
                    cout << "Would you like to pause the game? [Y/N]";
                    cin >> choice;
                }
                if (choice == "Y") {
                    player->buyThirdChain();
                }
            }
//            player->getHand() += deck.draw();


        }




    }
}
