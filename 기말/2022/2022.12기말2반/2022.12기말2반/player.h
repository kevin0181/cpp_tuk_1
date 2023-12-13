//-----------------------------------------------------------------------------
// Player.h
//-----------------------------------------------------------------------------
#pragma once

#include "game.h"

class Player : public Game {
	int nation;							// ���ӱ��� 0 - Korea,  1 - Japan, 2 - China
	int hp;								// ü��

public:
	Player(); 

	virtual void render() const override;

	void setHp( int n );				// ü���� set

	int getHp() const;					// ü���� get

	int getNation() const;				// ��� �����ΰ�?
};

