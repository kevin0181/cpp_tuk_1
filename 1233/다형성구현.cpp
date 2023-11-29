//----------------------------------------------------------------------------------------
// ����������.cpp							
// 
// ã�ƺ��� �˾ƺ� ��
// 
//				- ������(Ploymorphism)�̶� �����ΰ�?
//				- C++ ������ ��� �������� �����ϴ°�?			
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

	// 1. ���� Ŭ������ ����
	ShapeManager sm(100);			// �ִ� 100���� ������ ������

	while (true) {
		
		// �� ���α׷��� ������Ʈ�� Ȯ���ϱ� ���� ���̴�.
		// �ǽ� ������� ������ �ذ��� ����.

		menu = new Menu(sm);
		cin >> num;
		menu->choice(num);

		// 2. �������� ���� Ŭ������ ������
		//sm.insert(new Triangle());
		//sm.insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
		//sm.insert(new Circle(Point(1.23, 4.56), 7.89));

		//for (int i = 0; i < 10; ++i) {
		//	sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
		//}

		//sm.insert(new Pentagon(Point(4, 4), Point(5, 5), Point(6, 6), Point(7, 7), Point(8, 8))); // 4�� ���� ���� ��.


		// 3. �����ϰ� �ִ� ��� ������ �׸�
		//sm.draw();

		// �� ���α׷����� �߸��� ���� ã�� �� �ִ°�?
		// �߸��� ���� ��� ã�� �� �ִ°�?

		//5.������ �� ShapeManager�� �Ҹ��ڰ� ���������� ȣ���̵Ǵµ� ���������� ȣ���� �ȵǴ°�?
	}
}