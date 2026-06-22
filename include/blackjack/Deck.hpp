#pragma once

#include <vector>
#include <cstddef>
#include "Card.hpp"

class Deck {
private:
    std::vector<Card> cards_; // Last card is the top of the deck
};

Deck::Deck();

void Deck::shuffle();
Card Deck::draw();
std::size_t Deck::size() const noexcept;
