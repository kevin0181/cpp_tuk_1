#pragma once
//----------------------------------------------------------------------------------------
// Rectangle.h						�밢���� �ִ� �� 2���� �簢���� ������ �� �ִ�.				
// 
// 2023.11.27
//----------------------------------------------------------------------------------------
#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape {
	Point p1, p2;
public:
	Rectangle();
	Rectangle(const Point&, const Point&);
	Rectangle(const Rectangle&);
	~Rectangle();
	virtual void draw() const override;
};
