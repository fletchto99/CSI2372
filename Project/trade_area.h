#ifndef CSI2372_TRADEAREA_H
#define CSI2372_TRADEAREA_H

#include "gemstones.h"
#include "cardfactory.h"
#include <list>

/**
 * TradeArea holds the cards openly and support access insertion and removal.
 */
class TradeArea {
private:
    std::list<Card> d_list;
public:
    TradeArea& operator+=(Card*);
    bool legal(Card*);
    Card* trade(string);
    int numCards();
    TradeArea(std::istream&, CardFactory*);
};


#endif
