#include<iostream>
#include<random>
#include "Menu.h"
#include "Triangle.h"
#include "Circle.h"
#include "Point.h"
#include "Rectangle.h"
#include "Pentagon.h"


using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 1,100 };

Menu::Menu(ShapeManager& sma) {
	sm = sma;
	cout << "---------------Menu---------------" << endl;
	cout << " -  원하는 도형을 추가하세요." << endl;
	cout << "1. - 삼각형" << endl;
	cout << "2. - 사각형" << endl;
	cout << "3. - 오각형" << endl;
	cout << "4. - 원" << endl;
	cout << "---------------------------------" << endl;
	cout << "5. -  전체 도형을 그리기" << endl;
	cout << "6. -  프로그램 끝내기" << endl;
}

void Menu::choice(int num){

	switch (num)
	{
	case 1:
		sm.insert(new Triangle(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
		break;
	case 2:
		sm.insert(new Rectangle(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
		break;
	case 3:
		sm.insert(new Pentagon(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
		break;
	case 4:
		sm.insert(new Circle(Point(uid(dre), uid(dre)), uid(dre)));
		break;
	case 5:
		sm.draw();
		break;
	case 6:
		break;
	default:
		break;
	}
	
}