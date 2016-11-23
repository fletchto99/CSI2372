#include "players.h"
#include "Chain.h"
#include <exception>
#include <iostream>
using namespace std;

Player::Player(std::istream &, CardFactory *) {

}

Player::Player(std::string &name) {
 d_name = name;
}

std::string Player::getName() {
    return d_name;
}

int Player::getNumCoins() {
    return d_coins;
}

int Player::getMaxNumChains() {
    return 2;
}

Player &Player::operator+=(int coins) {
    d_coins += coins;
}

int Player::getNumChains() {
    if(d_numChains != 0) {
        return d_numChains;
    }
}

Chain& Player::operator[](int i) {

}

void Player::buyThirdChain() {
    if(d_coins < 2){
        throw NotEnoughCoins("You do not have enough coins");
    } else {
        d_coins = d_coins - 2;
      // Chain chain (nullptr, nullptr);
    }
}

void Player::printHand(std::ostream &, bool everybody) {

    if(everybody == true){
        cout << "everybodies hand" << endl;
    } else {
        cout << "players hand" << endl;
    }
}

class NotEnoughCoins{
private:
    std::string d_strError;
public:
    NotEnoughCoins(std::string _strError) : d_strError(_strError){}
    std::string getError(){return d_strError;}
};