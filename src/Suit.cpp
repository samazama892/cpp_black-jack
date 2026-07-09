#include "blackjack/Suit.hpp"

#include <iostream>
#include <stdexcept>

std::ostream &operator<<(std::ostream &os, const Suit &s) {
  switch (s) {
  case Suit::Clubs:
    return os << "\u2663";
  case Suit::Diamonds:
    return os << "\u2666";
  case Suit::Hearts:
    return os << "\u2665";
  case Suit::Spades:
    return os << "\u2660";
  default:
    throw std::invalid_argument("Invalid suit: " + std::to_string(static_cast<int>(s)));
  }
}
