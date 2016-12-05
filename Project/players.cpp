#include "players.h"
#include "Chain.h"
#include <iostream>

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
        std::cout << "Your chains are empty" << std::endl;
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
       std::cout << "You already have 3 chains, and you are only allow to have a maximum of 3 chains." << std::endl;
   }
}

void Player::printHand(std::ostream & out, bool hand) {

    if(hand){
         out << "Player's hand:" << std::endl;
         d_hand.print(out);
    } else {
        out << "Player's top card: ";
        out << d_hand.top() << std::endl;
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