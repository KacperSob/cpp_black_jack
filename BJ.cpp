﻿#include "mainloop.h"

int main()
{
	srand(time(0));
	Player *gracz = new(Player);
	Sleep(252);
	Player *krupier = new(Player);
	int16_t bet;
	int16_t stand = 0;

	while (gracz->pieniadze > 0) //Main while loop (update)
	{
		mainLoop(gracz, krupier, bet, stand);	
	}

	std::cout << "\nYou went bankrupt. Game over :c";
	delete(gracz);
	gracz = nullptr;
	delete(krupier);
	krupier = nullptr;
	Sleep(5000);
	return 0;
}