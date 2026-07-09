#include "blackjack/Hand.hpp"

#include "blackjack/Deck.hpp"

#include <cstdint>
#include <ostream>
#include <vector>

std::ostream &operator<<(std::ostream &os, const Hand &h) {
  const std::vector<Card> &cards = h.getCards();
  os << "Hand { ";
  for (const auto &card : cards) {
    // Add a comma before all cards except the first and last one
    if (&card != &cards.front()) { os << ", "; }
    os << card;
  }
  os << " }";
  return os;
}

void Hand::addCard(Card card) { cards_.push_back(card); }

void Hand::clear() { cards_.clear(); }

int Hand::getScore() const {
  int value = 0;
  int numAces = 0; // Since Aces can be worth 1 or 11 in order to achieve the best possible hand, we need to track how many we have

  for (const auto &card : cards_) {
    value += card.getValue();
    if (card.getRank() == Rank::Ace) { numAces++; }
  }

  while (value > 21 && numAces > 0) {
    value -= 10;
    numAces--;
  }

  return value;
}

const std::vector<Card> &Hand::getCards() const { return cards_; }

bool Hand::hasBlackjack() const { return getScore() == 21 && cards_.size() == 2; }
