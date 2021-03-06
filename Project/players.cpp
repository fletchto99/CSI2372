#include "players.h"

class NotEnoughCoins {
private:
    std::string d_strError;
public:
    NotEnoughCoins(std::string _strError) : d_strError(_strError) {}

    std::string getError() {
        return d_strError;
    }
};

Player::Player(std::istream &is, std::string &_name) {
    d_hand = new Hand(is, CardFactory::getFactory(is));
    d_name = _name;
}

std::string Player::getName() {
    return d_name;
}

int Player::getNumCoins() {
    return d_coins;
}

int Player::getMaxNumChains() {
    return d_numChains;
}

Player &Player::operator+=(int coins) {
    d_coins += coins;
    return *this;
}

int Player::getNumChains() {
    if (d_chains.empty()) {
        return 0;
    }
    return sizeof(d_chains);
}

Chain<Card*> *Player::operator[](int i) {
    return d_chains.at(i);
}

void Player::buyThirdChain() {
    if (d_numChains < 3) {
        if (d_coins < 3) {
            throw NotEnoughCoins("You do not have enough coins");
        } else {
            d_coins = d_coins - 3;
            d_numChains++;
        }
    } else {
        std::cout << "You already have 3 chains, and you are only allow to have a maximum of 3 chains." << std::endl;
    }
}

void Player::printHand(std::ostream &out, bool hand) {

    if (hand) {
        out << "Player's hand:" << std::endl;
        d_hand->print(out);
    } else {
        out << "Player's top card: ";
        (d_hand->top())->print(out);
    }
}

Hand *Player::getHand() {
    return d_hand;
}

void Player::sellChain(Chain<Card*> *chain) {
    this->operator+=(chain->sell());
    d_chains.erase(std::remove(d_chains.begin(), d_chains.end(), chain), d_chains.end());
}

void Player::addChain(Chain<Card*> *chain) {
    if (getNumChains() < d_numChains) {
        d_chains.push_back(chain);
    } else {
        std::cout << "You already reached your limit for chains!";
    }
}