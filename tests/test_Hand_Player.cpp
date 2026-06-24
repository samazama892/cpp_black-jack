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

TEST_CASE("Player hit reduces deck size and adds a card", "[player]") {
  Player p;
  Deck d;
  const auto startSize = d.size();

  p.hit(d);

  REQUIRE(d.size() == startSize - 1);
  REQUIRE(p.getHandValue() > 0);
}

TEST_CASE("Player operator<< contains name and hand", "[player]") {
  Player p;
  p.addCard(Card{Suit::Clubs, Rank::Four});
  std::ostringstream oss;
  oss << p;
  const auto s = oss.str();

  REQUIRE(s.find("Player") != std::string::npos);
  REQUIRE(s.find("4") != std::string::npos);
}

TEST_CASE("Clearing hand resets score and removes cards", "[hand]") {
  Hand h;
  h.addCard(Card{Suit::Diamonds, Rank::Queen});
  h.addCard(Card{Suit::Hearts, Rank::Ace});
  REQUIRE(h.getScore() > 0);

  h.clear();

  REQUIRE(h.getCards().empty());
  REQUIRE(h.getScore() == 0);
}

TEST_CASE("Hand handles multiple aces with a bust risk", "[hand]") {
  Hand h;
  h.addCard(Card{Suit::Clubs, Rank::Ace});
  h.addCard(Card{Suit::Diamonds, Rank::Ace});
  h.addCard(Card{Suit::Spades, Rank::King});
  h.addCard(Card{Suit::Hearts, Rank::Nine});

  REQUIRE(h.getScore() == 21);
}

TEST_CASE("Deck empties and throws", "[deck]") {
  Deck d;
  for (int i = 0; i < 52; ++i)
    d.draw();
  REQUIRE_THROWS_AS(d.draw(), std::runtime_error);
}
