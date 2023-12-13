//-----------------------------------------------------------------------------
// ScreenMonster.cpp
//
// Ư���� - n���� ������ ���ĺ� ���ڸ� ȭ�鿡 ����Ѵ�
//-----------------------------------------------------------------------------

#include <iostream>
#include <random>
#include "ScreenMonster.h"

std::default_random_engine dre{ 202312 };
std::uniform_int_distribution<int> uiLower{ 'a', 'z' };
std::uniform_int_distribution<int> uiUpper{ 'A', 'Z' };
std::uniform_int_distribution<int> uiEvenOdd{ 0, 1 };

void ScreenMonster::special()
{
	std::cout << "[" << id << "] : ���� --> ";

	char c;

	for ( int i = 0; i < n; ++i ) {
		if ( uiEvenOdd( dre ) == 0 )
			c = uiLower( dre );
		else
			c = uiUpper( dre );
		std::cout << c;
	}
	std::cout << '\n';
}