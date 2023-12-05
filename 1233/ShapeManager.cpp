//----------------------------------------------------------------------------------------
// ShapeManager.cpp							여러 개의 도형을 관리하는 클래스
//
// 2023.11.27
//----------------------------------------------------------------------------------------

#include <iostream>
#include "ShapeManager.h"
#include "Menu.h"

using namespace std;

ShapeManager::ShapeManager() {}

//----------------------
ShapeManager::ShapeManager(int n)
//----------------------
{
    nShape = 0;                                // 처음 만들어질 때는 관리하는 도형 갯수가 0임
    capacity = n;                            // 최대 n개의 도형을 담을 수 있음
    shapes = new Shape *[capacity];
    deleteNShape = 0;
};


//----------------------
ShapeManager::~ShapeManager()
//----------------------
{
    // 아마 이 부분이 5번에 해당하는 부분인듯..?
//    for (int i = 0; i < capacity; ++i) {
//        delete shapes[i];
//    }

    // 모든 객체가 정확하게 삭제되는지 반드시 확인하여야 한다.
//    delete[] shapes;					// 도형관리자가 관리하는 도형의 소멸자를 호출함

    cout << "ShapeManager 소멸자 호출 (shapes 삭제)" << endl;
};

//----------------------
void ShapeManager::insert(Shape *a)
//----------------------
{
    if (nShape >= capacity) { // 도형 추가가 최대 크기에 도달 했을 경우
        changeNewArray(menu->addCapacitySize());
    } else {
        shapes[nShape] = a;
        nShape++;
    }
}

void ShapeManager::changeNewArray(int num) {
    if (num != 0) {
        Shape **newShapes = new Shape *[num]; //새로운 배열 생성

        // 기존 데이터를 새로운 배열로 복사
        for (int i = 0; i < capacity; ++i) {
            newShapes[i] = shapes[i];
        }
        // 기존 배열 삭제
        delete[] shapes;

        // 새로운 배열을 사용하도록 업데이트
        shapes = newShapes;
        capacity = num;
    }
}

//----------------------
void ShapeManager::draw() const
//----------------------
{
    cout << "---------------------------------------------" << '\n';
    cout << "관리하는 모든 도형을 그립니다." << '\n';
    cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다." << '\n';
    cout << "모두 " << (nShape - deleteNShape) << "개의 도형이 있습니다." << '\n';
    cout << "---------------------------------------------" << '\n' << '\n';

    for (int i = 0; i < nShape; ++i) {
        if (shapes[i] != nullptr) {
            cout << "[" << i + 1 << "] ";
            shapes[i]->draw();                // 다형성이 구현된다.
        }
    }

    cout << '\n';

    cout << "---------------------------------------------" << '\n';
    cout << "그리기를 마칩니다." << '\n';
    cout << "---------------------------------------------" << '\n' << '\n';

}


void ShapeManager::deleteShape(Shape *a) {
    for (int i = 0; i < nShape; ++i) {
        if (shapes[i] != nullptr && a->getType() == shapes[i]->getType()) {
            shapes[i]->deleteF();
            shapes[i] = nullptr;
            deleteNShape++;
        }
    }
}

void ShapeManager::deleteNumber(int num) {
    shapes[num - 1]->deleteF();
    shapes[num - 1] = nullptr;
    deleteNShape++;
}

Shape **ShapeManager::getShape() {
    return shapes;
}

int ShapeManager::getNShape() {
    return nShape;
}
