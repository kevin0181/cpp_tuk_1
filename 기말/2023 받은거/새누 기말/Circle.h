//-----------------------------------------------------------------------------
// Circle.h
//-----------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <format>
#include "Shape.h"

using std::cout;

struct Point {							// 2���� ��ǥ(x, y)
	int x;
	int y;
};


class Circle : public Shape {
	Point center{};						// �߽����� ��ǥ
	int rad{};							// ������

public:
	Circle( ) = default;
	Circle( Point c, int r ) : center{ c }, rad{ r } { }

	int getRad( ) const				// �������� �˷��ش�
	{
		return rad;
	}


	virtual void draw() const override 
	{
		cout << std::format( "[{:3d}] - ��, ",id )  
			<< std::format( "�߽���({:d}, {:d}), ", center.x, center.y ) 
			<< std::format( "������ - {:3d}", rad )
			<< '\n';
	}
};

