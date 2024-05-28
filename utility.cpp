#include "utility.h"
#include <ctime>
#include <cstdlib>

void go_to_start(uint8_t *position) { *position = START; }

void go_to_illinois(uint8_t *position) { *position = ILLINOIS; }

void go_to_utility(uint8_t *position) {
  if (*position > LIGHT && *position < WATER) {
    *position = WATER;
  } else {
    *position = LIGHT;
  }
}

void go_to_railroad(uint8_t *position) { *position += (5 - (*position % 5)); }

void go_back_three(uint8_t *position) { *position -= 3; }

void go_to_jail(uint8_t *position) {
  *position = JAIL;
}

void go_to_rr(uint8_t *position) { *position = READING_RR; }

void go_to_boardwalk(uint8_t *position) { *position = BOARDWALK; }

void do_nothing(uint8_t *position) { return; }

uint8_t dice_toss(uint8_t amount) {
  if (amount == 0) {
    return 0;
  }
  return ((std::rand()) % 6 + 1)+ dice_toss(--amount);  // dice has 6 faces;
}
