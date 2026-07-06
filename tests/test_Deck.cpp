#include "blackjack/Deck.hpp"
#include "blackjack/Rank.hpp"
#include "blackjack/Suit.hpp"
#include <catch2/catch_all.hpp>
#include <set>

TEST_CASE("Deck starts with 52 cards", "[deck]") {
  Deck d;
  REQUIRE(d.size() == 52);
}

TEST_CASE("Drawing reduces size and returns a card", "[deck]") {
  Deck d;
  auto c = d.draw();

  REQUIRE(d.size() == 51);
  REQUIRE(static_cast<int>(c.rank) >= static_cast<int>(Rank::Ace));
  REQUIRE(static_cast<int>(c.rank) <= static_cast<int>(Rank::King));
  REQUIRE(static_cast<int>(c.suit) >= static_cast<int>(Suit::Clubs));
  REQUIRE(static_cast<int>(c.suit) <= static_cast<int>(Suit::Spades));
}

TEST_CASE("Deck reshuffles from the discard pile when empty", "[deck]") {
  Deck d;
  for (int i = 0; i < 52; ++i) {
    d.draw();
  }

  REQUIRE(d.size() == 0);

  auto c = d.draw();

  REQUIRE(d.size() == 51);
  REQUIRE(static_cast<int>(c.rank) >= static_cast<int>(Rank::Ace));
  REQUIRE(static_cast<int>(c.rank) <= static_cast<int>(Rank::King));
  REQUIRE(static_cast<int>(c.suit) >= static_cast<int>(Suit::Clubs));
  REQUIRE(static_cast<int>(c.suit) <= static_cast<int>(Suit::Spades));
}