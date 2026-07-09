#include "blackjack/Card.hpp"
#include "blackjack/Player.hpp"
#include "blackjack/Rank.hpp"
#include "blackjack/Suit.hpp"
#include <catch2/catch_all.hpp>

TEST_CASE("Card value mapping is correct", "[card]") {
  Card two{Suit::Clubs, Rank::Two};
  Card ten{Suit::Diamonds, Rank::Ten};
  Card jack{Suit::Hearts, Rank::Jack};
  Card ace{Suit::Spades, Rank::Ace};

  REQUIRE(two.getValue() == 2);
  REQUIRE(ten.getValue() == 10);
  REQUIRE(jack.getValue() == 10);
  REQUIRE(ace.getValue() == 11);
}

TEST_CASE("Card accessors return correct values", "[card]") {
  Card c{Suit::Hearts, Rank::Queen};
  REQUIRE(c.getSuit() == Suit::Hearts);
  REQUIRE(c.getRank() == Rank::Queen);
}

TEST_CASE("Card giveToPlayer adds card to player hand", "[card]") {
  Card c{Suit::Spades, Rank::Nine};
  Player p;
  c.giveToPlayer(p);
  REQUIRE(p.getHandValue() == 9);
}
