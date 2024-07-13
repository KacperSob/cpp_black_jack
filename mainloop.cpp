#include "mainloop.h"

void mainLoop(Player *gracz, Player *krupier, int16_t stand){
    int16_t bet;
	do
		{
			std::cout << "Place your bet, you have " << gracz->pieniadze << "$: ";
			std::cin >> bet;
		} while (bet>gracz->pieniadze);

        std::cout << "\n\n==================================================\n";
		std::cout << "Dealers card: " << pokazKarte(krupier->karty[0]) << std::endl;

		do
		{
			stand = gra(gracz, krupier, &bet);
		} while (stand != 1);

		krupierHit(krupier);

		// Dealer hits

		std::cout << "Dealer hits... " << std::endl;

		for (auto i = krupier->karty.begin(); i != krupier->karty.end(); ++i)
			std::cout << pokazKarte(*i) << " ";

		std::cout << std::endl;

		// Win conditions

		if (check(gracz) <= 21 && check(gracz) > check(krupier)) {
			std::cout << "YOU'VE WON!!!";
			gracz->pieniadze += bet;
		}
		else if (check(gracz) == check(krupier)) {
			std::cout << "Tie, you get your money back :/";
		}
		else if (check(krupier) > 21){
			std::cout << "YOU'VE WON!!!";
			gracz->pieniadze += bet;
		}
		else if (check(gracz) < check(krupier)) {
			std::cout << "You've lost :c";
            gracz->pieniadze -= bet;
		}
		std::cout << "\n";

		gracz->karty.clear();
		gracz->hit();
		gracz->hit();
		krupier->karty.clear();
		Sleep(252);
		krupier->hit();
		krupier->hit();
		Sleep(2000); // Time before another round
        std::cout << "\n\n==================================================\n";
}