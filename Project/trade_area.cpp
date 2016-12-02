#include "trade_area.h"

TradeArea &TradeArea::operator+=(Card *card) {
    d_list.back() = *card;
}

bool TradeArea::legal(Card *card) {
    return card == d_list.front();
}

Card *TradeArea::trade(const Card &_card) {
    Card *tmp = nullptr;
    for(auto a: d_list){
        if(a == _card){
            *tmp = a;
            d_list.remove(a);
        }
    }
    return tmp;
}

int TradeArea::numCards() {
    return (sizeof(d_list))/(sizeof(Card));
}

TradeArea::TradeArea(std::istream &, CardFactory *) {

}
