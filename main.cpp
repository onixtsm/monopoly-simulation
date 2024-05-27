#include <stdint.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Chance.h"
#include "Field.h"
#include "PublicFund.h"
#include "utility.h"

#define FIELD_COUNT 40

std::array<Field, FIELD_COUNT> field;

void print_field(void) {
  printf("Most visited fields\n");
  for (auto f : field) {
    printf("index: %3d, visits:%3f\n", f.my_index, 10* log(f.getVisits()));
  
  }

}

class Property : public Field {
  void add_revenue() { revenue += rent; }

 public:
  Property(uint64_t cost, uint64_t rent) {
    cost = cost;
    rent = rent;
  }
  void action() {
    add_revenue();
    visits++;
  }
};

class Comodoty : public Field {
  void add_revenue(void) { revenue += dice_toss(3) * 10; }

 public:
  Comodoty(uint64_t cost) { cost = cost; }
  void action() {
    add_revenue();
    visits++;
  }
};

class TrainStation : public Field {
  std::array<uint64_t, 4> rent;
  void add_revenue(void) { revenue = rent[3]; }

 public:
  TrainStation(uint64_t cost, std::array<uint64_t, 4> rent) {
    cost = cost;
    rent = rent;
  }
  void action() {
    add_revenue();
    visits++;
  }
};

class Jail : public Field {
 public:
  void action() {
    visits++;
    return;
  }
};

class Police : public Field {
 public:
  void action(uint8_t *position) {
    visits++;
    go_to_jail(position);
  }
};

class Empty : public Field {
 public:
  Empty(void){};
  void action(void) { visits++; }
};

#define TRAIN_STATION_RENT \
  { 25, 50, 100, 200 }

uint8_t position = 0;

void do_move(void);

int main(int argc, char **argv) {

  size_t move_count = 100;
  if (argc > 1) {
    move_count = atoi(argv[1]);
  }
  std::srand(std::time(nullptr));

  field = {Empty(),
           Property(60, 2),
           PublicFund(),
           Property(60, 4),
           Empty(),
           TrainStation(200, TRAIN_STATION_RENT),
           Property(100, 6),
           Chance(),
           Property(100, 6),
           Property(120, 8),
           Jail(),
           Property(140, 10),
           Comodoty(150),
           Property(140, 10),
           Property(160, 12),
           TrainStation(200, TRAIN_STATION_RENT),
           Property(180, 14),
           PublicFund(),
           Property(180, 14),
           Property(200, 14),
           Empty(),
           Property(220, 18),
           Chance(),
           Property(220, 18),
           Property(240, 20),
           TrainStation(200, TRAIN_STATION_RENT),
           Property(260, 22),
           Comodoty(150),
           Property(260, 22),
           Property(280, 24),
           Police(),
           Property(300, 26),
           Property(300, 26),
           PublicFund(),
           Property(320, 28),
           TrainStation(200, TRAIN_STATION_RENT),
           Chance(),
           Property(350, 35),
           Empty(),
           Property(400, 50)};
  fprintf(stderr, "Array initialised\n");

  do_move();
  for (size_t i = 0; i < move_count; ++i) {
    do_move();
  }
  std::sort(field.begin(), field.end(), [](Field const & a, Field const & b) -> bool {
      return a.getVisits() > b.getVisits() ? 1 : a.getVisits() == b.getVisits() ? a.my_index < b.my_index : 0 ;
      });
  print_field();
  return 0;
}

void do_move(void) {
  position = position + dice_toss(2);
  position = position % FIELD_COUNT;
  uint8_t temp = position;

DO_ACTION:
  field[position].action(&position);
  if (position != temp) {
    goto DO_ACTION;
  }
}

