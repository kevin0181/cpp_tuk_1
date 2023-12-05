//----------------------------------------------------------------------------------------
// Triangle.cpp
//
// 2023.11.27
//----------------------------------------------------------------------------------------
#include <iostream>
#include "Triangle.h"

Triangle::Triangle() : p1(), p2(), p3() {};

Triangle::Triangle(const Point &a, const Point &b, const Point &c) : p1(a), p2(b), p3(c) {

};

Triangle::Triangle(const Triangle &other) : p1(other.p1), p2(other.p2), p3(other.p3) {

};

Triangle::~Triangle() {
//    std::cout << "Triangle 소멸자 호출" << std::endl; // 배열에서 지워질때 호출됨.
};

void Triangle::draw() const {
    std::cout << "삼각형 - (" << p1.x << "," << p1.y << "), ("
              << p2.x << "," << p2.y << "), ("
              << p3.x << "," << p3.y << ")" << '\n';
};

void Triangle::saveDraw(std::ostream &os) {
    os << "삼각형 - (" << p1.x << "," << p1.y << "), ("
       << p2.x << "," << p2.y << "), ("
       << p3.x << "," << p3.y << ")" << '\n';
}

const std::type_info &Triangle::getType() const {
    return typeid(Triangle);
}

void Triangle::deleteF() {
    delete this;
}
