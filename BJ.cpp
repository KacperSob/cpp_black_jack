#include "test.h"

int main()
{
	srand(time(0));
	/*
	running tests
	runAllTests();
	Sleep(8000);
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	*/
	Player *gracz = new(Player);
	Sleep(252);
	Player *krupier = new(Player);
	int16_t stand = 0;

	while (gracz->pieniadze > 0) //Main while loop (update)
	{
		mainLoop(gracz, krupier, stand);	
	}

	std::cout << "\nYou went bankrupt. Game over :c";
	delete(gracz);
	gracz = nullptr;
	delete(krupier);
	krupier = nullptr;
	Sleep(5000);
	return 0;
}