//-----------------------------------------------------------------------------
// Game.h
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>

class Game {
public:
	Game() = default;

	Game( const Game& ) {
		std::cout << "이 문장이 출력되면 문제있는 곳이 있나 살펴 보자" << std::endl;
	}

	virtual void render() const = 0;
};

