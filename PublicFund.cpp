#include "PublicFund.h"

#include "PublicFundDeck.h"

PublicFundDeck& PublicFund::deck = PublicFundDeck::getInstance();

PublicFund::PublicFund() {}
void PublicFund::action(uint8_t* position) {
  PublicFund::deck.get_card()(position);
  PublicFund::visits++;
}
