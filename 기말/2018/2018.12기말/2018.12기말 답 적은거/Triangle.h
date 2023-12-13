#pragma once
#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

class Triangle : public Shape
{
public:
	virtual void draw() override
	{
		cout << id << " - �ﰢ��" << endl;
	}
};