#include "blackjack/Stats.hpp"

Stats::Stats() : wins(0), busts(0), pushes(0) {}

std::ostream &operator<<(std::ostream &os, const Stats &s) {
  os << "Stats { wins: " << s.wins << ", busts: " << s.busts << ", pushes: " << s.pushes << " }";
  return os;
}
