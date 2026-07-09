#ifndef SUPERIDEN3_BLACKJACK_RANK_HPP
#define SUPERIDEN3_BLACKJACK_RANK_HPP

#include <ostream>

enum class Rank {
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
};

std::ostream &operator<<(std::ostream &os, const Rank &r);

#endif
