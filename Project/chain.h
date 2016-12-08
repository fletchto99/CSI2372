#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <iostream>

#include "cardfactory.h"

/**
 * An exception to be thrown when a card of an illegal type is added to a chain
 */
class IllegalType : public std::exception {
private:
    std::string d_strError;
public:
    IllegalType(std::string _strError) : d_strError(_strError) {}

    std::string getError() {
        return d_strError;
    }
};

/**
 * Initilizes the chain template by extending the abstract ChainBase class
 */
template<class T>
class Chain {
private:
    std::vector<T *> d_cards;
public:
    Chain<T> &operator+=(T *);

    int sell();

    Chain();

    friend std::ostream& operator << (std::ostream& out, const T& card){
        if(typeid(card) == typeid(Card)){
            ((Card)card).print(out);
        }
        return out;
    }

    T* peek();

    int length();
};



template<typename T>
Chain<T> &Chain<T>::operator+=(T *type) {
    if (d_cards.front() != type) {
        throw new IllegalType("Not the same type");
    } else {
        d_cards.push_back(type);
    }
    return *this;
}

template<typename T>
int Chain<T>::sell() {
    int numOfCoins = 0;
    if(typeid(peek()) == typeid(Card)) {
        numOfCoins = ((Card*)peek())->getCoinsForCards(length());
    }

    return numOfCoins;
}

template<typename T>
T* Chain<T>::peek() {
    return d_cards.front();
}

template<typename T>
int Chain<T>::length() {
    return sizeof(d_cards) / sizeof(T);
}

template<typename T>
Chain<T>::Chain() {

}

#endif
