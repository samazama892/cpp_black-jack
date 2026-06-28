#ifndef SUPERIDEN3_BLACKJACK_SUIT_HPP
#define SUPERIDEN3_BLACKJACK_SUIT_HPP

#include <ostream>

enum class Suit { Clubs, Diamonds, Hearts, Spades };

std::ostream &operator<<(std::ostream &os, const Suit &s);

#endif
