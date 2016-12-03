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

void DiscardPile::print(std::ostream & out) {
    out << "Discard Pile: [" << endl;
    for(auto card: d_cards){
        out << card << ", ";
    }
    out << " ]" << endl;
}

DiscardPile::DiscardPile(std::istream &, CardFactory *) {

}
