#include "hand.h"
#include <iostream>
#include <queue>
#include <vector>
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
        d_hand.pop();
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

    if(!d_hand.empty()){
        for(int i=0; i<index; i++){

        }
    }

    return nullptr;
}

/*
Hand::Hand(std::istream &, CardFactory *) {

}
