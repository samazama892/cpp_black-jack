#include "Card.hpp"

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << c.rank << " of " << c.suit;
    return os;
}

