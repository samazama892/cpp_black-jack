#include "blackjack/Suit.hpp"

#include <iostream>

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
    std::cerr << "Unknown suit encountered in operator<<: "
              << static_cast<int>(s) << std::endl;
    return os << "?";
  }
}
