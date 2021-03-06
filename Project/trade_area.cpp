#include "trade_area.h"

TradeArea &TradeArea::operator+=(Card *card) {
    d_list.back() = card;
    return *this;
}

bool TradeArea::legal(Card *card) {
    return card == d_list.front();
}

Card *TradeArea::trade(const Card &_card) {
    Card *tmp = nullptr;
    for (auto a: d_list) {
        if (a == &_card) {
            tmp = a;
            d_list.remove(a);
        }
    }
    return tmp;
}

int TradeArea::numCards() {
    return (sizeof(d_list)) / (sizeof(Card));
}

std::list<Card *> TradeArea::getCards() {
    return d_list;
}

TradeArea::TradeArea(std::istream &, CardFactory *) {

}