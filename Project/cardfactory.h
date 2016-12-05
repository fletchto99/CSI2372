#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <list>

#include "deck.h"
#include "gemstones.h"

/**
 * The card factory is a singleton which contains one copy
 * of the deck. All deck operations must be applied to the
 * deck that the card factory stores
 */
class CardFactory {
private:
    //Private vars used to hold instance information
    Deck<Card> d_deck = NULL;
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
    static CardFactory *getFactory();

    /**
     * Retrieves the instance of the card factory
     * or creates one from the input stream if null
     *
     * @return The cardfactory instance
     */
    static CardFactory *getFactory(std::istream &input);

    /**
     * Retrieves the deck
     *
     * @return The deck that is stored in the card factory
     */
    Deck<Card> getDeck();

    /**
     * Destroys the card factory
     */
    ~CardFactory();
};


#endif
