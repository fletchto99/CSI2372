#include "trade_area.h"

TradeArea &TradeArea::operator+=(Card *card) {
    d_list.back() = *card;
}

bool TradeArea::legal(Card *card) {
    return card == d_list.front();
}

Card *TradeArea::trade(const Card &_card) {
    Card tmp;
    std::list<Card>::iterator iter = ;

    d_list.remove(_card);
    return nullptr;
}

int TradeArea::numCards() {
    return 0;
}

TradeArea::TradeArea(std::istream &, CardFactory *) {

}
