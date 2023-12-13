//-----------------------------------------------------------------------------
// Monster.cpp
//-----------------------------------------------------------------------------
#include <iostream>
#include <random>
#include "game.h"
#include "monster.h"

std::default_random_engine dreMonster{ 202202 };
std::uniform_int_distribution<> uiHpMonster( 50, 100 );			// 몬스터의 체력

Monster::Monster() 
{
	hp = uiHpMonster( dreMonster );
}

void Monster::render() const 
{
	std::cout << "몬스터  , 체력 - " << hp << std::endl;
};
