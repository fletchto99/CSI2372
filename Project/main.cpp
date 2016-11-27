#include <iostream>
#include <fstream>

#include "cardfactory.h"
#include "players.h"

using namespace std;


int main() {

    cout << "Where would you like to load the game from? Press enter to start a new game.";

    string file = "";
    cin >> file;

    Deck deck = CardFactory::getFactory()->getDeck();

    ifstream in;

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