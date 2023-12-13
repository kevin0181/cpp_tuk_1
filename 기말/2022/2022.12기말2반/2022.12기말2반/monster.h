//-----------------------------------------------------------------------------
// Monster.h
//-----------------------------------------------------------------------------
#pragma once

#include "game.h"

class Monster : public Game {
	int hp;								// 몬스터의 체력

public:
	Monster();

	virtual void render() const override;
};
