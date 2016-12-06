#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>

#include "cardfactory.h"

/**
 * The disard pile stores all of discarded cards in
 * a vector
 */
class DiscardPile {
private:
    //The vector to store the discarded cards in
    std::vector<Card *> d_cards;
public:

    /**
     * Initilizes the discard pile
     *
     * @param input The input file to rebuild the discard pile from if necessecary
     * @param cardFactory The card factory
     */
    DiscardPile(std::istream &input, CardFactory *cardFactory);

    /**
     * crates a += operator to add a card to the discard pile
     * @return
     */
    DiscardPile &operator+=(Card *);

    /**
     * Removes the card at the top of the discard pile
     *
     * @return The top card of the discard pile
     */
    Card *pickUp();

    /**
     * Peeks at the card at the top of the discard pile
     *
     * @return The card at the top of the discard pile
     */
    Card *top();

    /**
     * Prints the discard pile to the specified output stream
     *
     * @param out The stream to print the file to
     */
    void print(std::ostream &out);

};

#endif