#ifndef CSI2372_CARDFACTORY_H
#define CSI2372_CARDFACTORY_H

#include "deck.h"

class CardFactory {
public:
    static CardFactory* getFactory();
    Deck getDeck();
};


#endif
