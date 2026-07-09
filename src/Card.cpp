#include "blackjack/Card.hpp"
#include "blackjack/Player.hpp"

#include <cstdint>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Card &c) {
  os << c.rank << c.suit;
  return os;
}

std::uint8_t Card::getValue() const {
  switch (rank) {
  case Rank::Two:
    return 2;
  case Rank::Three:
    return 3;
  case Rank::Four:
    return 4;
  case Rank::Five:
    return 5;
  case Rank::Six:
    return 6;
  case Rank::Seven:
    return 7;
  case Rank::Eight:
    return 8;
  case Rank::Nine:
    return 9;
  case Rank::Ten:
  case Rank::Jack:
  case Rank::Queen:
  case Rank::King:
    return 10;
  case Rank::Ace:
    return 11; // Initially treat Ace as 11, will adjust in Hand if needed
  }
  return 0; // Should never reach here
}

const Rank &Card::getRank() const { return rank; }

const Suit &Card::getSuit() const { return suit; }

void Card::giveToPlayer(Player &player) const { player.addCard(*this); }
