#include "gemstones.h"

int Quartz::getCoinsForCards(int cards) {
    if(cards >= 4 && cards < 6) {
        return 1;
    } else if (cards >= 6 && cards < 8) {
        return 2;
    } else if (cards >= 8 && cards < 10) {
        return 3;
    } else if (cards > 10) {
        return 4;
    }
    return 0;
}

string Quartz::getName() {
    return "Quartz";

}

void Quartz::print(std::ostream &out) {
    out << " Q " << endl;
}


int Hematite::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 9;
        default:
            return 0;
    }
}

string Hematite::getName() {
    return "Hematite";
}

void Hematite::print(std::ostream &out) {
    out << " H " << endl;
}

int Obsidian::getCardsPerCoin(int coins) {
    switch(coins) {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 8;
        default:
            return 0;
    }
}

string Obsidian::getName() {
    return "Obsidian";
}

void Obsidian::print(std::ostream &out) {
    out << " O " << endl;
}

int Malachite::getCardsPerCoin(int coins) {
    switch(coins) {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return 0;
    }
}

string Malachite::getName() {
    return "Malachite";
}

void Malachite::print(std::ostream &out) {
   out << " M " << endl;
}

int Turquoise::getCardsPerCoin(int coins) {
    switch(coins) {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return 0;
    }
}

string Turquoise::getName() {

    return "Turquoise";
}

void Turquoise::print(std::ostream &out) {
    out << " T " << endl;
}

int Ruby::getCardsPerCoin(int coins) {
    switch(coins){
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        default:
            return 0;
    }
}

string Ruby::getName() {
    return "Ruby";
}

void Ruby::print(std::ostream &out) {
    out << " R " << endl;
}

int Amethyst::getCardsPerCoin(int coins) {
    switch(coins){
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 0;
    }
}

string Amethyst::getName() {
    return "Amethyst";
}

void Amethyst::print(std::ostream &out) {
    out << " A " << endl;
}

int Emerald::getCardsPerCoin(int coins) {
    switch(coins){
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return -1;
        default:
            return 0;
    }
}

string Emerald::getName() {
    return "Emerald";
}

void Emerald::print(std::ostream &out) {
    out << " E " << endl;
}

