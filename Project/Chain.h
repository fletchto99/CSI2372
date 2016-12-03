#ifndef CSI2372_CHAIN_H
#define CSI2372_CHAIN_H

#include <vector>
#include <iostream>
#include "gemstones.h"
#include "cardfactory.h"

using namespace std;


class ChainBase {
public:
    virtual Chain& operator+=(Card*) = 0;
    virtual int sell() = 0;
    friend ostream& operator << (ostream& out, ChainBase& const chainBase) {
        return out;
    }
};

/**
 * Initialized the template Chain
 * d_cards vector
 */
template <class T> class Chain : ChainBase {
private:
    std::vector<T*> d_cards;
public:
    Chain<T>& operator+=(T*);
    int sell();
    Chain();
};
template <typename T>
Chain &Chain::operator+=(T * type) {
   if(d_cards.front() != type){
       throw new IllegalType("Not the same type");
   } else {
       d_cards.push_back(type);
   }
}
template <typename T>
int Chain::sell() override {
    int numOfCards = d_cards.size();
    int numOfCoins = 0;
    return numOfCoins;
}
template <typename T>
Chain::Chain() {

}

class IllegalType //: public exception
{
private:
    std::string d_strError;
public:
    IllegalType(std::string _strError) : d_strError(_strError){}
    std::string getError(){return d_strError;}
};


#endif
