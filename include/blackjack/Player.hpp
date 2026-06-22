#pragma once

#include "blackjack/Hand.hpp"

#include <cstdint>
#include <ostream>

class Player {
private:
  Hand hand_;

public:
  friend std::ostream &operator<<(std::ostream &os, const Player &p);

  void addCard(const Card &card);
  uint8_t getHandValue() const;
  const Hand &getHand() const;
};
