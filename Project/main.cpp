#include <iostream>

#include "cardfactory.h"
#include "players.h"

using namespace std;

string &getName(int player) {
    string name;
    while (name == "") {
        cout << "What is player " << player << "'s name?" << endl;
        cin >> name;
    }
    return name;
}

int main() {

    cout << "Where would you like to load the game from? Press enter to start a new game.";

    string file = "";

    Deck deck = new Deck(nullptr, CardFactory::getFactory());


    std::vector<Player*> players;
    if (file != "") {
        //TODO: Load players from file istream
    } else {
        players.push_back(new Player(getName(1)));
        players.push_back(new Player(getName(2)));
    }


    for(auto const &player: players) {
        for (int i = 0; i < 5; i++) {
            //TODO: Fill hand with 5 cards
//            player->getHand() += deck.draw();
        }
    }

    while(!deck.empty()) {
        string choice = "";
        while (choice != "Y" || choice != "N") {
            cout << "Would you like to pause the game? [Y/N]";
            cin >> choice;
        }

        if (choice == "Y") {
            //TODO: Save the game
            return 0;
        } else {
            for (auto const &player : players) {

                //TODO: Display the table

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

                //TODO: Draw a card from the deck
//                player.getHand()
            }
        }




    }

    return 0;
}