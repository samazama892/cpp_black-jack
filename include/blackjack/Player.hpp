#pragma once

#include "blackjack/Hand.hpp"

#include "blackjack/Card.hpp"

#include <cstdint>
#include <ostream>
#include <string>

class Deck;

class Player {
private:
  Hand hand_;

public:
  friend std::ostream &operator<<(std::ostream &os, const Player &p);

  void addCard(const Card &card);
  void hit(Deck& deck);
  uint8_t getHandValue() const;
  const Hand &getHand() const;
};
