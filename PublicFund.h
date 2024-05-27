#ifndef PUBLICFUND_H_
#define PUBLICFUND_H_
#include "Field.h"
#include "PublicFundDeck.h"

class PublicFund : public Field {
  static PublicFundDeck &deck;

 public:
  PublicFund();
  void action(uint8_t *position) override;
};
#endif
