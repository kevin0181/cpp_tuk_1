//-----------------------------------------------------------------------------
// MemoryMonster.h
//
// Ư���� - Ȯ���� num ����Ʈ �޸��� ��� ����Ʈ ���� 1���� ��Ų��
// show() - �޸��� ���� ȭ�鿡 ����Ѵ�
//-----------------------------------------------------------------------------
#pragma once

#include "Monster.h"

class MemoryMonster : public Monster {
	int num;							// ������ milli second
	char* p;

public:
	MemoryMonster( int n );
	~MemoryMonster();

	virtual void special() override;

	void show() const;					// �޸��� ������ ȭ�� ����Ѵ�
};


