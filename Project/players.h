#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <vector>

#include "chain.h"
#include "hand.h"

/**
 * The player class stores all of the information related
 * to the individual players
 */
class Player {
private:
    //Variables to store the player's information
    std::string d_name;
    int d_coins;
    int d_numChains;
    std::vector<Chain<Card*>*> d_chains;
    Hand *d_hand;
public:

    /**
     * Initilizes the player's information
     *
     * @param input The input stream to generate the player from
     * @param name The name of the player, if the stream doesn't already contain this information
     */
    Player(std::istream &input, std::string &name);

    /**
     * Retrieves the hand of the player
     *
     * @return The hand of the player
     */
    Hand *getHand();

    /**
     * Retrieves the name of the player
     *
     * @return The player's name
     */
    std::string getName();

    /**
     * Retrieves the number of coins a player has
     *
     * @return The number of coins the player has
     */
    int getNumCoins();

    /**
     * Adds some coins to the players instance
     *
     * @param coins The number of coins to add
     */
    Player &operator+=(int coins);

    /**
     * Retrieves the maximum number of chains that the player is allowed to have
     *
     * @return The max number of chains the player can have
     */
    int getMaxNumChains();

    /**
     * Retrieves the current number of chains the player has
     *
     * @return The current number of chains the player has
     */
    int getNumChains();

    /**
     * Retieves the chain at a specific index
     *
     * @param i The index to look up the chain at
     * @return The chain at the specific index
     */
    Chain<Card*> *operator[](int i);

    /**
     * Adds a third chain to the player's chain vector
     */
    void buyThirdChain();

    /**
     * Prints the player's hand
     *
     * @param out The output stream to write the hand to
     * @param top Only print out the top card of the hand
     */
    void printHand(std::ostream &out, bool top);

    /**
     * Sells a player's chain and opens up a slot for other chains
     *
     * @param chain The chain to sell
     */
    void sellChain(Chain<Card*>* chain);

};

#endif
