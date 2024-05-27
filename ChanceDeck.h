#ifndef CHANCEDECK_H_
#define CHANCEDECK_H_
#include <array>

#include "utility.h"
#define CHANCE_DECK_SIZE 15

typedef void (*ChanceFunc)(uint8_t *position);

class ChanceDeck {
  static ChanceDeck *instance;
  std::array<ChanceFunc, CHANCE_DECK_SIZE> deck;
  std::size_t counter;

  ChanceDeck();

 public:
  static ChanceDeck &getInstance() {
    static ChanceDeck instance;
    return instance;
  }
  ChanceFunc get_card(void);
};
#endif
