#ifndef CSI2372_HAND_H
#define CSI2372_HAND_H

#include "gemstones.h"
#include "cardfactory.h"

class Hand {
public:
    Hand&operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
    Hand(std::istream&, CardFactory*);
};


#endif
