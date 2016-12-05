#ifndef DECK_H
#define DECK_H

#include "cardfactory.h"
#include "gemstones.h"

#include <vector>

template <typename T>

class Deck : public std::vector<T> {

public:
    /**
     * Reconstructs the deck from file.
     */
    Deck( std::istream&, CardFactory* );

    /**
     * Returns and removes the top card from the deck
     *
     * @return The top card from the deck
     */
    Card* draw();

};
#endif