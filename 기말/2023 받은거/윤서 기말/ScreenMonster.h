//-----------------------------------------------------------------------------
// ScreenMonster.h
//
// Ư���� - ������ ���ĺ� ���� n���� ȭ�鿡 ����Ѵ�
//-----------------------------------------------------------------------------

#pragma once

#include "Monster.h"

class ScreenMonster : public Monster {
	int n;							

public:
	ScreenMonster( int n ) : n{ n } {

	}

	virtual void special() override;
};

