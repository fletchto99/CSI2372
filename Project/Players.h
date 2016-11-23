#ifndef CSI2372_PLAYERS_H
#define CSI2372_PLAYERS_H

#include <string>
#include <queue>
#include "chain.h"

class Player {
private:
    string d_name;
    int d_coins;
    int d_numChains;
    std::queue<Card, std::list> chains;
public:
    Player( std::istream&, std::string&);
    Player( std::string& );

    std::string getName();
    int getNumCoins();
    Player& operator+=(int coins);
    int getMaxNumChains();
    int getNumChains();
    Chain& operator[](int i);
    void buyThirdChain();
    void printHand(std::ostream&, bool);

};


#endif
