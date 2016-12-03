#include "hand.h"

using namespace std;

/**
 * Adds the card to the rear of the hand
 * @return
 */
Hand &Hand::operator+=(Card *card) {
     d_hand.back() = card;
}

/**
 * Returns and removes the top card from the player's hand
 * @return
 */
Card *Hand::play() {
    Card* cardPtr = nullptr;

    if(!d_hand.empty()) {
        cardPtr = d_hand.front();
        d_hand.pop_back();
    }

    return cardPtr;
}

/**
 * Return but does not remove the top card from the player's hand
 * @return
 */
Card *Hand::top() {
    Card* cardPtr = d_hand.front();
    return cardPtr;
}

/**
 * Returns and removes the Card at a given index
 * @return
 */
Card *Hand::operator[](int index) {
    Card* cardPtr = nullptr;
    if(!d_hand.empty()) {
        cardPtr = d_hand.at(index);
        d_hand.erase(d_hand.begin() + index);
    }
    return cardPtr;
}


Hand::Hand(std::istream &input , CardFactory *) {
//    d_hand.push_back()
//    input>>strName>>nSomeInteger>>nSomeInteger2;
//    cout<<strName<<" "<<nSomeInteger<<" "<<nSomeInteger2<<endl;;
}

void Hand::print(std::ostream &os) {
    for(auto cards: d_hand){
        cout << cards << " " << endl;
    }
}
