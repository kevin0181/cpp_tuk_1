#pragma once

#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

class Circle : public Shape
{
public:
	virtual void draw() override
	{
		cout << id << " - ¿øÇü" << endl;
	}
};