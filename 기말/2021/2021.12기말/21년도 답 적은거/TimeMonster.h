//-----------------------------------------------------------------------------
// TimeMonster.h
//
// Ư���� - mSec �ð���ŭ CPU�� �����
//-----------------------------------------------------------------------------

#pragma once

#include "Monster.h"

class TimeMonster : public Monster {
	int mSec;							// ������ milli second

public:
	TimeMonster( int n ) : mSec( n ) 
	{

	}

	virtual void special() override;
};

