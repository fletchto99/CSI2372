#include "discard_pile.h"

DiscardPile &DiscardPile::operator+=(Card *card) {
    d_cards.push_back(card);
}

Card *DiscardPile::pickUp() {
    Card *res = d_cards.at(0);
    d_cards.erase (d_cards.begin(), d_cards.begin()+1);
    return res;
}

Card *DiscardPile::top() {
    return d_cards.at(0);
}

void DiscardPile::print(std::ostream &) {

}

DiscardPile::DiscardPile(std::istream &, CardFactory *) {

}
