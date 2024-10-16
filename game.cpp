#include "game.h"

int16_t gra(Player* gracz, Player* krupier, int16_t* bet,  std::vector<std::vector<int16_t>>* decks) {
	std::string kartyWys; // string kart wyswietlanych
	int16_t wybor = 0;

	std::cout << "Your cards: ";
	for (auto i = gracz->karty.begin(); i != gracz->karty.end(); ++i)
		std::cout << pokazKarte(*i) << " ";
	std::cout << std::endl;
	do
	{
		std::cout << "1 - hit, 2 - stand, 3 - double 4 - split\n";
		std::cin >> wybor;
		if (wybor == 1) {
			gracz->hit();
			return 0;
		}
		else if (wybor == 2) {
			return 1;
		} else if (wybor == 3) {
			if(gracz->pieniadze >= (*bet*2)){
				gracz->hit();
				*bet *= 2;
				std::cout << "Your bet now is: " << *bet << std::endl;
				std::cout << "Your cards: ";
				for (auto i = gracz->karty.begin(); i != gracz->karty.end(); ++i)
				std::cout << pokazKarte(*i) << " ";
				std::cout << std::endl;
				return 1;
			} else {
				std::cout << "You don't have enough money!" << std::endl;
				wybor = 0;
			}
		} else if (wybor == 4) {
			if(wartoscKarty(gracz->karty.end()[-1]) != wartoscKarty(gracz->karty.end()[-2])){
					std::cout << "Your last two cards aren't the same value!" << std::endl;
					wybor = 0;
			} else {
				if(gracz->pieniadze >= (*bet*2)){
					split(&gracz->karty, bet, gracz, decks);
					return 1;
				} else {
					std::cout << "You don't have enough money!" << std::endl;
					wybor = 0;
				}	
			}
		}
	} while (wybor != 1 && wybor != 2 && wybor != 3);
}
int16_t check(std::vector<int16_t> karty) {
	int16_t sum = 0;
	std::vector<int16_t> check = karty;
	std::sort(check.begin(), check.end());
	for (int16_t karta : check) {
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
	while (check(krupier->karty) < 17)
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
int16_t wartoscKarty(int16_t karta){
	if (karta <= 10) {
			return karta;
		}
		else if (karta == 11 || karta == 12 || karta == 13) {
			return 10;
		}
		else if (karta == 14) {
			return 11;
		}
}

void split(std::vector<int16_t>* karty, int16_t* bet, Player* gracz, std::vector<std::vector<int16_t>>* decks){
	int16_t koniec = 0;
	int16_t option = 0;
	std::vector<int16_t> karty2;
	karty2.push_back(karty->end()[-1]);
	karty->erase(karty->end()-1);
	decks->push_back(*(karty));
	decks->push_back(karty2);
	do
	{
		int16_t gdziehit = 0;
		for(std::vector<int16_t> deck : *decks){
			for (auto i = deck.begin(); i != deck.end(); ++i)
				std::cout << pokazKarte(*i) << " ";
			std::cout << "| ";
		}
		do
		{
			std::cout << "\nWhich deck to hit? 1 to " << decks->size() << "\n";
			std::cin >> gdziehit;
		} while (!(gdziehit > 0 && gdziehit <= decks->size()));
		wybor(&(decks->at((gdziehit-1))), bet, gracz, decks);
		do
		{
			for(std::vector<int16_t> deck : *decks){
				for (auto i = deck.begin(); i != deck.end(); ++i)
					std::cout << pokazKarte(*i) << " ";
				std::cout << "| ";
			}
			std::cout << "\nDo you want to hit more or stand all? 1 - hit, 2 - stand\n";
			std::cin >> option;
		} while (option != 1 && option != 2);
		switch (option)
		{
		case 1:
			koniec = 0;
			break;
		case 2:
			koniec = 1;
			break;
		default:
			koniec = 0;
			break;
		}
	} while (koniec!=1);	
}

void wybor(std::vector<int16_t>* karty, int16_t* bet, Player* gracz,  std::vector<std::vector<int16_t>>* decks){
	int16_t stand = 0;
	int16_t wybor = 0;
	do
	{
		do
		{
			for (auto i = karty->begin(); i != karty->end(); ++i)
				std::cout << pokazKarte(*i) << " ";
			std::cout << "\n";
			std::cout << "1 - hit, 2 - stand, 3 - double 4 - split\n";
			std::cin >> wybor;
			if (wybor == 1) {
				karty->push_back(randKarta());
				stand = 0;
			}
			else if (wybor == 2) {
				stand = 1;
			} else if (wybor == 3) {
				if(gracz->pieniadze >= (*bet*2)){
					karty->push_back(randKarta());
					*bet *= 2;
					std::cout << "Your bet now is: " << *bet << std::endl;
					std::cout << "Your cards: ";
					for (auto i = karty->begin(); i != karty->end(); ++i)
					std::cout << pokazKarte(*i) << " ";
					std::cout << std::endl;
					stand = 1;
				} else {
					std::cout << "You don't have enough money!" << std::endl;
					wybor = 0;
				}
			} else if (wybor == 4) {
				if(wartoscKarty(karty->end()[-1]) != wartoscKarty(karty->end()[-2])){
					std::cout << "Your last two cards aren't the same value!" << std::endl;
					wybor = 0;
				} else {
					if(gracz->pieniadze >= (*bet*2)){
						split(&gracz->karty, bet, gracz, decks);
						stand = 1;
					} else {
						std::cout << "You don't have enough money!" << std::endl;
						wybor = 0;
					}
				}
			}
		} while (wybor != 1 && wybor != 2 && wybor != 3);
	} while (stand!=1);
}
