#pragma once

#include "blackjack/Hand.hpp"

#include "blackjack/Card.hpp"

#include <cstdint>
#include <ostream>
#include <string>

class Player {
private:
  Hand hand_;
  std::string name_;

public:
  friend std::ostream &operator<<(std::ostream &os, const Player &p);

  const std::string& getName() const;
  void addCard(const Card &card);
  void hit(const Deck& deck);
  uint8_t getHandValue() const;
  const Hand &getHand() const;
};
