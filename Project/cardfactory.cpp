#include <fstream>
#include "cardfactory.h"
#include "deck.h"


CardFactory *CardFactory::getFactory() {
    if (d_factory == nullptr) {
        std::ifstream ignore;
        d_factory = new CardFactory(ignore);
    }
    return d_factory;
}

CardFactory *CardFactory::getFactory(std::istream &input) {
    if (d_factory == nullptr) {
        d_factory = new CardFactory(input);
    }
    return d_factory;
}

Deck CardFactory::getDeck() {
    std::random_shuffle(d_deck->begin(), d_deck->end());
    return *d_deck;
}

CardFactory::~CardFactory() {

}

CardFactory::CardFactory(std::istream &input) {
    if (d_deck == NULL) {
        d_deck = new Deck(input, getFactory());
    }
    if (d_deck->empty()) {
        for (size_t i = 0; i < 104; i++) {
            if (i < 20) {
                d_deck->push_back(new Quartz());
            } else if (i < 38) {
                d_deck->push_back(new Hematite());
            } else if (i < 54) {
                d_deck->push_back(new Obsidian());
            } else if (i < 68) {
                d_deck->push_back(new Malachite());
            } else if (i < 80) {
                d_deck->push_back(new Turquoise());
            } else if (i < 90) {
                d_deck->push_back(new Ruby());
            } else if (i < 98) {
                d_deck->push_back(new Amethyst());
            } else {
                d_deck->push_back(new Emerald());
            }
        }
    }
}
