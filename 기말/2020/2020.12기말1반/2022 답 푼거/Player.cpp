#include <random>
#include "player.h"
#include <iostream>

std::default_random_engine drePlayer;
std::uniform_int_distribution<int> nationUid{ 0,2 };
std::uniform_int_distribution<int> hpUidPlayer{ 0,100 };

Player::Player() {
	nation = nationUid(drePlayer);
	hp = hpUidPlayer(drePlayer);
}

void Player::render() const {
	std::cout << "Player - ±¹°¡ : " << nation << ", hp : " << hp << std::endl;
}