// ==========================================================================
// $Id: main_skel.cpp,v 1.1 2016/10/10 20:41:56 jlang Exp $
// CSI2372 Lab Assignment 4 2016
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada.
//   http://www.eecs.uottawa.ca
//
// Creator: jlang (Jochen Lang)
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: main_skel.cpp,v $
// Revision 1.1  2016/10/10 20:41:56  jlang
// Created Lab 4.
//
// ==========================================================================
#include <iostream>
#include <string>
#include <array>

#include "fruit_grower.h"

using std::cout;
using std::cerr;
using std::endl;


class RandBool {
    std::mt19937 d_generator;
    std::bernoulli_distribution d_distribution;

public:
    RandBool() : d_distribution(0.25) {
        std::random_device rd;
        d_generator.seed(rd());
    }

    bool get() {
        return d_distribution( d_generator );
    }
};


int main() {
    // Array of fruit
    std::array<Fruit,10> fruits{ Fruit{"apple"},
                                 Fruit{"pear"},
                                 Fruit{"pineapple"},
                                 Fruit{"mango"},
                                 Fruit{"kiwi"},
                                 Fruit{"grape"},
                                 Fruit{"banana"},
                                 Fruit{"peach"},
                                 Fruit{"nectarine"},
                                 Fruit{"plum"},
    };
    // Array of growers
    std::array<Grower,3> growers{ Grower{"Smith"},
                                  Grower{"Green Thumb"},
                                  Grower{"Fowering Gardens"}
    };
    IdManager idm;
    RandBool rb;

    for(size_t i = 0; i < 10; i++) {
        idm.assignFruitId(fruits[i]);
    }

    for (size_t i = 0; i < 3; i++) {
        idm.assignGrowerId(growers[i]);
    }

    for(size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (rb.get()) {
                fruits[i].addGrower(growers[j]);
                growers[j].addFruit(fruits[i]);
            }
        }
    }

    for(size_t i = 0; i < 10; i++) {
        fruits[i].print();
        cout << "------------------------" << endl;
        for(int j : fruits[i].getGrowerIds()) {
            for (size_t k = 0; k < 3; k++) {
                if (growers[k].getCode() == j) {
                    cout << "    ";
                    growers[k].print();
                }
            }
        }
        cout << "========================" << endl;
    }

    for(size_t i = 0; i < 3; i++) {
        growers[i].print();
        cout << "------------------------" << endl;
        for(int j : growers[i].getFruitIds()) {
            for (size_t k = 0; k < 10; k++) {
                if (fruits[k].getCode() == j) {
                    cout << "    ";
                    fruits[k].print();
                }
            }
        }
        cout << "========================" << endl;
    }



    return 0;
}