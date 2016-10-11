#include <iostream>

#include "fruit_grower.h"

using namespace std;


Fruit::Fruit(const string &_type) {
    d_type = _type;
}

void Fruit::setCode(int _code) {
    d_code = _code;
}

int Fruit::getCode() const {
    return d_code;
}

bool Fruit::addGrower(const Grower &_grower) {
    if (_grower.getCode() > 0) {
        d_growers.push_back(_grower.getCode());
        return true;
    }
    return false;
}

const std::vector<int> &Fruit::getGrowerIds() {
    return d_growers;
}

void Fruit::print() const {
    cout << d_code << " : " << d_type << endl;
}

Grower::Grower(const string &_type) {
    d_name = _type;
}

void Grower::setCode(int _code) {
    d_code = _code;
}

int Grower::getCode() const {
    return d_code;
}

bool Grower::addFruit(const Fruit &_fruit) {
    if (_fruit.getCode() > 0) {
        d_fruits.push_back(_fruit.getCode());
        return true;
    }
    return false;
}

const std::vector<int> &Grower::getFruitIds() {
    return d_fruits;
}

void Grower::print() const {
    cout << d_code << " : " << d_name << endl;
}

int IdManager::assignFruitId(Fruit &_fruit) {
    int randomNumber = IdManager::getRandomId();
    while (find(d_fruitIds.begin(), d_fruitIds.end(), randomNumber) != d_fruitIds.end() || randomNumber < 0 || randomNumber > 49) {
        randomNumber = IdManager::getRandomId();
    }
    d_fruitIds.push_back(randomNumber);
    _fruit.setCode(randomNumber);
    return randomNumber;
}

int IdManager::assignGrowerId(Grower &_grower) {
    int randomNumber = IdManager::getRandomId();
    while (find(d_growerIds.begin(), d_growerIds.end(), randomNumber) != d_growerIds.end() || randomNumber > 100 || randomNumber < 49) {
        randomNumber = IdManager::getRandomId();
    }
    d_growerIds.push_back(randomNumber);
    _grower.setCode(randomNumber);
    return randomNumber;
}