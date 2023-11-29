//----------------------------------------------------------------------------------------
// ShapeManager.cpp							여러 개의 도형을 관리하는 클래스				
// 
// 2023.11.27
//----------------------------------------------------------------------------------------

#include <iostream>
#include "ShapeManager.h"
using namespace std;

ShapeManager::ShapeManager(){}

//----------------------
ShapeManager::ShapeManager(int n)
//----------------------
{
	nShape = 0;								// 처음 만들어질 때는 관리하는 도형 갯수가 0임
	capacity = n;							// 최대 n개의 도형을 담을 수 있음
	shapes = new Shape * [capacity];
};


//----------------------
ShapeManager::~ShapeManager()
//----------------------
{
	// 아마 이 부분이 5번에 해당하는 부분인듯..?
	for (int i = 0; i < capacity; ++i) {
		delete shapes[i];
	}

	// 모든 객체가 정확하게 삭제되는지 반드시 확인하여야 한다.
	delete[] shapes;					// 도형관리자가 관리하는 도형의 소멸자를 호출함
	
	cout << "ShapeManager 소멸자 호출 (shapes 삭제)" << endl;
};

//----------------------
void ShapeManager::insert(Shape* a)
//----------------------
{
	shapes[nShape] = a;
	nShape++;
}

//----------------------
void ShapeManager::draw() const
//----------------------
{
	cout << "---------------------------------------------" << '\n';
	cout << "관리하는 모든 도형을 그립니다." << '\n';
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다." << '\n';
	cout << "모두 " << nShape << "개의 도형이 있습니다." << '\n';
	cout << "---------------------------------------------" << '\n' << '\n';
	
	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i+1 << "] ";
		shapes[i]->draw();				// 다형성이 구현된다.
	}
	
	cout << '\n';

	cout << "---------------------------------------------" << '\n';
	cout << "그리기를 마칩니다." << '\n';
	cout << "---------------------------------------------" << '\n' << '\n';

}