#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <list>

#include "deck.h"

class CardFactory {
private:
    Deck<Card> d_deck = NULL;
    static CardFactory* d_factory;

    CardFactory(std::istream &input);

public:
    static CardFactory* getFactory();
    static CardFactory* getFactory(std::istream &input);
    Deck<Card> getDeck();
    ~CardFactory();
};


#endif
