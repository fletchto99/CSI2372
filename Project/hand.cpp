#include "hand.h"

Hand &Hand::operator+=(Card *card) {
    d_hand.back() = card;
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
//    d_hand.push_back()
//    input>>strName>>nSomeInteger>>nSomeInteger2;
//    cout<<strName<<" "<<nSomeInteger<<" "<<nSomeInteger2<<endl;;
}

void Hand::print(std::ostream &out) {
    out << "Hand: [ ";
    for (auto cards: d_hand) {
        std::cout << cards << " ," << std::endl;
    }
    out << "]" << std::endl;
}