//-----------------------------------------------------------------------------
// Game.h
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <string>
class Game {
	
public:
	Game() = default;

	Game( const Game& ) {
		std::cout << "�� ������ ��µǸ� ���캸��" << std::endl;
	}
	virtual void render() const = 0;
};