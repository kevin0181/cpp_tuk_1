#pragma once
//----------------------------------------------------------------------------------------
// Triangle.h				세 점으로 삼각형을 정의할 수 있다.
// 
// 2023.11.27
//----------------------------------------------------------------------------------------

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape {
    Point p1, p2, p3;
public:
    Triangle();

    Triangle(const Point &, const Point &, const Point &);

    Triangle(const Triangle &);

    ~Triangle();

    virtual void draw() const override;            // virtual function을 overriding

    virtual void saveDraw(std::ostream&) override;

    virtual const std::type_info &getType() const override;

    virtual void deleteF() override;

};