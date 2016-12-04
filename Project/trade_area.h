#ifndef TRADEAREA_H
#define TRADEAREA_H

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
    Card* trade(const Card &);
    int numCards();
    TradeArea(std::istream&, CardFactory*);
    std::list<Card> getCards();
};

#endif