#include "blackjack/Game.hpp"

#include <iostream>
#include <vector>

void cout_hands(const Player& player, const Player& dealer) {
  std::cout << "Your hand: " << player.getHand() << '\n';
  std::cout << "Dealer hand: ?, " << dealer.getHand() << "\n\n";
}

RoundResolution StandardGame::resolveRoundOutcome(bool playerBusted, bool dealerBusted, int playerScore, int dealerScore) {
  if (playerBusted) {
    return RoundResolution::DealerWins;
  }
  if (dealerBusted) {
    return RoundResolution::PlayerWins;
  }
  if (playerScore > dealerScore) {
    return RoundResolution::PlayerWins;
  }
  if (playerScore < dealerScore) {
    return RoundResolution::DealerWins;
  }
  return RoundResolution::Push;
}

void StandardGame::play() {
  std::cout << "WELCOME TO BLACKJACK!!!\nMade by Iden Gomes, and based on the implementation in Red Dead Redemption.\n\n";

  player_.setChips(CHIPS_PER_PERSON);
  dealer_.setChips(CHIPS_PER_PERSON);

  bool playing = true;

  while (playing) {
    std::cout << "You have " << player_.getChips() << " chips.\n";
    if (player_.getChips() < MIN_BET_AMOUNT) {
      std::cout << "You don't have enough chips to continue playing. Game over!\n\n";
      break;
    }
    std::uint32_t bet_amount;
    bool valid_bet = false;
    while (!valid_bet) {
      std::cout << "Enter your bet (between " << MIN_BET_AMOUNT << " and " << MAX_BET_AMOUNT << "): ";
      std::cout.flush();
      std::cin >> bet_amount;
      try {
        player_.bet(bet_amount);
        if (bet_amount < MIN_BET_AMOUNT || bet_amount > MAX_BET_AMOUNT) {
          throw std::out_of_range("Bet amount out of range");
        }
        valid_bet = true;

        std::cout << "You bet " << bet_amount << " chips.\n";
        if (bet_amount == player_.getChips()) { std::cout << "DESPERATION!!\n"; }
        std::cout << '\n';
      } catch (const std::out_of_range &e) {
        std::cout << "Invalid bet. Please try again.\n\n";
      }
    }

    player_.hit(deck_);
    hole_card = deck_.draw();
    player_.hit(deck_);
    dealer_.hit(deck_);

    if (player_.getHand().hasBlackjack()) {
      if (dealer_.getHand().hasBlackjack()) {
        std::cout << "PUSH! Both you and the dealer have blackjack!\n";
        player_.addChips(bet_amount); // Return the bet to the player
      } else {
        std::cout << "WIN! You have blackjack!\n";
        player_.addChips(static_cast<std::uint32_t>(bet_amount * 2.5)); // Payout for blackjack is 3:2
      }
      std::cout << "You now have " << player_.getChips() << " chips.\n\n";
      continue;
    }

    if (dealer_.getHand().getCards()[0].rank == Rank::Ace) {
      std::cout << "Dealer has an Ace showing. Do you want to take insurance? (y/n): ";
      char insurance_choice;
      bool valid_insurance = false;
      while (!valid_insurance) {
        std::cin >> insurance_choice;
        if (insurance_choice == 'y' || insurance_choice == 'Y') {
          std::uint32_t max_insurance_bet = bet_amount / 2;
          std::uint32_t insurance_bet;
          std::cout << "Enter your insurance bet (up to " << max_insurance_bet << "): ";
          std::cout.flush();
          std::cin >> insurance_bet;
          if (insurance_bet > max_insurance_bet) {
            std::cout << "Insurance bet exceeds maximum allowed.\n\n";
            continue;
          } else { valid_insurance = true; }
          try {
            player_.bet(insurance_bet);
            std::cout << "You placed an insurance bet of " << insurance_bet << " chips.\n";
            if (dealer_.getHand().hasBlackjack()) {
              std::cout << "Dealer has blackjack! Insurance pays 2:1.\n\n";
              player_.addChips(insurance_bet * 3); // Payout for insurance is 2:1
            } else {
              std::cout << "Dealer does not have blackjack. You lose your insurance bet.\n\n";
            }
          } catch (const std::out_of_range &e) {
            std::cout << "Not enough chips for insurance bet.\n\n";
            continue;
          }
        } else { break; }
      }
    }

    bool stand = false;
    bool busted = false;
    while (!stand && !busted) {
      cout_hands(player_, dealer_);
      std::cout << "Your hand value: " << player_.getHandValue() << '\n';
      std::cout << "Do you want to hit, stand, or double down? (h/s/d): ";
      std::cout.flush();
      char choice;
      std::cin >> choice;
      switch (choice) {
        case 'h':
        case 'H':
          player_.hit(deck_);
          if (player_.getHandValue() > 21) {
            cout_hands(player_, dealer_);
            std::cout << "BUST! You exceeded 21 with a score of " << player_.getHandValue() << ". You lose your bet of " << bet_amount << " chips.\n";
            std::cout << "You now have " << player_.getChips() << " chips.\n\n";
            busted = true;
          }
          break;
        case 's':
        case 'S':
          std::cout << "STAND!\n\n";
          stand = true;
          break;
        case 'd':
        case 'D':
          if (player_.getChips() >= bet_amount) {
            std::cout << "DOUBLE DOWN! Your bet increases from " << bet_amount << " to " << bet_amount * 2 << ".\n\n";
            player_.bet(bet_amount);
            bet_amount *= 2;
            player_.hit(deck_);
            if (player_.getHandValue() > 21) {
              cout_hands(player_, dealer_);
              std::cout << "BUST! You exceeded 21 with a score of " << player_.getHandValue() << ". You lose your bet of " << bet_amount << " chips.\n";
              std::cout << "You now have " << player_.getChips() << " chips.\n\n";
              busted = true;
            }
          } else {
            std::cout << "Not enough chips to double down.\n\n";
            continue;
          }
          stand = true;
          break;
        default:
          std::cout << "Invalid choice. Please enter 'h' to hit, 's' to stand, or 'd' to double down.\n\n";
          break;
      }
    }

    std::cout << "Dealer's turn!\nDealer reveals hole card... " << hole_card << "!\n\n";
    dealer_.addCard(hole_card);
    while (dealer_.getHandValue() < 17) {
      dealer_.hit(deck_);
      std::cout << "Dealer hits and draws: " << dealer_.getHand().getCards().back() << '\n';
    }
    const auto resolution = resolveRoundOutcome(busted, dealer_.getHandValue() > 21, player_.getHandValue(), dealer_.getHandValue());

    if (dealer_.getHandValue() > 21) {
      std::cout << "Dealer busts!\n";
    } else {
      std::cout << "Dealer stands with a hand value of " << dealer_.getHandValue() << ".\n";
    }

    switch (resolution) {
      case RoundResolution::PlayerWins:
        std::cout << "You win! You gain " << bet_amount << " chips!\n\n";
        player_.addChips(bet_amount * 2); // Return the bet and add winnings
        break;
      case RoundResolution::DealerWins:
        if (busted) {
          std::cout << "You busted, so you lose your bet of " << bet_amount << " chips.\n\n";
        } else {
          std::cout << "Dealer wins! You lose your bet of " << bet_amount << " chips.\n\n";
        }
        break;
      case RoundResolution::Push:
        std::cout << "PUSH! It's a tie. Your bet of " << bet_amount << " chips is returned.\n\n";
        player_.addChips(bet_amount); // Return the bet to the player
        break;
    }

    if (dealer_.getChips() < MIN_BET_AMOUNT) {
      std::cout << "Dealer doesn't have enough chips to continue playing. You win the game!\n\n";
      break;
    }

    player_.clearHand();
    dealer_.clearHand();
    deck_.reset();
  }
  
  std::cout << "Thanks for playing! You leave with " << player_.getChips() << " chips.\n";
}
