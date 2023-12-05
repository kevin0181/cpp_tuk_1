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
    Menu *menu;
    int num{};

    // 1. 관리 클래스를 만듦
    ShapeManager sm(10);            // 최대 100개의 도형을 관리함
    menu = new Menu(sm);
    while (true) {

        // 이 프로그램은 프로젝트를 확인하기 위한 것이다.
        // 실습 순서대로 문제를 해결해 보자.

        menu->qChoice();
        cin >> num;
        menu->choice(num);
        cout << endl << endl;

    }
}