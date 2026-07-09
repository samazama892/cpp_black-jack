#include "blackjack/Game.hpp"

#include <iostream>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  StandardGame game;
  game.play();
  return 0;
}
