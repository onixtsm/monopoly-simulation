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

std::array<Field *, FIELD_COUNT> field;
size_t move_count = 100;

void print_field(void) {
  printf("Most visited fields\n");
  for (auto f : field) {
    if (move_count > 100) {
      printf("index: %3d, visits:%3f\n", f->my_index, 10 * log(f->getVisits()));
    } else {
      printf("index: %3d, visits:%3zu\n", f->my_index, f->getVisits());
    }
  }
}

void print_field_rev(void) {
  printf("Most profitable fields\n");
  for (auto f : field) {
    if (f->getRevenue() != 0) {
      if (move_count > 100) {
        printf("index: %3d, revenue:%3f\n", f->my_index, 10 * log(f->getRevenue()));
      } else {
        printf("index: %3d, revenue:%3zu\n", f->my_index, f->getRevenue());
      }
    }
  }
}

class Property : public Field {
  void add_revenue() { revenue += rent; }

 public:
  Property(uint64_t cost, uint64_t rent) {
    this->cost = cost;
    this->rent = rent;
  }
  void action(uint8_t *position) override {
    add_revenue();
    visits++;
  }
};

class Comodoty : public Field {
  void add_revenue(void) { revenue += dice_toss(3) * 10; }

 public:
  Comodoty(uint64_t cost) { this->cost = cost; }
  void action(uint8_t *position) override {
    add_revenue();
    visits++;
  }
};

class TrainStation : public Field {
  std::array<uint64_t, 4> rent;
  void add_revenue(void) { revenue = rent[3]; }

 public:
  TrainStation(uint64_t cost, std::array<uint64_t, 4> rent) {
    this->cost = cost;
    this->rent = rent;
  }
  void action(uint8_t *position) override {
    add_revenue();
    visits++;
  }
};

class Jail : public Field {
 public:
  void action(uint8_t *position) override {
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
  void action(uint8_t *position) override { visits++; }
};

#define TRAIN_STATION_RENT \
  { 25, 50, 100, 200 }

uint8_t position = 0;

void do_move(void);

int main(int argc, char **argv) {
  if (argc > 1) {
    move_count = atoi(argv[1]);
  }
  std::srand(std::time(nullptr));

  field = {new Empty(),
           new Property(60, 2),
           new PublicFund(),
           new Property(60, 4),
           new Empty(),
           new TrainStation(200, TRAIN_STATION_RENT),
           new Property(100, 6),
           new Chance(),
           new Property(100, 6),
           new Property(120, 8),
           new Jail(),
           new Property(140, 10),
           new Comodoty(150),
           new Property(140, 10),
           new Property(160, 12),
           new TrainStation(200, TRAIN_STATION_RENT),
           new Property(180, 14),
           new PublicFund(),
           new Property(180, 14),
           new Property(200, 14),
           new Empty(),
           new Property(220, 18),
           new Chance(),
           new Property(220, 18),
           new Property(240, 20),
           new TrainStation(200, TRAIN_STATION_RENT),
           new Property(260, 22),
           new Comodoty(150),
           new Property(260, 22),
           new Property(280, 24),
           new Police(),
           new Property(300, 26),
           new Property(300, 26),
           new PublicFund(),
           new Property(320, 28),
           new TrainStation(200, TRAIN_STATION_RENT),
           new Chance(),
           new Property(350, 35),
           new Empty(),
           new Property(400, 50)};
  fprintf(stderr, "Array initialised\n");

  do_move();
  for (size_t i = 1; i < move_count; ++i) {
    do_move();
  }
  std::sort(field.begin(), field.end(), [](Field const *a, Field const *b) -> bool {
    return a->getVisits() > b->getVisits() ? 1 : a->getVisits() == b->getVisits() ? a->my_index < b->my_index : 0;
  });
  print_field();
  std::sort(field.begin(), field.end(), [](Field const *a, Field const *b) -> bool {
    return a->getRevenue() > b->getRevenue() ? 1 : a->getRevenue() == b->getRevenue() ? a->my_index < b->my_index : 0;
  });
  print_field_rev();
  return 0;
}

void do_move(void) {
  position = position + dice_toss(2);
  position = position % FIELD_COUNT;
  uint8_t temp = position;

DO_ACTION:
  field[position]->action(&position);
  if (position != temp) {
    temp = position;
    goto DO_ACTION;
  }
}
