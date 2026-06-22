#pragma once

#include "blackjack/Rank.hpp"
#include "blackjack/Suit.hpp"

#include <cstdint>
#include <ostream>

struct Card {
  Suit suit;
  Rank rank;

  uint8_t getValue() const;
  const Rank &getRank() const;
  const Suit &getSuit() const;

  friend std::ostream &operator<<(std::ostream &os, const Card &c);
};
