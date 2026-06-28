#ifndef SUPERIDEN3_BLACKJACK_HAND_HPP
#define SUPERIDEN3_BLACKJACK_HAND_HPP

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
  void clear();
  std::uint8_t getScore() const;
  const std::vector<Card> &getCards() const;
};

#endif
