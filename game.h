#include "player.h"
#include <iostream>
#include <algorithm>
#include <sstream>

int16_t gra(Player* gracz, Player* krupier, int16_t* bet,  std::vector<std::vector<int16_t>>* decks);
int16_t check(std::vector<int16_t> karty);
void krupierHit(Player* krupier);
std::string pokazKarte(int16_t karta);
void split(std::vector<int16_t>* karty, int16_t* bet, Player* gracz,  std::vector<std::vector<int16_t>>* decks);
int16_t wartoscKarty(int16_t karta);
void wybor(std::vector<int16_t>* karty, int16_t* bet, Player* gracz,  std::vector<std::vector<int16_t>>* decks);