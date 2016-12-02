#include "deck.h"

Card *Deck::draw() {
    Card *res = (Card *) this->at(0);
    this->erase(this->begin(),this->begin()+1);
    return res;
}

Deck::Deck(std::istream &, CardFactory *) {

}
