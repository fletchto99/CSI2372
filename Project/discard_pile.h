#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>

#include "gemstones.h"
#include "cardfactory.h"

using namespace std;

class DiscardPile {
private:
    std::vector<Card*> d_cards;
public:

    DiscardPile( std::istream&, CardFactory* );

    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top();
    void print( std::ostream& );

};
#endif