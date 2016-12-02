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
    deck = CardFactory::getFactory(file)->getDeck();
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
            //TODO: for each card in the deck print it to the file
            //TODO: print the discard pile to the file
            //TODO: for each player: save their hand, save their chains, save their tradearea
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
            player->getHand()->operator+=(deck.draw());

            if (tradeArea->numCards() > 0) {
                //TODO: Add gemstone cards from the TradeArea to chains or discard them
//                tradeArea->
            }

//            Play topmost card from Hand.
//            If chain is ended, cards for chain are removed and player receives coin(s).
//            If player decides to Play the now topmost card from Hand.
//            If chain is ended, cards for chain are removed and player receives coin(s).

            choice = "";
            while (choice != "Y" || choice != "N") {
                cout << "Would you like to look at your hand and discard a card? [Y/N]";
                cin >> choice;
            }

            if (choice == "Y") {
                int arbitraryCard = -1;
                player->getHand()->print(out);
                cout << "Which card would you like to remove 1-5?";
                cin >> arbitraryCard;
                if(arbitraryCard > -1) {
                    discardPile->operator+=(player->getHand()->operator[](1));
                }
            }
            tradeArea->operator+=(deck.draw());

            while (tradeArea->legal(discardPile->top())) {
                tradeArea->operator+=(discardPile->pickUp());
            }

//            for all cards in the trade area
//              if player wants to chain the card
//                  chain the card
//              If chain is ended
//                  cards for chain are removed and player receives coin(s).
//              else
//                  card remains in trade area for the next player.
//            end

            player->getHand()->operator+=(deck.draw());
        }




    }
}
