//-----------------------------------------------------------------------------
// Player.h
//-----------------------------------------------------------------------------
#pragma once

#include "game.h"

class Player : public Game {
	int nation;							// 접속국가 0 - Korea,  1 - Japan, 2 - China
	int hp;								// 체력

public:
	Player(); 

	virtual void render() const override;

	void setHp( int n );				// 체력을 set

	int getHp() const;					// 체력을 get

	int getNation() const;				// 어느 나라인가?
};

