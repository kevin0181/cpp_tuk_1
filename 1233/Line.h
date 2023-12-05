//
// Created by 유영빈 on 2023/12/05.
//

#ifndef INC_2_LINE_H
#define INC_2_LINE_H

#include "Point.h"
#include "Shape.h"

class Line : public Shape {
    Point start, end;

public:
    Line();

    ~Line();

    Line(const Point &, const Point &);

    virtual void draw() const override;

    virtual void saveDraw(std::ostream &) override;

    virtual const std::type_info &getType() const override;

    virtual void deleteF() override;
};


#endif //INC_2_LINE_H
