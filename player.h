#include <cstdint>
#include "karty.h"

class Player {
public:
    std::vector<int16_t> karty; //this wskazuje na klase
    int32_t pieniadze = 100;
public:
    Player();
    Player(int32_t pieniadze);
    void hit();
};

void pStand(Player* krupier);