//----------------------------------------------------------------------------------------
// Rectangle.cpp
//
// 2023.11.27
//----------------------------------------------------------------------------------------
#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : p1(), p2() {

};

Rectangle::Rectangle(const Point &a, const Point &b) : p1(a), p2(b) {

};

Rectangle::Rectangle(const Rectangle &other) : p1(other.p1), p2(other.p2) {

};

Rectangle::~Rectangle() {
//    std::cout << "Rectangle 소멸자 호출" << std::endl;
};

void Rectangle::draw() const {
    std::cout << "사각형 - (" << p1.x << "," << p1.y << "), ("
              << p2.x << "," << p2.y << ")" << '\n';
};

void Rectangle::saveDraw(std::ostream &os) {
    os << "사각형 - (" << p1.x << "," << p1.y << "), ("
       << p2.x << "," << p2.y << ")" << '\n';
}

const std::type_info &Rectangle::getType() const {
    return typeid(Rectangle);
}


void Rectangle::deleteF() {
    delete this;
}