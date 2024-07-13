#include "player.h"

void Player::hit() {
    this->karty.push_back(randKarta());
}

Player::Player(){
	Player::hit();
	Player::hit();
}

Player::Player(int32_t pieniadze){
    this->pieniadze = pieniadze;
	Player::hit();
	Player::hit();
}

void pStand(Player* krupier){
	std::vector<int16_t> kKarty = krupier->karty;
	int sum = 0;
	for (int16_t kartaK : kKarty)
	{
		sum += kartaK;
	}
	if (sum < 17) {
		krupier->hit();
	}
}