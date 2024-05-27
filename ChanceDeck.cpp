#include "ChanceDeck.h"

#include <algorithm>
#include <ctime>
#include <random>

ChanceDeck::ChanceDeck() {
  ChanceDeck::deck.fill(do_nothing);
  ChanceDeck::deck[0] = go_to_start;
  ChanceDeck::deck[1] = go_to_utility;
  ChanceDeck::deck[2] = go_to_rr;
  ChanceDeck::deck[3] = go_to_jail;
  ChanceDeck::deck[4] = go_back_three;
  ChanceDeck::deck[5] = go_to_boardwalk;
  ChanceDeck::deck[6] = go_to_illinois;
  std::srand(std::time(nullptr));
  std::shuffle(deck.begin(), deck.end(), std::default_random_engine(0));
  ChanceDeck::counter = 0;
}
ChanceFunc ChanceDeck::get_card(void) {
  ChanceFunc card = ChanceDeck::deck[counter];
  ChanceDeck::counter++;
  ChanceDeck::counter %= CHANCE_DECK_SIZE;
  return card;
}
