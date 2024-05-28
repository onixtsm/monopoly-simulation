#include "Field.h"
void Field::add_visit(void) { Field::visits++; }

Field::~Field() {}

int Field::index = 0;
Field::Field() {
  Field::index++;
}

uint64_t Field::getVisits(void) const {
  return Field::visits;
}

uint64_t Field::getRevenue(void) const {
  return Field::revenue;
}
