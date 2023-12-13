//-----------------------------------------------------------------------------
// Player.cpp
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <random>
#include "game.h"
#include "player.h"

//enum class Nation { Korea = 0, Japan, China };	// 시간이 남으면 enum class를 공부해 보자
enum Nation { Korea = 0, Japan, China };			// 접속국가
std::string nations[3]{ "한국", "일본", "중국" };

std::default_random_engine drePlayer{ 202201 };
std::uniform_int_distribution<> uiHpPlayer( 50, 100 );		// 플레이어의 HP 값
std::uniform_int_distribution<> uiNation( 0, 2 );			// 접속국가

Player::Player() 
{
	nation = uiNation( drePlayer );
	hp = uiHpPlayer( drePlayer );
}

void Player::render() const 
{
	std::cout << "플레이어, 체력 - " << hp << ", 국가 - " << nations[nation] << std::endl;
}

void Player::setHp( int n ) {
	hp = n;
}

int Player::getHp() const {
	return hp;
}

int Player::getNation() const {
	return nation;
}
