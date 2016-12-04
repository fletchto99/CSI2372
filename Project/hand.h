#ifndef HAND_H
#define HAND_H

#include "gemstones.h"
#include "cardfactory.h"
#include <queue>
#include <vector>

class Hand {
private:
    std::vector<Card*> d_hand;
public:
    Hand& operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
    Hand(std::istream&, CardFactory*);
    void print(std::ostream& os);
};

#endif