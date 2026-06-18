#pragma once

#include "Suit.hpp"
#include "Rank.hpp"

struct Card {
    Suit suit;
    Rank rank;

    friend std::ostream& operator<<(std::ostream& os, const Card& c);
};
