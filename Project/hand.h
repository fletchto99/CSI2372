#ifndef HAND_H
#define HAND_H

#include <vector>

#include "cardfactory.h"

/**
 * Stores a player's hand in a vector
 */
class Hand {
private:
    //The vector containing the player's hand
    std::vector<Card *> d_hand;
public:

    /**
     * An operator to add a card to the player's hand
     *
     * @param card The card to add to the player's hand
     */
    Hand &operator+=(Card *card);

    /**
     * Returns and removes the top card from the player's hand
     *
     * @return A pointer to the top card in the player's hand
     */
    Card *play();

    /**
     * Peeks at the player's top card in their hand
     *
     * @return The top card in the player's hand
     */
    Card *top();

    /**
     * Retrieves the card at a specific index in the player's hand
     *
     * @param index The index of the card
     * @return The card at the specified index
     */
    Card *operator[](int index);

    /**
     * Initilizes a player's hand
     *
     * @param input The input file to rebuild the players hand from
     * @return The card factory
     */
    Hand(std::istream &input, CardFactory *cardFactory);

    /**
     * Print's the player's hand to an output stream
     *
     * @param out The stream to write the player's hand to
     */
    void print(std::ostream &out);
};

#endif