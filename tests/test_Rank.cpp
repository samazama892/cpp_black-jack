#include "blackjack/Rank.hpp"
#include <catch2/catch_all.hpp>

#include <sstream>

TEST_CASE("Rank prints correct symbols", "[rank]") {
  std::ostringstream oss;
  oss << Rank::Ace;
  REQUIRE(oss.str() == "A");

  oss.str(""), oss.clear();
  oss << Rank::Ten;
  REQUIRE(oss.str() == "10");

  oss.str(""), oss.clear();
  oss << Rank::Queen;
  REQUIRE(oss.str() == "Q");
}
