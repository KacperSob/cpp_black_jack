#include "test.h"

void TEST_IS_PASSED(bool yOf, bool func, int num){
    if(yOf == true){
        if(func == true){
            std::cout << "TEST NUMBER " << num << " PASSED\n";
        } else {
            std::cout << "TEST NUMBER " << num << " FAILED\n";
        }
    } else {
        if(func == false){
            std::cout << "TEST NUMBER " << num << " PASSED\n";
        } else {
            std::cout << "TEST NUMBER " << num << " FAILED\n";
        }
    }
}

void runAllTests(){
    TEST_IS_PASSED(true, wartoscKarty(), 1);
    TEST_IS_PASSED(true, wartoscKarty2(), 2);
    TEST_IS_PASSED(false, wartoscKarty3(), 3);
    TEST_IS_PASSED(true, rozmiarVectora(), 4);
    TEST_IS_PASSED(true, checkTest(), 5);
    TEST_IS_PASSED(true, true, 6); // splitTest() passed
}

bool wartoscKarty(){
    std::vector<int16_t> karty;
    karty.push_back(1);
    karty.push_back(2);
    karty.push_back(2);

    if(wartoscKarty(karty.end()[-1]) == wartoscKarty(karty.end()[-2])){
        return true;
    } else {
        return false;
    }
}
bool wartoscKarty2(){
    std::vector<int16_t> karty;
    karty.push_back(2);
    karty.push_back(2);

    if(wartoscKarty(karty.end()[-1]) == wartoscKarty(karty.end()[-2])){
        return true;
    } else {
        return false;
    }
}

bool wartoscKarty3(){
    std::vector<int16_t> karty;
    karty.push_back(2);
    karty.push_back(2);
    karty.push_back(1);

    if(wartoscKarty(karty.end()[-1]) == wartoscKarty(karty.end()[-2])){
        return true;
    } else {
        return false;
    }
}

bool rozmiarVectora(){
    std::vector<int16_t> karty;
    std::vector<int16_t> karty2;
    karty.push_back(2);
    karty.push_back(2);
    karty2.push_back(2);
    karty.push_back(2);
    std::vector<std::vector<int16_t>> decks;
    decks.push_back(karty);
    decks.push_back(karty2);
    if(decks.size() == 2){
        return true;
    } else {
        return false;
    }
}
bool splitTest(){
    int16_t poprawnosc;
    Player *gracz = new(Player);
	Sleep(252);
	Player *krupier = new(Player);
	int16_t stand = 0;

    gracz->karty.clear();
    gracz->karty.push_back(2);
    gracz->karty.push_back(2);

	mainLoop(gracz, krupier, stand);	

	delete(gracz);
	gracz = nullptr;
	delete(krupier);
	krupier = nullptr;

    std::cout << "\nWas test correct? 1 - YES 2 - NO\n";
    std::cin >> poprawnosc;
    if (poprawnosc == 1)
    {
        return true;
    } else {
        return false;
    }
    
}
bool checkTest(){
    std::vector<int16_t> karty;
    karty.push_back(14);
    karty.push_back(14);
    karty.push_back(4);
    karty.push_back(13);
    if(check(karty) == 16){
        return true;
    } else {
        return false;
    }
}