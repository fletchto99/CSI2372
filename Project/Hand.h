#ifndef CSI2372_HAND_H
#define CSI2372_HAND_H

#include "gemstones.h"
#include "cardfactory.h"
#include <queue>
#include <vector>

class Hand {
private:
    std::queue<Card*, std::vector> d_hand;
public:
    Hand& operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
    Hand(std::istream&, CardFactory*);
};


#endif
