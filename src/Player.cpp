#include "blackjack/Player.hpp"
#include "blackjack/Card.hpp"
#include "blackjack/Deck.hpp"

#include <ostream>
#include <stdexcept>

std::ostream &operator<<(std::ostream &os, const Player &p) {
  os << "Player { hand: " << p.getHand() << " }";
  return os;
}

void Player::hit(Deck &deck) { hand_.addCard(deck.draw()); }

void Player::addCard(Card card) { hand_.addCard(card); }

void Player::clearHand() { hand_.clear(); }

void Player::setChips(std::uint32_t amount) { chips_ = amount; }

void Player::addChips(std::uint32_t amount) { chips_ += amount; }

void Player::bet(std::uint32_t amount) {
  if (amount > chips_) { throw std::out_of_range("Not enough chips to bet"); }
  chips_ -= amount;
}

int Player::getHandValue() const { return hand_.getScore(); }

const Hand &Player::getHand() const { return hand_; }

std::uint32_t Player::getChips() const { return chips_; }
