#pragma once

#include "Hand.hpp"

#include <ostream>

class Player {
private:
    Hand hand_;
};

friend std::ostream& operator<<(std::ostream& os, const Player& p);

void Player::addCard(const Card& card);
uint8_t Player::getHandValue() const;
const Hand& Player::getHand() const;
