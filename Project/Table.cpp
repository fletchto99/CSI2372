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
            cout << "Where would you like to save the game to? Press enter to start a new game.";
            string file = "";
            cin >> file;
            out.open (file);
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

            //TODO: Draw top card from the deck
//            player->getHand() += deck.draw();

            if (tradeArea->numCards() > 0) {
                //TODO: Add gemstone cards from the TradeArea to chains or discard them
//                tradeArea->
            }

//            Play topmost card from Hand.
//            If chain is ended, cards for chain are removed and player receives coin(s).
//            If player decides to Play the now topmost card from Hand.
//            If chain is ended, cards for chain are removed and player receives coin(s).
//            If player decides to Show the player's full hand and player selects an arbitrary card

//            Discard the arbitrary card from the player's hand and place it on the discard pile.
//            Draw three cards from the deck and place cards in the trade area

//            while top card of discard pile matches an existing card in the trade area
//              draw the top-most card from the discard pile and place it in the trade area
//            end
//            for all cards in the trade area
//              if player wants to chain the card
//                  chain the card
//              If chain is ended
//                  cards for chain are removed and player receives coin(s).
//              else
//                  card remains in trade area for the next player.
//            end
//            Draw two cards from Deck and add the cards to the player's hand (at the back).
        }




    }
}
