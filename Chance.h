#ifndef CHANCE_H_
#define CHANCE_H_
#include "ChanceDeck.h"
#include "Field.h"

class Chance : public Field {
  static ChanceDeck &deck;

 public:
  Chance();
  void action(uint8_t *position) override;
  virtual ~Chance();
};
#endif
