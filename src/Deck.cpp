#include "blackjack/Deck.hpp"

#include <algorithm>
#include <random>
#include <stdexcept>
#include <cstdint>

Deck::Deck() {
  for (std::uint8_t suit = 0; suit < 4; ++suit) {
    for (std::uint8_t rank = 0; rank < 13; ++rank) {
      cards_.push_back(Card{static_cast<Suit>(suit), static_cast<Rank>(rank)});
    }
  }
}

void Deck::shuffle() {
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(cards_.begin(), cards_.end(), g);
}

std::size_t Deck::size() const noexcept { return cards_.size(); }

Card Deck::draw() {
  if (cards_.empty()) {
    throw std::runtime_error("Cannot draw from an empty deck");
  }
  Card card = cards_.back();
  cards_.pop_back();
  return card;
}
