#include "players.h"

Player::Player(std::istream &, CardFactory *) {

}

Player::Player(std::string &name) {
 d_name = name;
}

std::string Player::getName() {
    return d_name;
}

int Player::getNumCoins() {
    return 0;
}

int Player::getMaxNumChains() {
    return 0;
}

Player &Player::operator+=(int coins) {
    d_coins += coins;
}

int Player::getNumChains() {
    return d_numChains;
}

chain &Player::operator[](int i) {
    return ;
}

void Player::buyThirdChain() {
chains.
}

void Player::printHand(std::ostream &, bool) {

}
