include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(deck_tests test_Deck.cpp)
target_link_libraries(deck_tests PRIVATE Catch2::Catch2WithMain blackjack)

include(CTest)
include(Catch)
catch_discover_tests(deck_tests)