#include "karty.h"

int16_t wszystkieKarty[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

int16_t randKarta() {
    return wszystkieKarty[rand() % 13];
}