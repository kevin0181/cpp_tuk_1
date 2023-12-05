#pragma once

#include "Point.h"
#include "Shape.h"

class Pentagon : public Shape {
    Point p1, p2, p3, p4, p5;

public:
    Pentagon();

    Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5);

    ~Pentagon();

    virtual void draw() const override;

    virtual void saveDraw(std::ostream&) override;

    virtual const std::type_info &getType() const override;

    virtual void deleteF() override;
};