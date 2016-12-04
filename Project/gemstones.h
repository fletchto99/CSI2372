#ifndef GEMSTONES_H
#define GEMSTONES_H

#include <string>
#include "Chain.h"

using namespace std;

class Card {
public:
    virtual int getCoinsForCards(int cards) = 0;
    virtual string getName() = 0;
    virtual void print(ostream& out) = 0;
};

class Quartz : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);
};

class Hematite : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);
};

class Obsidian : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);
};

class Malachite : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);

};

class Turquoise : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);
};

class Ruby : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);
};

class Amethyst : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);
};

class Emerald : public Card {
public:
    int getCoinsForCards(int cards);
    string getName();
    void print(std::ostream& out);
};
#endif