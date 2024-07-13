#include "player.h"
#include <iostream>
#include <sstream>

int16_t gra(Player* gracz, Player* krupier, int16_t bet);
int16_t check(Player* gracz);
void krupierHit(Player* krupier);
std::string pokazKarte(int16_t karta);