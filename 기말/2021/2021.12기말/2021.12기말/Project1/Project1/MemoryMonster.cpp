//-----------------------------------------------------------------------------
// MemoryMonster.cpp
//-----------------------------------------------------------------------------
#include <iostream>
#include "MemoryMonster.h"

MemoryMonster::MemoryMonster( int n ) : num( n )	
{
	p = new char[num];
	for ( int i = 0; i < num; ++i )
		p[i] = 0;
}

MemoryMonster::~MemoryMonster()
{
	delete[] p;
}

void MemoryMonster::special()
{
	std::cout << "[" << id << "] : �� ++" << std::endl;

	for ( int i = 0; i < num; ++i )
		++p[i];
}

void MemoryMonster::show() const 
{
	std::cout << "[" << id << "] - �� ��� " << std::endl;

	for ( int i = 0; i < num; ++i )
		std::cout << static_cast<int>(p[i]) << ' ';
	std::cout << std::endl;
}