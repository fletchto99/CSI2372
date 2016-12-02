#ifndef CSI2372_TABLE_H
#define CSI2372_TABLE_H

#include <string>

#include "Players.h"
#include "discard_pile.h"
#include "trade_area.h"


class Table {
private:
    std::vector<Player*> players;
    DiscardPile* discardPile;
    TradeArea* tradeArea;
    Deck deck;
public:
    Table(std::istream& file);
    bool win( std::string& );
    void print(std::ostream&);
    void play();
};


#endif
