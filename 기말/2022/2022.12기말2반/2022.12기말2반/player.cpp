//-----------------------------------------------------------------------------
// Player.cpp
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <random>
#include "game.h"
#include "player.h"

//enum class Nation { Korea = 0, Japan, China };	// �ð��� ������ enum class�� ������ ����
enum Nation { Korea = 0, Japan, China };			// ���ӱ���
std::string nations[3]{ "�ѱ�", "�Ϻ�", "�߱�" };

std::default_random_engine drePlayer{ 202201 };
std::uniform_int_distribution<> uiHpPlayer( 50, 100 );		// �÷��̾��� HP ��
std::uniform_int_distribution<> uiNation( 0, 2 );			// ���ӱ���

Player::Player() 
{
	nation = uiNation( drePlayer );
	hp = uiHpPlayer( drePlayer );
}

void Player::render() const 
{
	std::cout << "�÷��̾�, ü�� - " << hp << ", ���� - " << nations[nation] << std::endl;
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
