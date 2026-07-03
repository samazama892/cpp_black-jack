#include "blackjack/Game.hpp"

#include <iostream>
#include <vector>

Game::Game() {
  player_ = Player();
  dealer_ = Player();
  deck_ = Deck();
}

void cout_hands(const Player& player, const Player& dealer) {
  atd::cout << "Your hand: " << player_.getHand() << '\n';
  atd::cout << "Dealer hand: ?, " << dealer_.getHand() << "\n\n";
}

void Game::play() {
  std::cout << "WELCOME TO BLACKJACK!!!\n\n";

  player_.hit(deck_);
  dealer_.hit(deck_);
  player_.hit(deck_);
  dealer_.hit(deck_);

  const std::vector<Card>& dealer_cards = dealer_.getHand().getCards();
  const Card& hidden = dealer_cards.back();
  dealer_cards.pop_back();

}
