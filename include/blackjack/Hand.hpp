#pragma once

#include "Card.hpp"

#include <vector>
#include <cstdint>
#include <ostream>

class Hand {
private:
    std::vector<Card> cards_;
};

friend std::ostream& operator<<(std::ostream& os, const Hand& h);

void Hand::addCard(const Card& card);
uint8_t Hand::getValue() const;
const std::vector<Card>& Hand::getCards() const;
