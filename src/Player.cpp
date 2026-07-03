#include "blackjack/Player.hpp"
#include "blackjack/Card.hpp"
#include "blackjack/Deck.hpp"

#include <ostream>

std::ostream &operator<<(std::ostream &os, const Player &p) {
  os << "Player { hand: " << p.getHand() << ", stats: " << p.getStats() << " }";
  return os;
}

void Player::addCard(const Card &card) { hand_.addCard(card); }

void Player::hit(Deck& deck) {
  const Card card = deck.draw();
  addCard(card);
}

std::uint8_t Player::getHandValue() const { return hand_.getScore(); }

const Hand &Player::getHand() const { return hand_; }
