#ifndef SUPERIDEN3_BLACKJACK_GAME_HPP
#define SUPERIDEN3_BLACKJACK_GAME_HPP

#include "blackjack/Player.hpp"
#include "blackjack/Deck.hpp"

#include <ostream>

class Game {
public:
  Game() {}

  void play();

  friend std::ostream &operator<<(std::ostream &os, const Game &g);

private:
  Player player_;
  Player dealer_;
  Deck deck_;
}

#endif
