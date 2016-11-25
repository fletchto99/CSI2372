#ifndef CSI2372_CARDFACTORY_H
#define CSI2372_CARDFACTORY_H

#include <list>

#include "deck.h"

class CardFactory {
private:
    Deck<Card> d_deck = NULL;
    static CardFactory* d_factory = nullptr;

    CardFactory();

public:
    static CardFactory* getFactory();
    Deck getDeck();
    ~CardFactory();
};


#endif
