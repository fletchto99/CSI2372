#ifndef CSI2372_CHAIN_H
#define CSI2372_CHAIN_H

#include <vector>
#include "gemstones.h"
#include "cardfactory.h"

/**
 * Initialized the template Chain
 * d_cards vector
 */
template <class T>
class Chain {
private:
    std::vector<T> d_cards;
public:
    Chain<T>& operator+=(Card*);
    int sell();
    Chain();
};

#endif
