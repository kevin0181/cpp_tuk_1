#include<iostream>
#include "Pentagon.h"

Pentagon::Pentagon() :p1(), p2(), p3(), p4(), p5() {

};

Pentagon::Pentagon(const Point& a, const Point& b, const Point& c, const Point& d, const Point& e):p1(a), p2(b), p3(c), p4(d), p5(e) {

};

Pentagon::~Pentagon() {
	std::cout << "Pentagon �Ҹ��� ȣ��" << std::endl;
}

void Pentagon::draw() const {
	std::cout << "������ - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << "), (" 
		<< p3.x << "," << p3.y << "), ("
		<< p4.x << "," << p4.y << "), ("
		<< p5.x << "," << p5.y << ")"
		<< '\n';
}