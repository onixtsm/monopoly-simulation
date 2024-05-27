#include "Chance.h"

#include "ChanceDeck.h"

ChanceDeck& Chance::deck = ChanceDeck::getInstance();

Chance::Chance() {}
void Chance::action(uint8_t* position) {
  Chance::deck.get_card()(position);
  Chance::visits++;
}
Chance::~Chance() {

}
