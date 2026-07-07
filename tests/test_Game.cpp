#include "blackjack/Game.hpp"
#include <catch2/catch_all.hpp>

TEST_CASE("Pairs of equal-value cards can be split", "[game]") {
  Hand hand;
  hand.addCard(Card{Suit::Spades, Rank::Eight});
  hand.addCard(Card{Suit::Spades, Rank::Eight});

  REQUIRE(StandardGame::canSplit(hand));
}

TEST_CASE("Non-pairs cannot be split", "[game]") {
  Hand hand;
  hand.addCard(Card{Suit::Spades, Rank::Eight});
  hand.addCard(Card{Suit::Hearts, Rank::Nine});

  REQUIRE_FALSE(StandardGame::canSplit(hand));
}

TEST_CASE("Busted player does not receive a win payout", "[game]") {
  REQUIRE(StandardGame::resolveRoundOutcome(true, false, 23, 18) == RoundResolution::DealerWins);
}

TEST_CASE("Dealer bust gives the player a win", "[game]") {
  REQUIRE(StandardGame::resolveRoundOutcome(false, true, 20, 25) == RoundResolution::PlayerWins);
}

TEST_CASE("Matching totals resolve as a push", "[game]") {
  REQUIRE(StandardGame::resolveRoundOutcome(false, false, 20, 20) == RoundResolution::Push);
}
