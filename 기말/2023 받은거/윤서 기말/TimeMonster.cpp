//-----------------------------------------------------------------------------
// TimeMonster.cpp 
//
// Ư���� - mSec �ð���ŭ CPU�� �����
//-----------------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <chrono>
#include "TimeMonster.h"

void TimeMonster::special() 
{
	using std::cout;
	using std::thread;

	cout << "[" << id << "] : CPU ���� - " << mSec << "ms" << '\n';

	std::this_thread::sleep_for( std::chrono::milliseconds( mSec ) );
}