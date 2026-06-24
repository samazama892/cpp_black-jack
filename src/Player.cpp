#include "blackjack/Player.hpp"
#include "blackjack/Card.hpp"

#include <ostream>

std::ostream &operator<<(std::ostream &os, const Player &p) {
  os << "Player { name: " << p.getName() << ", hand: " << p.getHand() << " }";
  return os;
}

void Player::addCard(const Card &card) { hand_.addCard(card); }

void Player::hit(const Deck& deck) { hand_.hit(deck); }

uint8_t Player::getHandValue() const { return hand_.getScore(); }

const Hand &Player::getHand() const { return hand_; }

const std::string& Player::getName() const {
  return name_;
}
