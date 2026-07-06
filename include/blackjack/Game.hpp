#ifndef SUPERIDEN3_BLACKJACK_GAME_HPP
#define SUPERIDEN3_BLACKJACK_GAME_HPP

#include "blackjack/Player.hpp"
#include "blackjack/Deck.hpp"

#include <ostream>
#include <cstdint>

class StandardGame {
public:
  static constexpr int MIN_BET_AMOUNT = 2;
  static constexpr int MAX_BET_AMOUNT = 10;
  static constexpr int CHIPS_PER_PERSON = MAX_BET_AMOUNT * 10;

  StandardGame() {}

  void play();

  friend std::ostream &operator<<(std::ostream &os, const StandardGame &g);

private:
  Player player_;
  Player dealer_;
  Deck deck_;
  Card hole_card;
};

#endif
