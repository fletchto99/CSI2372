#ifndef GEMSTONES_H
#define GEMSTONES_H

#include <string>
#include "Chain.h"

/**
 * An abstract class representing the card type
 */
class Card {
public:

    /**
     * Retireves the number of coins the user should get
     * for having x amount of cards in their chain
     *
     * @param cards The number of cards that have been chained
     * @return The number of coins the user should recieve
     */
    virtual int getCoinsForCards(int cards) = 0;

    /**
     * Retrieves the name of the card
     *
     * @return The name of the card
     */
    virtual std::string getName() = 0;

    /**
     * Prints the card to an output stream
     *
     * @param out The stream to print the card to
     */
    virtual void print(std::ostream &out) = 0;
};

class Quartz : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);
};

class Hematite : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);
};

class Obsidian : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);
};

class Malachite : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);

};

class Turquoise : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);
};

class Ruby : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);
};

class Amethyst : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);
};

class Emerald : public Card {
public:
    int getCoinsForCards(int cards);

    std::string getName();

    void print(std::ostream &out);
};

#endif