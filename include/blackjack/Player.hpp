#ifndef SUPERIDEN3_BLACKJACK_PLAYER_HPP
#define SUPERIDEN3_BLACKJACK_PLAYER_HPP

#include "blackjack/Hand.hpp"
#include "blackjack/Stats.hpp"

#include "blackjack/Card.hpp"

#include <cstdint>
#include <ostream>
#include <string>

class Deck;

class Player {
private:
  Hand hand_;
  // Stats stats_;
  std::uint32_t chips_;

public:
  friend std::ostream &operator<<(std::ostream &os, const Player &p);

  void hit(Deck &deck);
  void addCard(Card card);
  void clearHand();
  void setChips(std::uint32_t amount);
  void addChips(std::uint32_t amount);

  void bet(std::uint32_t amount);

  int getHandValue() const;
  const Hand &getHand() const;
  // const Stats &getStats() const;
  std::uint32_t getChips() const;

  bool hasBlackJack() const;
};

#endif
