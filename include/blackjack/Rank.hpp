#pragma once

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
