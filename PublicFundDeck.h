#ifndef PUBLICFUNDDECK_H_
#define PUBLICFUNDDECK_H_
#include <array>
#include <ctime>

#include "utility.h"

typedef void (*PublicFunc)(uint8_t *position);

#define PUBLIC_FUND_DECK_SIZE 17
class PublicFundDeck {
  static PublicFundDeck *instance;
  std::array<PublicFunc, PUBLIC_FUND_DECK_SIZE> deck;
  size_t counter;

  PublicFundDeck();

 public:
  static PublicFundDeck &getInstance() {
    static PublicFundDeck instance;
    return instance;
  }
  PublicFunc get_card(void);
};

#endif
