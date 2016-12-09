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
    d_discardPile = new DiscardPile(file, CardFactory::getFactory(file));
    d_tradeArea = new TradeArea(file, CardFactory::getFactory(file));
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

        std::ostream *out;
        out = &std::cout;

        *out << "Would you like to save the game to a file? [Y/N]";

        std::string choice = "";
        std::cin >> choice;

        if (choice == "Y") {
            *out << "Where would you like to save the game to? Press enter to start a new game.";
            std::string file = "";
            std::cin >> file;
            std::ofstream fileout;
            fileout.open(file);
            //TODO: for each card in the deck print it to the file
            //TODO: print the discard pile to the file
            //TODO: for each player: save their hand, save their chains, save their tradearea
            fileout.close();
            return;
        }

        for (auto const &player : d_players) {

            //Display the table
            print(*out);

            //Buy a 3rd chain if you have 3 coins
            if (player->getMaxNumChains() < 3 && player->getNumCoins() >= 3) {
                *out << "Would you like to buy a third chain? [Y/N]";
                choice = "";
                std::cin >> choice;
                if (choice == "Y") {
                    player->buyThirdChain();
                }
            }

            //Draw card from deck
            player->getHand()->operator+=(d_deck->draw());


            //Play remaining cards in trade area
            if (d_tradeArea->numCards() > 0) {
                //For each card in the trade area check if it is chainable to the player
                for (auto &card : d_tradeArea->getCards()) {
                    Chain<Card*> *found = nullptr;
                    for (int i = 0; i < player->getNumChains(); i++) {
                        if (typeid(card) == typeid(player->operator[](i)->peek())) {
                            found = player->operator[](i);
                            break;
                        }
                    }

                    //if we found a matching chain for the current card check if the user wishes to chain the card
                    if (found != nullptr) {
                        *out << "Chaining card " << card->getName() << std::endl;
                        found->operator+=(&card);
                    }  else if (player->getNumChains() < player->getMaxNumChains()) {
                        Chain<Card*> *chain = new Chain<Card*>();
                        chain->operator+=(&card);
                        player->addChain(chain);
                    } else {
                        *out << "Discarding card " << card->getName() << std::endl;
                    }
                }

            }

            //Play topmost card from Hand into chain
            Card *toPlay = player->getHand()->play();

            *out << "Your topmost card is " << toPlay->getName() << std::endl;

            Chain<Card*> *toChain = nullptr;
            for (int i = 0; i < player->getNumChains(); i++) {
                if (typeid(*toPlay) == typeid(player->operator[](i))) {
                    toChain = player->operator[](i);
                    break;
                }
            }

            //if we found a matching chain for the current card check if the user wishes to chain the card
            if (toChain != nullptr) {
                *out << "Chaining topmost card " << toPlay->getName() << std::endl;
                toChain->operator+=(&toPlay);
                *out << "Would you like to sell the chain of " << toPlay->getName() << " that is length " << toChain->length();
                choice = "";
                std::cin >> choice;
                if (choice == "Y") {
                    //Sells & removes the chain
                    player->sellChain(toChain);
                }
            } else {
                //force sell a chain if needed
                if (player->getNumChains() == player->getMaxNumChains()) {
                    *out << "Which chain would you like to sell? 1-" << player->getMaxNumChains();
                    int shouldSell;
                    std::cin >> shouldSell;
                    player->sellChain(player->operator[](shouldSell));
                } else {
                    //create a new chain and add the first card to enforce typing
                    Chain<Card*> *chain = new Chain<Card*>();
                    chain->operator+=(&toPlay);
                    player->addChain(chain);
                }
            }

            *out << "Do you want to play a next card? [Y/N]";
            choice = "";
            std::cin >> choice;
            if (choice == "Y") {
                //Play topmost card from Hand into chain
                Card *nextToPlay = player->getHand()->play();

                *out << "Your topmost card is " << toPlay->getName();

                Chain<Card*> *nextToChain = nullptr;
                for (int i = 0; i < player->getNumChains(); i++) {
                    if (typeid(*nextToPlay) == typeid(player->operator[](i))) {
                        nextToChain = player->operator[](i);
                        break;
                    }
                }

                //if we found a matching chain for the current card check if the user wishes to chain the card
                if (nextToChain != nullptr) {
                    *out << "Chaining topmost card " << nextToPlay->getName() << std::endl;
                    nextToChain->operator+=(&nextToPlay);
                    *out << "Would you like to sell the chain of " << nextToPlay->getName() << " that is length " << nextToChain->length();
                    choice = "";
                    std::cin >> choice;
                    if (choice == "Y") {
                        //Sells & removes the chain
                        player->sellChain(nextToChain);
                    }
                } else {
                    //force sell a chain if needed
                    if (player->getNumChains() == player->getMaxNumChains()) {
                        *out << "Which chain would you like to sell? 1-" << player->getMaxNumChains();
                        int shouldSell;
                        std::cin >> shouldSell;
                        player->sellChain(player->operator[](shouldSell));
                    } else {
                        //create a new chain and add the first card to enforce typing
                        Chain<Card*> *chain = new Chain<Card*>();
                        chain->operator+=(&nextToPlay);
                        player->addChain(chain);
                    }
                }
            }


            //Allow the user to discard one card from their hand if they choose to
            *out << "Would you like to look at your hand and discard a card? [Y/N]";
            choice = "";
            std::cin >> choice;
            if (choice == "Y") {
                int arbitraryCard = -1;
                player->getHand()->print(*out);
                *out << "Which card would you like to remove?";
                std::cin >> arbitraryCard;
                if (arbitraryCard > -1) {
                    d_discardPile->operator+=(player->getHand()->operator[](arbitraryCard));
                }
            }

            //Draw 3 cards from the deck into the trade area
            d_tradeArea->operator+=(d_deck->draw());
            d_tradeArea->operator+=(d_deck->draw());
            d_tradeArea->operator+=(d_deck->draw());

            //check if the top of the discard pile matches any cards in the trade area
            while (d_tradeArea->legal(d_discardPile->top())) {
                d_tradeArea->operator+=(d_discardPile->pickUp());
            }

            //For each card in the trade area check if it is chainable to the player
            for (auto &card : d_tradeArea->getCards()) {
                Chain<Card*> *found = nullptr;
                for (int i = 0; i < player->getNumChains(); i++) {
                    if (typeid(card) == typeid(player->operator[](i))) {
                        found = player->operator[](i);
                        break;
                    }
                }
                *out << "Would you like chain this " + card->getName() + " card? [Y/N]";
                choice = "";
                std::cin >> choice;

                //They wish to chain the card, check if they now want to sell it
                if (choice == "Y") {
                    //if we found a matching chain for the current card check if the user wishes to chain the card
                    if (found != nullptr) {
                        found->operator+=(&card);
                        *out << "You have " << found->length() << " cards in this chain of " << ((Card*)found->peek())->getName() << std::endl;
                        *out << "Would you like sell this chain? [Y/N]";
                        choice = "";
                        std::cin >> choice;

                        //They want to sell the chain, so sell it and give them the coins
                        if (choice == "Y") {
                            player->sellChain(found);
                        }

                    } else if (player->getNumChains() < player->getMaxNumChains()) {
                        Chain<Card*> *chain = new Chain<Card*>();
                        chain->operator+=(&card);
                        player->addChain(chain);
                    }
                }
            }

            //Draw 2 cards from the deck to the hand
            player->getHand()->operator+=(d_deck->draw());
            player->getHand()->operator+=(d_deck->draw());
        }


    }
}