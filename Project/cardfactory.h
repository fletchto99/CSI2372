#ifndef CSI2372_CARDFACTORY_H
#define CSI2372_CARDFACTORY_H

#include <list>

#include "deck.h"

class CardFactory {
private:
    Deck<Card> d_deck;
    static CardFactory* d_factory = nullptr;
public:
    static CardFactory* getFactory();
    Deck getDeck();
};


#endif
