#include "blackjack/Deck.hpp"
#include "blackjack/Player.hpp"
#include "blackjack/Rank.hpp"
#include "blackjack/Suit.hpp"
#include <catch2/catch_all.hpp>

#include <sstream>

TEST_CASE("Player starts with empty hand value", "[player]") {
  Player p;
  REQUIRE(p.getHandValue() == 0);
  REQUIRE(p.getHand().getCards().empty());
}

TEST_CASE("Player hit modifies hand and deck", "[player]") {
  Player p;
  Deck d;
  const auto initial = d.size();
  p.hit(d);
  REQUIRE(p.getHand().getCards().size() == 1);
  REQUIRE(d.size() == initial - 1);
}

TEST_CASE("Player output contains name and card", "[player]") {
  Player p;
  p.addCard(Card{Suit::Diamonds, Rank::Three});
  std::ostringstream oss;
  oss << p;
  REQUIRE(oss.str().find("Player") != std::string::npos);
  REQUIRE(oss.str().find("3") != std::string::npos);
}
