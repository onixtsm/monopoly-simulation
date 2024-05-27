#include "Field.h"
void Field::add_visit(void) { Field::visits++; }

Field::~Field() {}

uint8_t Field::index = 0;
Field::Field() {
  Field::index++;
}

uint64_t Field::getVisits(void) const {
  return Field::visits;
}

