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
class chain {
private:
    std::vector<T> d_cards;
public:
    chain<T>& operator+=(Card*);
    int sell();
    chain (std::istream&, CardFactory*);
};

#endif
