#include "PublicFundDeck.h"
#include <algorithm>
#include <random>

PublicFundDeck::PublicFundDeck() {
  PublicFundDeck::deck.fill(do_nothing);
  PublicFundDeck::deck[0] = go_to_start;
  PublicFundDeck::deck[3] = go_to_jail;
  std::srand(std::time(nullptr));
  std::shuffle(deck.begin(), deck.end(), std::default_random_engine(0));
  PublicFundDeck::counter = 0;
}
PublicFunc PublicFundDeck::get_card(void) {
  PublicFunc card = deck[counter];
  PublicFundDeck::counter++;
  PublicFundDeck::counter %= PUBLIC_FUND_DECK_SIZE;
  return card;
}
