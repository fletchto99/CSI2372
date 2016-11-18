//
// Created by Matt Langlois on 2016-11-16.
//

#ifndef CSI2372_GEMSTONES_H
#define CSI2372_GEMSTONES_H

#include <string>

using namespace std;

class Card {
    virtual int getCardsPerCoin(int coins) = 0;
    virtual string getName() = 0;
    virtual void print(const ostream& out) = 0;
};

class Quartz : public Card {

    int getCardsPerCoin(int coins) {
        switch(coins) {
            case 1:
                return 4;
            case 2:
                return 6;
            case 3:
                return 8;
            case 4:
                return 10;
            default:
                return -1; //TODO: return illegal argument error
        }
    }

};

class Hematite : public Card {

    int getCardsPerCoin(int coins) {
        switch(coins) {
            case 1:
                return 3;
            case 2:
                return 6;
            case 3:
                return 8;
            case 4:
                return 9;
            default:
                return -1; //TODO: return illegal argument error
        }
    }

};

class Obsidian : public Card {

    int getCardsPerCoin(int coins) {
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
                return -1; //TODO: return illegal argument error
        }
    }

};

class Malachite : public Card {

    int getCardsPerCoin(int coins) {
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
                return -1; //TODO: return illegal argument error
        }
    }

};

class Turquoise : public Card {

    int getCardsPerCoin(int coins) {
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
                return -1; //TODO: return illegal argument error
        }
    }
};

class Ruby : public Card {
    int getCardsPerCoin(int coins){
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
                return -1; //TODO: return illegal argument error
        }
    }
    string getName(){
        return "Ruby";
    }
};

class Amethyst : public Card {
    int getCardsPerCoin(int coins){
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
                return -1; //TODO: return illegal argument error
        }
    }

    string getName(){
        return "Amethyst";
    }
};

class Emerald : public Card {
    int getCardsPerCoin(int coins){
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
                return -1; //TODO: return illegal argument error
        }
    }

    string getName(){
        return "Emerald";
    }
};


#endif //CSI2372_GEMSTONES_H
