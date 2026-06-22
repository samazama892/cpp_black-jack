#include "Hand.hpp"

#include <ostream>
#include <cstdint>

friend std::ostream& operator<<(std::ostream& os, const Hand& h) {
	os << "Hand { ";
	for (const auto& card : h.getCards()) {
		if (&card != &h.getCards().front()) {
			os << ", ";
		} else {
			os << card;
		}
	}
	os << "}";
	return os;
}

void Hand::addCard(const Card& card) {
	cards_.push_back(card);
}

uint8_t Hand::getValue() const {
	uint8_t value = 0;
	uint8_t numAces = 0;

	for (const auto& card : cards_) {
		value += card.getValue();
		if (card.getRank() == Rank::Ace) {
			numAces++;
		}
	}

	while (value > 21 && numAces > 0) {
		value -= 10;
		numAces--;
	}

	return value;
}
