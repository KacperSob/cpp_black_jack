#include "game.h"

int16_t gra(Player* gracz, Player* krupier, int16_t bet) {
	std::string kartyWys; // string kart wyswietlanych
	int16_t wybor = 0;

	std::cout << "Your cards: " << kartyWys;
	for (auto i = gracz->karty.begin(); i != gracz->karty.end(); ++i)
		std::cout << pokazKarte(*i) << " ";
	std::cout << std::endl;
	do
	{
		std::cout << "1 - hit, 2 - stand\n";
		std::cin >> wybor;
		if (wybor == 1) {
			gracz->hit();
			return 0;
		}
		else if (wybor == 2) {
			return 1;
		}
	} while (wybor != 1 && wybor != 2);
}
int16_t check(Player* gracz) {
	int16_t sum = 0;
	for (int16_t karta : gracz->karty) {
		if (karta <= 10) {
			sum += karta;
		}
		else if (karta == 11 || karta == 12 || karta == 13) {
			sum += 10;
		}
		else if (karta == 14) {
			sum += 11;
			if (sum > 21) {
				sum -= 11;
				sum += 1;
			}
		}
	}
	return sum;
}
void krupierHit(Player* krupier) {
	while (check(krupier) < 17)
	{
		krupier->hit();
	}
}
std::string pokazKarte(int16_t karta) {
	if (karta <= 10) {
		return std::to_string(karta).append(" ");
	}
	else {
		switch (karta)
		{
		case 11:
			return "J ";
			break;
		case 12:
			return "Q ";
			break;
		case 13:
			return "K ";
			break;
		case 14:
			return "A ";
			break;
		default:
			break;
		}
	}
}