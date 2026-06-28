#ifndef SUPERIDEN3_BLACKJACK_DECK_HPP
#define SUPERIDEN3_BLACKJACK_DECK_HPP

#include "blackjack/Card.hpp"

#include <cstddef>
#include <vector>

class Deck {
private:
  std::vector<Card> cards_; // Last card is the top of the deck

public:
  /* Create a standard deck of 52 cards */
  Deck();

  /* Shuffle the deck using a random number generator */
  void shuffle();
  /* Draw a card from the top of the deck, removes it */
  Card draw();
  std::size_t size() const noexcept;
};

#endif
