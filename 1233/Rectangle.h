#pragma once
//----------------------------------------------------------------------------------------
// Rectangle.h						대각선에 있는 점 2개로 사각형을 정의할 수 있다.				
// 
// 2023.11.27
//----------------------------------------------------------------------------------------
#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape {
    Point p1, p2;
public:
    Rectangle();

    Rectangle(const Point &, const Point &);

    Rectangle(const Rectangle &);

    ~Rectangle();

    virtual void draw() const override;

    virtual void saveDraw(std::ostream&) override;

    virtual const std::type_info &getType() const override;

    virtual void deleteF() override;

};