#include "Rank.hpp"

#include <ostream>

friend std::ostream& operator<<(std::ostream& os, const Rank& r) {
    switch (r) {
        case Rank::Ace:
            return os << "A";
        case Rank::Two:
            return os << "2";
        case Rank::Three:
            return os << "3";
        case Rank::Four:
            return os << "4";
        case Rank::Five:
            return os << "5";
        case Rank::Six:
            return os << "6";
        case Rank::Seven:
            return os << "7";
        case Rank::Eight:
            return os << "8";
        case Rank::Nine:
            return os << "9";
        case Rank::Ten:
            return os << "10";
        case Rank::Jack:
            return os << "J";
        case Rank::Queen:
            return os << "Q";
        case Rank::King:
            return os << "K";
    }
}
