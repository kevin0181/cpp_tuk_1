//-----------------------------------------------------------------------------
// MemoryMonster.cpp
// 
// Ư���� - Ȯ���� �޸��� ��� ����Ʈ ���� 1���� ��Ų��.
//-----------------------------------------------------------------------------
#include <iostream>
#include "MemoryMonster.h"

MemoryMonster::MemoryMonster( int n ) 
	: num( n )	
{
	p = new int[num];
	for ( int i = 0; i < num; ++i )
		p[i] = i;
}

MemoryMonster::~MemoryMonster()
{
	delete[] p;
}

void MemoryMonster::special()
{
	std::cout << "[" << id << "] : ��� int �� 1����" << '\n';

	for ( int i = 0; i < num; ++i )
		++p[i];
}

void MemoryMonster::show() const 
{
	std::cout << "MemoryMonster [" << id << "] - " << num << "�� �� ��� " << '\n';

	for ( int i = 0; i < num; ++i )
		std::cout << static_cast<int>(p[i]) << ' ';
	std::cout << '\n';
}

void MemoryMonster::operator++() {
	// �޸� ������ 1�� ������Ŵ
	for (int i = 0; i < num; ++i)
		++p[i];
}
