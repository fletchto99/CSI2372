#ifndef DECK_H
#define DECK_H

#include "gemstones.h"
#include "cardfactory.h"

#include <vector>

using namespace std;

class Deck : public vector {

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