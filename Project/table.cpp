#include "table.h"

std::string &getName(int player) {
    std::string name;
    while (name == "") {
        std::cout << "What is player " << player << "'s name?" << std::endl;
        std::cin >> name;
    }
    return name;
}

Table::Table(std::istream &file) {
    d_deck = CardFactory::getFactory(file)->getDeck();
    d_discardPile = new DiscardPile(file, CardFactory::getFactory());
    d_tradeArea = new TradeArea(file, CardFactory::getFactory());
    d_players.push_back(new Player(file, getName(1)));
    d_players.push_back(new Player(file, getName(2)));

    for (auto const &player: d_players) {
        for (int i = 0; i < 5; i++) {
            *player->getHand() += d_deck->draw();
        }
    }
}

bool Table::win(std::string &winner) {
    if (d_deck->empty()) {
        Player *win = nullptr;
        for (auto const &player: d_players) {
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

    while (!d_deck->empty()) {

        std::string choice = "";
        while (choice != "Y" || choice != "N") {
            std::cout << "Would you like to pause the game? [Y/N]";
            std::cin >> choice;
        }

        std::ostream *out;

        if (choice == "Y") {
            std::cout << "Where would you like to save the game to? Press enter to start a new game.";
            std::string file = "";
            std::cin >> file;
            std::ofstream fileout;
            fileout.open(file);
            //TODO: for each card in the deck print it to the file
            //TODO: print the discard pile to the file
            //TODO: for each player: save their hand, save their chains, save their tradearea
            fileout.close();
            return;
        } else {
            out = &std::cout;
        }

        for (auto const &player : d_players) {

            print(*out);

            if (player->getMaxNumChains() < 3) {
                choice = "";
                while (choice != "Y" || choice != "N") {
                    std::cout << "Would you like to pause the game? [Y/N]";
                    std::cin >> choice;
                }
                if (choice == "Y") {
                    player->buyThirdChain();
                }
            }
            player->getHand()->operator+=(d_deck->draw());

            if (d_tradeArea->numCards() > 0) {
                //TODO: Add gemstone cards from the TradeArea to chains or discard them
//                player->getChains();
                //FOR each chain check if the type of that chain is the same as the card in the trade area

            }

//            Play topmost card from Hand.

            if (player->getHand()) {

            }
//            If chain is ended, cards for chain are removed and player receives coin(s).


            //TODO: Print out current chains
            //TODO: Print out the top card in the players hand


//            If player decides to Play the now topmost card from Hand.
//            If chain is ended, cards for chain are removed and player receives coin(s).

            choice = "";
            while (choice != "Y" || choice != "N") {
                *out << "Would you like to look at your hand and discard a card? [Y/N]";
                std::cin >> choice;
            }

            if (choice == "Y") {
                int arbitraryCard = -1;
                player->getHand()->print(*out);
                *out << "Which card would you like to remove 1-5?";
                std::cin >> arbitraryCard;
                if (arbitraryCard > -1) {
                    d_discardPile->operator+=(player->getHand()->operator[](1));
                }
            }
            d_tradeArea->operator+=(d_deck->draw());

            while (d_tradeArea->legal(d_discardPile->top())) {
                d_tradeArea->operator+=(d_discardPile->pickUp());
            }

            for (auto &card : d_tradeArea->getCards()) {
                Chain<Card*> *found = nullptr;
                for (int i = 0; i < player->getNumChains(); i++) {
//                    if (typeid(card) == typeid(player->operator[](i)->getType())) {
//                        found = player->operator[](i);
//                        break;
//                    }
                }
                if (found != nullptr) {
                    choice = "";
                    while (choice != "Y" || choice != "N") {
                        *out << "Would you like chain this " + card->getName() + " card? [Y/N]";
                        std::cin >> choice;
                    }
                    if (choice == "Y") {
                        //TODO: They want to chain the card
                    } else {
                        //TODO: they don't wanna chain the card
                    }
                } else {
                    *out << "Unable to chain card... Discarding";
                }


            }

//            for all cards in the trade area
//              if player wants to chain the card
//                  chain the card
//                  If chain is ended
//                      cards for chain are removed and player receives coin(s).
//              else
//                  card remains in trade area for the next player.
//            end

            player->getHand()->operator+=(d_deck->draw());
        }


    }
}