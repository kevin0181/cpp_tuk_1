//-----------------------------------------------------------------------------
// TimeMonster.h
//
// Ư���� - mSec �ð���ŭ CPU�� �����
//-----------------------------------------------------------------------------

#pragma once

#include "Monster.h"

class TimeMonster : public Monster {
	int mSec;							// mSec �ð����� CPU�� �����, ������ 1/1000��

public:
	TimeMonster( int n ) : mSec( n ) {

	}

	virtual void special() override;
};

