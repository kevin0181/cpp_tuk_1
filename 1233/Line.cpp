//
// Created by 유영빈 on 2023/12/05.
//

#include <iostream>
#include "Line.h"

Line::Line() {

}

Line::~Line() {

}

Line::Line(const Point &p1, const Point &p2) : start(p1), end(p2) {

}

void Line::draw() const {
    std::cout << "선 - (" << start.x << "," << start.y << "), ("
              << end.x << "," << end.y << ")" << '\n';
}

void Line::saveDraw(std::ostream &os) {
    os << "선 - (" << start.x << "," << start.y << "), ("
       << end.x << "," << end.y << ")" << '\n';
}

const std::type_info &Line::getType() const {
    return typeid(Line);
}


void Line::deleteF() {
    delete this;
}