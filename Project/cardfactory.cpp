#include "cardfactory.h"

CardFactory *CardFactory::getFactory() {
    if (d_factory == nullptr) {
        d_factory = new CardFactory();
    }
    return d_factory;
}

Deck CardFactory::getDeck() {
    std::random_shuffle(d_deck.begin(), d_deck.end());
    return d_deck;
}

CardFactory::~CardFactory() {

}

CardFactory::CardFactory() {
    for(size_t i = 0; i < 104; i++) {
        if (i < 20) {
            d_deck.push_back(new Quartz());
        } else if (i < 38) {
            d_deck.push_back(new Hematite());
        } else if (i < 54) {
            d_deck.push_back(new Obsidian());
        } else if (i < 68) {
            d_deck.push_back(new Malachite());
        } else if (i < 80) {
            d_deck.push_back(new Turquoise());
        } else if (i < 90) {
            d_deck.push_back(new Ruby());
        } else if (i < 98) {
            d_deck.push_back(new Amethyst());
        } else {
            d_deck.push_back(new Emerald());
        }
    }
}
