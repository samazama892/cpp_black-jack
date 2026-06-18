#include <algorithm>
#include <random>
#include <stdexcept>

#include "blackjack/Deck.hpp"

/* Create a standard deck of 52 cards */
Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            cards_.push_back(Card{static_cast<Suit>(suit), static_cast<Rank>(rank)});
        }
    }
}

/* Shuffle the deck using a random number generator */
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards_.begin(), cards_.end(), g);
}

std::size_t Deck::size() const noexcept {
    return cards_.size();
}

/* Draw a card from the top of the deck, removes it */
Card Deck::draw() {
    if (cards_.empty()) {
        throw std::runtime_error("Cannot draw from an empty deck");
    }
    Card card = cards_.back();
    cards_.pop_back();
    return card;
}