#include "blackjack/Suit.hpp"
#include <catch2/catch_all.hpp>

#include <sstream>

TEST_CASE("Suit prints correct symbols", "[suit]") {
  std::ostringstream oss;
  oss << Suit::Clubs;
  REQUIRE(oss.str() == "\u2663");

  oss.str(""), oss.clear();
  oss << Suit::Diamonds;
  REQUIRE(oss.str() == "\u2666");

  oss.str(""), oss.clear();
  oss << Suit::Hearts;
  REQUIRE(oss.str() == "\u2665");

  oss.str(""), oss.clear();
  oss << Suit::Spades;
  REQUIRE(oss.str() == "\u2660");
}
