# Blackjack Rules

## Overview

Blackjack is a casino card game in which players compete against the dealer.

The objective is to obtain a hand value closer to **21** than the dealer without exceeding **21**.

Players do not compete against one another. Each player wins or loses independently against the dealer.

---

# Objective

A player wins by:

* Having a higher hand value than the dealer without exceeding 21.
* Having the dealer bust.
* Receiving a natural Blackjack.

A player loses by:

* Busting (exceeding 21).
* Having a lower hand value than the dealer.
* Having the dealer achieve a higher valid hand value.

---

# Participants

A game contains:

* One Dealer
* One or more Players

The dealer manages the deck and follows predefined drawing rules.

---

# Card Values

| Card  | Value      |
| ----- | ---------- |
| 2-10  | Face value |
| Jack  | 10         |
| Queen | 10         |
| King  | 10         |
| Ace   | 1 or 11    |

An Ace is worth either 1 or 11, whichever produces the best valid hand.

### Examples

| Hand          | Value |
| ------------- | ----- |
| Ace + King    | 21    |
| Ace + 7       | 18    |
| Ace + 7 + 9   | 17    |
| Ace + Ace + 9 | 21    |

---

# Blackjack

A Blackjack (also called a Natural) is:

```text
Ace + 10
Ace + Jack
Ace + Queen
Ace + King
```

obtained with the player's initial two cards.

A Blackjack automatically beats any non-Blackjack hand valued at 21.

Standard casinos typically pay Blackjack at 3:2 odds.

---

# Round Setup

At the start of each round:

1. Players place their bets.
2. The dealer shuffles the deck if necessary.
3. Every player receives two cards face-up.
4. The dealer receives:

   * One face-up card (upcard)
   * One face-down card (hole card)

Example:

```text
Player:
[10♠] [7♦]

Dealer:
[K♥] [?]
```

---

# Player Actions

Starting from the dealer's left, each player takes a turn.

During a turn, a player may perform one of the following actions.

## Hit

Receive one additional card.

The player may continue hitting until they:

* Stand
* Bust

---

## Stand

Take no more cards.

The player's turn immediately ends.

---

# Bust

A player busts when their hand value exceeds 21.

Example:

```text
10 + 8 + 6 = 24
```

A busted player immediately loses the round.

---

# Dealer Turn

After all players have completed their turns:

1. The dealer reveals the hole card.
2. The dealer calculates their hand value.
3. The dealer follows house rules.

Standard dealer rules:

```text
Dealer must Hit on 16 or less.
Dealer must Stand on 17 or more.
```

The dealer cannot freely choose.

---

# Dealer Bust

If the dealer's hand exceeds 21:

```text
Dealer = 22
```

The dealer busts.

All remaining non-busted players win.

---

# Determining Winners

After the dealer finishes:

## Player Busts

Player loses immediately.

---

## Dealer Busts

All non-busted players win.

---

## Dealer and Player Both Valid

Compare scores:

| Player | Dealer | Result |
| ------ | ------ | ------ |
| 20     | 18     | Win    |
| 18     | 20     | Lose   |
| 19     | 19     | Push   |

A Push is a tie.

The player's bet is returned.

---

# Example Round

Dealer:

```text
[K♠] [7♥]
```

Dealer total:

```text
17
```

Players:

| Player  | Total | Result |
| ------- | ----- | ------ |
| Alice   | 20    | Win    |
| Bob     | 17    | Push   |
| Charlie | 15    | Lose   |
| Dana    | 22    | Bust   |

---

# Game Flow

```text
Start Round
    │
    ▼
Place Bets
    │
    ▼
Deal Initial Cards
    │
    ▼
Player Turns
    │
    ▼
Dealer Turn
    │
    ▼
Determine Results
    │
    ▼
Payouts
    │
    ▼
Next Round
```

---

# Future Rule Variants

Optional rules often found in casinos:

* Double Down
* Split Pairs
* Insurance
* Surrender
* Multiple Decks
* Dealer Hits Soft 17
* Side Bets
