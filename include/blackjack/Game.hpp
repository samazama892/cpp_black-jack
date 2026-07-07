#ifndef SUPERIDEN3_BLACKJACK_GAME_HPP
#define SUPERIDEN3_BLACKJACK_GAME_HPP

#include "blackjack/Player.hpp"
#include "blackjack/Deck.hpp"

#include <ostream>
#include <cstdint>
#include <vector>

enum class RoundResolution {
  PlayerWins,
  DealerWins,
  Push,
};

class StandardGame {
public:
  static constexpr int MIN_BET_AMOUNT = 2;
  static constexpr int MAX_BET_AMOUNT = 10;
  static constexpr int CHIPS_PER_PERSON = MAX_BET_AMOUNT * 10;

  StandardGame() {}

  void play();
  static bool canSplit(const Hand &hand);
  static RoundResolution resolveRoundOutcome(bool playerBusted, bool dealerBusted, int playerScore, int dealerScore);

  friend std::ostream &operator<<(std::ostream &os, const StandardGame &g);

private:
  struct HandState {
    Player player;
    std::uint32_t bet_amount = 0;
    bool busted = false;
  };

  bool handleInsurance(std::uint32_t bet_amount);
  void playHand(Player &bankroll, Player &player, const Player &dealer, Deck &deck, std::uint32_t &bet_amount, bool &busted);
  void playSplitHands(Player &bankroll, Player &dealer, Deck &deck, std::vector<HandState> &hands);
  void playDealerTurn(Player &dealer, Deck &deck);
  void settleHand(Player &bankroll, const Player &hand_player, const Player &dealer, std::uint32_t bet_amount, bool busted);

  Player player_;
  Player dealer_;
  Deck deck_;
  Card hole_card;
};

#endif
