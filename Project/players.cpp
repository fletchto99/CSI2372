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
    //d_hand = new Hand(is, CardFactory::CardFactory _factory);
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

Chain<ChainBase> &Player::operator[](int i) {
    return (Chain<ChainBase> &) d_chains.at(i);
}

void Player::buyThirdChain() {
    if (d_numChains != 3) {
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

void Player::printHand(std::ostream &out, bool hand) {

    if (hand) {
        out << "Player's hand:" << std::endl;
        d_hand->print(out);
    } else {
        out << "Player's top card: ";
        out << d_hand->top() << std::endl;
    }
}

Hand *Player::getHand() {
    return d_hand;
}