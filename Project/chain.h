#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <iostream>
#include "gemstones.h"
#include "cardfactory.h"

/**
 * The base class which our chain template is derived from
 */
class ChainBase;

/**
 * Initilizes the chain template by extending the abstract ChainBase class
 */
template<class T>
class Chain : ChainBase {
private:
    std::vector<T *> d_cards;
public:
    Chain<T> &operator+=(T *);

    int sell();

    Chain();
};

template<typename T>
Chain &Chain<T>::operator+=(T *type) {
    if (d_cards.front() != type) {
        throw new IllegalType("Not the same type");
    } else {
        d_cards.push_back(type);
    }
}

template<typename T>
int Chain<T>::sell() override {
    int numOfCards = d_cards.size();
    int numOfCoins = 0;
    return numOfCoins;
}

template<typename T>
Chain<T>::Chain() {

}

/**
 * An exception to be thrown when a card of an illegal type is added to a chain
 */
class IllegalType : public std::exception
{
private:
    std::string d_strError;
public:
    IllegalType(std::string _strError) : d_strError(_strError) {}

    std::string getError() { return d_strError; }
};


#endif
