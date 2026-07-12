# C++ Black Jack

A simple Blackjack implementation written in **modern C++17**.

This project is designed as a modular Blackjack engine with unit tests and CMake support.

---

## Features

- ♠️ Standard deck of 52 playing cards
- 🃏 `Card`, `Deck`, `Hand`, `Player`, and `Game` abstractions
- 🎮 Command-line Blackjack game
- 🧩 Modular library architecture
- 🧪 Catch2 Unit tests
- ⚙️ CMake build system
- 📚 Documentation for Blackjack rules

---

## Project Structure

```text
.
├── include/
│   └── blackjack/
│       ├── Card.hpp
│       ├── Deck.hpp
│       ├── Game.hpp
│       ├── Hand.hpp
│       ├── Player.hpp
│       ├── Rank.hpp
│       ├── Stats.hpp
│       └── Suit.hpp
├── src/
│   ├── main.cpp
│   ├── Card.cpp
│   ├── Deck.cpp
│   ├── Game.cpp
│   ├── Hand.cpp
│   ├── Player.cpp
│   ├── Rank.cpp
│   ├── Stats.cpp
│   └── Suit.cpp
├── tests/
├── docs/
├── CMakeLists.txt
└── build.sh
```

---

## Requirements

- C++17 compatible compiler
  - GCC
  - Clang
  - MSVC (Visual Studio 2019+)
- CMake 3.16 or newer

---

## Building

### Linux / macOS

```bash
mkdir build
cd build

cmake ..
cmake --build .
```

Or, just run `build.sh`:

```bash
./build.sh [--release] [--debug] [--no-cmake] [--clean] [--help]
```

### Windows

```powershell
mkdir build
cd build

cmake ..
cmake --build . --config Release
```

---

## Running

After building:

```bash
./build/blackjack
```

On Windows:

```powershell
.\Release\blackjack.exe
```

---

## Running Tests

If testing is enabled (default):

```bash
ctest
```

or

```bash
ctest --output-on-failure
```

---

## Documentation

Additional documentation can be found in the `docs/` directory, including:

- Blackjack rules
- Gameplay flow
- Design goals
- Splitting rules

---

## Goals

This project focuses on:

- Clean object-oriented design
- Separation of game logic from the executable
- Readable and maintainable C++
- Practicing modern C++ development
- Unit testing

---

## Future Improvements

- Save/load statistics
- Better terminal UI

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
