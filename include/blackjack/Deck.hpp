#pragma once

#include <vector>
#include "Card.hpp"

class Deck {
public:
    Deck();

    void shuffle();
    Card draw();
    std::size_t size() const noexcept;

private:
    std::vector<Card> cards_; // Last card is the top of the deck
};