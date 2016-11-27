#include "trade_area.h"

TradeArea &TradeArea::operator+=(Card *card) {
    d_list.back() = *card;
}

bool TradeArea::legal(Card *card) {
    return card == d_list.front();
}

Card *TradeArea::trade(string) {

    return nullptr;
}

int TradeArea::numCards() {
    return 0;
}

TradeArea::TradeArea(std::istream &, CardFactory *) {

}
