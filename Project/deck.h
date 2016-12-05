#ifndef DECK_H
#define DECK_H

#include "cardfactory.h"
#include "gemstones.h"

#include <vector>

/**
 * The deck extends a vectory of type <T> which will eventually
 * store all of the cards, shuffled by the cardfactory
 */
template <typename T>
class Deck : public std::vector<T> {

public:
    /**
     * Reconstructs the deck from file.
     *
     * @param out The input stream to rebuild the deck from
     * @param cardFactory The cardfactory
     */
    Deck(std::istream &input, CardFactory* cardFactory);

    /**
     * Returns and removes the top card from the deck
     *
     * @return The top card from the deck
     */
    Card* draw();

};
#endif