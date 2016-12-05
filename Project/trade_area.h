#ifndef TRADEAREA_H
#define TRADEAREA_H

#include "gemstones.h"
#include "cardfactory.h"
#include <list>

/**
 * TradeArea holds the cards in a list. It supports adding and removing cards
 * in a convinent manner
 */
class TradeArea {
private:
    //the list to store the cards in
    std::list<Card *> d_list;
public:

    /**
     * An operator which will add a card to the trade area
     *
     * @param card The card to be added to the trade area
     */
    TradeArea &operator+=(Card *card);

    /**
     * Checks if the card specified matches the cards in the trade area
     *
     * @param card The card to check
     * @return True if the card matches; otherwise false
     */
    bool legal(Card *card);

    /**
     * Removes a card in the trade area
     *
     * @param card The card to remove from the trade area
     * @return The card that has been removed from the trade area
     */
    Card *trade(const Card &card);

    /**
     * Retrieves the number of cards currently in the trade area
     *
     * @return The number of cards in the trade area
     */
    int numCards();

    /**
     * Constructs a trade area
     *
     * @param input The input stream to build the trade area from
     * @param cardFactory The card factory instance
     */
    TradeArea(std::istream &input, CardFactory *cardFactory);

    /**
     * Retrieves all of the cards in the trade area
     *
     * @return The cards in the trade area
     */
    std::list<Card> getCards();
};

#endif