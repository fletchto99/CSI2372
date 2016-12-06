#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <list>
#include <fstream>

#include "deck.h"

class Deck;

/**
 * The card factory is a singleton which contains one copy
 * of the deck. All deck operations must be applied to the
 * deck that the card factory stores
 */
class CardFactory {
private:
    //Private vars used to hold instance information
    Deck *d_deck;
    static CardFactory *d_factory;

    /**
     * Creates an instance of the deck, shuffling all of the cards
     *
     * @param input The stream of a file to load the saved deck from
     */
    CardFactory(std::istream &input);

public:

    /**
     * Retrieves the instance of the card factory
     * or creates one if null
     *
     * @return The cardfactory instance
     */
    static CardFactory *getFactory() {
        std::ifstream ignore;
        return new CardFactory(ignore);
    }

    /**
     * Retrieves the instance of the card factory
     * or creates one from the input stream if null
     *
     * @return The cardfactory instance
     */
    static CardFactory *getFactory(std::istream &input) {
        return new CardFactory(input);
    };

    /**
     * Retrieves the deck
     *
     * @return The deck that is stored in the card factory
     */
    Deck *getDeck();

    /**
     * Destroys the card factory
     */
    ~CardFactory();
};


#endif
