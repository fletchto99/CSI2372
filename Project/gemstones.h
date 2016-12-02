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
Chain<Quartz>
class Quartz : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};
Chain<Hematite>
class Hematite : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};
Chain<Obsidian>
class Obsidian : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};
Chain<Malachite>
class Malachite : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);

};
Chain<Turquoise>
class Turquoise : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};
Chain<Ruby>
class Ruby : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};
Chain<Amethyst>
class Amethyst : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};
Chain<Emerald>
class Emerald : public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream& out);
};


#endif
