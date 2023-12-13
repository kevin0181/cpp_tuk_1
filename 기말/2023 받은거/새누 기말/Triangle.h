//-----------------------------------------------------------------------------
// Triangle.h
//-----------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <format>
#include "Shape.h"

using std::cout;


class Triangle : public Shape {
public:
	virtual void draw() const override 
	{
		std::cout << std::format( "[{:3d}] - »ï°¢Çü", id ) << '\n';
	}
};
