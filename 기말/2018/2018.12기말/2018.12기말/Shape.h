#pragma once

#include <iostream>
using namespace std;

class Shape
{
	static int gid;
protected:
	int id;
public:
	Shape() : id(++gid){}

	virtual void draw() = 0;

};

int Shape::gid{ 0 };