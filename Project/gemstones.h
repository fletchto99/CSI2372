#ifndef CSI2372_GEMSTONES_H
#define CSI2372_GEMSTONES_H

#include <string>
#include "Chain.h"

using namespace std;

class Card {
    virtual int getCardsPerCoin(int coins) = 0;
    virtual string getName() = 0;
    virtual void print(const ostream& out) = 0;
};

class Quartz : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};

class Hematite : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};

class Obsidian : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};

class Malachite : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);

};

class Turquoise : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};

class Ruby : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};

class Amethyst : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};

class Emerald : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};


#endif
