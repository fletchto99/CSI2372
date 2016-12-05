#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <queue>
#include "chain.h"
#include "hand.h"

class Player {
private:
    std::string d_name;
    int d_coins;
    int d_numChains;
    std::vector<Chain<Card>> d_chains;
    Hand d_hand = NULL;
public:
    Player( std::istream&, std::string&);
    Player( std::string& );

    Hand* getHand();
    std::string getName();
    int getNumCoins();
    Player& operator+=(int coins);
    int getMaxNumChains();
    int getNumChains();
    Chain<Card> getAvaliableChains();
    Chain& operator[](int i);
    void buyThirdChain();
    void printHand(std::ostream&, bool);

};

#endif
