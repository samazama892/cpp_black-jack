#ifndef SUPERIDEN3_BLACKJACK_PLAYER_HPP
#define SUPERIDEN3_BLACKJACK_PLAYER_HPP

#include "blackjack/Hand.hpp"
#include "blackjack/Stats.hpp"

#include "blackjack/Card.hpp"

#include <cstdint>
#include <ostream>
#include <string>

class Deck;

class Player {
private:
  Hand hand_;
  Stats stats_;

public:
  friend std::ostream &operator<<(std::ostream &os, const Player &p);

  void addCard(const Card &card);
  void hit(Deck& deck);

  std::uint8_t getHandValue() const;
  const Hand &getHand() const;
  const Stats &getStats() const;
};

#endif
