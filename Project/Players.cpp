#include "players.h"
#include "Chain.h"
#include "cardfactory.h"
#include <iostream>
using namespace std;

Player::Player(std::string &name) {
 d_name = name;
}

Player::Player(std::istream & is , std::string & _name) {
    //d_hand = new Hand(is, CardFactory::CardFactory _factory);
}

std::string Player::getName() {
    return d_name;
}

int Player::getNumCoins() {
    return d_coins;
}

int Player::getMaxNumChains() {
   if(d_numChains)
    return 2;
}

Player &Player::operator+=(int coins) {
    d_coins += coins;
}

int Player::getNumChains() {
    if(d_chains.empty()) {
        cout << "Your chains are empty" << endl;
        return 0;
    }
    return d_numChains;
}

Chain& Player::operator[](int i) {
    return d_chains.at(i);
}

void Player::buyThirdChain() {
   if(d_numChains != 3) {
       if (d_coins < 2) {
           throw NotEnoughCoins("You do not have enough coins");
       } else {
           d_coins = d_coins - 2;
           d_numChains++;
           // Chain chain (nullptr, nullptr);
       }
   } else {
       cout << "You already have 3 chains, and you are only allow to have a maximum of 3 chains." << endl;
   }
}

void Player::printHand(std::ostream & os, bool hand) {
    if(hand){
         d_hand.print(os);
    } else {
        os << d_hand.top() << endl;
    }
}

Hand *Player::getHand() {
    return &d_hand;
}

class NotEnoughCoins{
private:
    std::string d_strError;
public:
    NotEnoughCoins(std::string _strError) : d_strError(_strError){}
    std::string getError(){return d_strError;}
};