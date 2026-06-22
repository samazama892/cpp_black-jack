#include "blackjack/Card.hpp"
#include "blackjack/Deck.hpp"
#include "blackjack/Hand.hpp"
#include "blackjack/Player.hpp"
#include "blackjack/Rank.hpp"
#include "blackjack/Suit.hpp"
#include <catch2/catch_all.hpp>

#include <sstream>

TEST_CASE("Hand scoring with aces", "[hand]") {
  Hand h;
  h.addCard(Card{Suit::Hearts, Rank::Ace});
  h.addCard(Card{Suit::Spades, Rank::Ten});
  REQUIRE(h.getScore() == 21);

  Hand h2;
  h2.addCard(Card{Suit::Clubs, Rank::Ace});
  h2.addCard(Card{Suit::Diamonds, Rank::Ace});
  REQUIRE(h2.getScore() == 12);

  Hand h3;
  h3.addCard(Card{Suit::Clubs, Rank::Ace});
  h3.addCard(Card{Suit::Diamonds, Rank::Nine});
  h3.addCard(Card{Suit::Hearts, Rank::Ace});
  REQUIRE(h3.getScore() == 21);
}

TEST_CASE("Hand operator<< prints cards", "[hand]") {
  Hand h;
  h.addCard(Card{Suit::Clubs, Rank::Two});
  h.addCard(Card{Suit::Hearts, Rank::King});
  std::ostringstream oss;
  oss << h;
  auto s = oss.str();
  REQUIRE(s.find("2") != std::string::npos);
  REQUIRE(s.find("K") != std::string::npos);
}

TEST_CASE("Player addCard and getHandValue", "[player]") {
  Player p;
  p.addCard(Card{Suit::Spades, Rank::Seven});
  p.addCard(Card{Suit::Hearts, Rank::Eight});
  REQUIRE(p.getHandValue() == 15);
}

TEST_CASE("Deck empties and throws", "[deck]") {
  Deck d;
  for (int i = 0; i < 52; ++i)
    d.draw();
  REQUIRE_THROWS_AS(d.draw(), std::runtime_error);
}
