#ifndef SUPERIDEN3_BLACKJACK_STATS_HPP
#define SUPERIDEN3_BLACKJACK_STATS_HPP

#include <cstdint>

struct Stats {
  std::uint32_t wins;
  std::uint32_t busts;
  std::uint32_t pushes;

  Stats();
};

#endif
