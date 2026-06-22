#pragma once

#include <ostream>

enum class Suit { Clubs, Diamonds, Hearts, Spades };

std::ostream &operator<<(std::ostream &os, const Suit &s);
