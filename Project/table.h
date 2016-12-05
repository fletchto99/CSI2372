#ifndef TABLE_H
#define TABLE_H

#include <string>

#include "Players.h"
#include "discard_pile.h"
#include "trade_area.h"

/**
 * Stores all information for the table (players, discard pile, trade area, deck)
 */
class Table {
private:
    //The vars to store the information in
    std::vector<Player *> players;
    DiscardPile *discardPile;
    TradeArea *tradeArea;
    Deck *deck;
public:

    /**
     * Constructs a table
     *
     * @param file The file to construct the table from
     */
    Table(std::istream &file);

    /**
     * Checks if the player has won
     *
     * @return True if the player won; otherwise false
     */
    bool win(std::string &);

    /**
     * Outputs the table
     *
     * @param out Prints the table to the output stream
     */
    void print(std::ostream &out);

    /**
     * Plays the game
     */
    void play();
};

#endif