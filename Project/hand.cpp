#include "hand.h"

Hand &Hand::operator+=(Card *card) {
    d_hand.push_back(card);
    return *this;
}

Card *Hand::play() {
    Card *cardPtr = nullptr;

    if (!d_hand.empty()) {
        cardPtr = d_hand.front();
        d_hand.pop_back();
    }

    return cardPtr;
}

Card *Hand::top() {
    return d_hand.front();
}

Card *Hand::operator[](int index) {
    Card *cardPtr = nullptr;
    if (!d_hand.empty()) {
        cardPtr = d_hand.at(index);
        d_hand.erase(d_hand.begin() + index);
    }
    return cardPtr;
}


Hand::Hand(std::istream &input, CardFactory *) {
}

void Hand::print(std::ostream &out) {
    out << "Hand: [ ";
    for (auto& cards: d_hand) {
        cards->print(out);
        std::cout << ", ";
    }
    out << "]" << std::endl;
}