#include "game.h"
#include <windows.h>

void mainLoop(Player *gracz, Player *krupier, int16_t stand);
void checkWinner(Player *gracz, int16_t allPlayer, int16_t allDealer, int16_t bet);