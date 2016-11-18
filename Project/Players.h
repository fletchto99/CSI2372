#ifndef CSI2372_PLAYERS_H
#define CSI2372_PLAYERS_H

#include <string>
#include "chain.h"

class Player {

    Player( std::istream&, CardFactory* );

    Player( std::string& );
    std::string getName();
    int getNumCoins();
    Player& operator+=(int coins);
    int getMaxNumChains();
    int getNumChains();
    chain& operator[](int i);
    void buyThirdChain();
    void printHand(std::ostream&, bool);

};


#endif
