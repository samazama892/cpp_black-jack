#pragma once

#include "blackjack/Card.hpp"

#include <cstdint>
#include <ostream>
#include <vector>

class Hand {
private:
  std::vector<Card> cards_;

public:
  friend std::ostream &operator<<(std::ostream &os, const Hand &h);

  void addCard(const Card &card);
  uint8_t getScore() const;
  const std::vector<Card> &getCards() const;
};
