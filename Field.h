#ifndef FIELD_H_
#define FIELD_H_
#include <stdint.h>
#include <cstdlib>
#include <string>
#include "utility.h"
class Field {
 protected:
  uint64_t rent;
  uint64_t cost;
  uint64_t revenue = 0;
  uint64_t visits = 0;
  static uint8_t index;

 public:
  Field();
  void set_revenue(uint64_t revenue) { revenue = revenue; }
  virtual void action(uint8_t *position) {
    add_visit();
  };
  void add_visit(void); 
  virtual ~Field();
  uint64_t getVisits(void) const;
  uint8_t my_index = index - 40;
};

#endif
