//----------------------------------------------------------------------------------------
// 다형성구현.cpp							
// 
// 찾아보고 알아볼 것
// 
//				- 다형성(Ploymorphism)이란 무엇인가?
//				- C++ 언어에서는 어떻게 다형성을 구현하는가?			
// 
// 2023.11.27
//----------------------------------------------------------------------------------------
#include<iostream>
#include "Point.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeManager.h"
#include "Pentagon.h"
#include "Menu.h"

using namespace std;
//-----------
int main() 
//-----------
{
	Menu* menu;
	int num{};

	// 1. 관리 클래스를 만듦
	ShapeManager sm(100);			// 최대 100개의 도형을 관리함

	while (true) {
		
		// 이 프로그램은 프로젝트를 확인하기 위한 것이다.
		// 실습 순서대로 문제를 해결해 보자.

		menu = new Menu(sm);
		cin >> num;
		menu->choice(num);

		// 2. 도형들을 관리 클래스에 삽입함
		//sm.insert(new Triangle());
		//sm.insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
		//sm.insert(new Circle(Point(1.23, 4.56), 7.89));

		//for (int i = 0; i < 10; ++i) {
		//	sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
		//}

		//sm.insert(new Pentagon(Point(4, 4), Point(5, 5), Point(6, 6), Point(7, 7), Point(8, 8))); // 4번 도형 성생 완.


		// 3. 관리하고 있는 모든 도형을 그림
		//sm.draw();

		// 이 프로그램에서 잘못된 점을 찾을 수 있는가?
		// 잘못된 점을 어떻게 찾을 수 있는가?

		//5.번에서 왜 ShapeManager은 소멸자가 정상적으로 호출이되는데 나머지들은 호출이 안되는가?
	}
}