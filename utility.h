#ifndef UTILITY_H_
#define UTILITY_H_
#include <cinttypes>

#define JAIL 9
#define START 10
#define ILLINOIS 24
#define LIGHT 12
#define WATER 28
#define READING_RR 5
#define BOARDWALK 39

void go_to_start(uint8_t *position);

void go_to_illinois(uint8_t *position);

void go_to_utility(uint8_t *position);

void go_to_railroad(uint8_t *position);

void go_back_three(uint8_t *position);

void go_to_jail(uint8_t *position);

void go_to_rr(uint8_t *position);

void go_to_boardwalk(uint8_t *position);

void do_nothing(uint8_t *position);

uint8_t dice_toss(uint8_t amount);

#endif
