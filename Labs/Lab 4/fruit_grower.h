// ==========================================================================
// $Id: fruit_grower.h,v 1.1 2016/10/10 20:41:56 jlang Exp $
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
// $Log: fruit_grower.h,v $
// Revision 1.1  2016/10/10 20:41:56  jlang
// Created Lab 4.
//
// ==========================================================================
#ifndef _FruitGrower_h_
#define _FruitGrower_h_

#include <string>
#include <random>
#include <chrono>
#include <vector>

using std::string;

class Grower;

/**
 * Fruit
 */
class Fruit {
    string d_type;
    int d_code = -1;
    std::vector<int> d_growers;
public:
    Fruit( const string& _type );
    void setCode(int _code);
    int getCode() const;
    // Adds a grower's id for this fruit or returns false if grower has no id
    bool addGrower(const Grower& _grower);
    // returns a reference to vector of grower ids
    const std::vector<int>& getGrowerIds();
    // prints d_code : d_type
    void print() const;
};

/**
 * Vegetable or fruit grower
 */
class Grower {
    string d_name;
    int d_code;
    std::vector<int> d_fruits;
public:
    Grower(const string& _type );
    void setCode(int _code);
    int getCode() const;
    // Adds a fruit's id for this grower or returns false if fruit has no id
    bool addFruit(const Fruit& _fruit);
    // returns a reference to vector of fruit ids
    const std::vector<int>& getFruitIds();
    // prints d_code : d_name
    void print() const;
};


/**
 * Class that manages ids for fruit and growers
 */
class IdManager {
private:
    std::mt19937 d_generator;
    std::uniform_int_distribution<int> d_distribution;

    std::vector<int> d_fruitIds;
    std::vector<int> d_growerIds;
public:
    // Default constructor to seed random number generator
    inline IdManager();
    // Produces random number - will not be unique
    inline int getRandomId();
    // Assigns an unique Id from 0..49 for the fruit and sets it in _fruit
    int assignFruitId(Fruit& _fruit);
    // Assigns an unique Id from 50..99 for the grower and sets it in _grower
    int assignGrowerId(Grower& _grower);
};

IdManager::IdManager() : d_distribution(0,99) {
    // seed random number generator with time for changing sequences
    auto t = std::chrono::system_clock::now(); // get current time
    auto s = static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(t.time_since_epoch()).count());
    d_generator.seed(s);
}

/**
 * Return the next random number
 */
int IdManager::getRandomId() {
    return d_distribution(d_generator);
}


#endif