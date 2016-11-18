#include "cardfactory.h"

CardFactory *CardFactory::getFactory() {
    if (d_factory == nullptr) {
        d_factory = new CardFactory();
        CardFactory reference = (*d_factory);
        for(size_t i = 0; i < 104; i++) {
            if (i < 20) {
                reference.d_deck.push_back(new Quartz());
            } else if (i < 38) {
                reference.d_deck.push_back(new Hematite());
            } else if (i < 54) {
                reference.d_deck.push_back(new Obsidian());
            } else if (i < 68) {
                reference.d_deck.push_back(new Malachite());
            } else if (i < 80) {
                reference.d_deck.push_back(new Turquoise());
            } else if (i < 90) {
                reference.d_deck.push_back(new Ruby());
            } else if (i < 98) {
                reference.d_deck.push_back(new Amethyst());
            } else {
                reference.d_deck.push_back(new Emerald());
            }
        }
        //TODO: Create a cardfactory
    }
    return d_factory;
}

Deck CardFactory::getDeck() {
    std::random_shuffle(d_deck.begin(), d_deck.end());
    return d_deck;
}
