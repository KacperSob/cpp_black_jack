#include "mainloop.h"

void mainLoop(Player *gracz, Player *krupier, int16_t stand){
    int16_t bet;
    std::vector<std::vector<int16_t>> decks;




	do
	{
		std::cout << "Place your bet, you have " << gracz->pieniadze << "$: ";
		std::cin >> bet;
	} while (bet>gracz->pieniadze);
    std::cout << "\n==================================================\n";
	std::cout << "Dealers card: " << pokazKarte(krupier->karty[0]) << std::endl;
	do
	{
		stand = gra(gracz, krupier, &bet, &decks);
	} while (stand != 1);

    Sleep(200);

	krupierHit(krupier);
	// Dealer hits
	std::cout << "Dealer hits... " << std::endl;
	for (auto i = krupier->karty.begin(); i != krupier->karty.end(); ++i)
		std::cout << pokazKarte(*i) << " ";
	std::cout << std::endl;
    Sleep(200);

    int16_t allDealer = check(krupier->karty);
    int16_t allPlayer = check(gracz->karty);

	// Win conditions
    
    if(decks.size() < 1){
        
        checkWinner(gracz, allPlayer, allDealer, bet);

    } else {


        for(std::vector<int16_t> deck : decks){
            allPlayer = check(deck);

            checkWinner(gracz, allPlayer, allDealer, bet);
        }
    }
	

    // Cleaning decks

	gracz->karty.clear();
	gracz->hit();
	gracz->hit();
	krupier->karty.clear();
	Sleep(252);
	krupier->hit();
	krupier->hit();
	Sleep(2000); // Time before another round
    std::cout << "\n==================================================\n";
    decks.clear();
}

void checkWinner(Player *gracz, int16_t allPlayer, int16_t allDealer, int16_t bet){
    if (allPlayer <= 21 && allPlayer > allDealer) {
		    std::cout << "YOU WON!!!";
		    gracz->pieniadze += bet;
	    }
	    else if (allPlayer == allDealer) {
		    std::cout << "Tie, you get your money back :/";
	    }
	    else if (allDealer > 21){
            if(allPlayer <= 21){
                std::cout << "YOU WON!!!";
		        gracz->pieniadze += bet;
            } else {
                std::cout << "You lost :c";
                gracz->pieniadze -= bet;
            }
	    }
	    else if (allPlayer < allDealer) {
	    	std::cout << "You lost :c";
            gracz->pieniadze -= bet;
	    }
	    std::cout << "\n";
}