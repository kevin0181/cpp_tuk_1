#include"monster.h"
#include <iostream>
#include<random>

std::default_random_engine dreMonster;
std::uniform_int_distribution<int> hpUidMonster{ 0,100 };

Monster::Monster(){
	hp = hpUidMonster(dreMonster);
}

void Monster::render() const {
	std::cout << "Monster - hp : " << hp << std::endl;
}