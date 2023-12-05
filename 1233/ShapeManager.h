#pragma once

//----------------------------------------------------------------------------------------
// ShapeManager.h							여러 개의 도형을 관리하는 클래스
// 
// -------------------------------------------------------------------------
// Shape* (부모 클래스의 *)로 전체 도형을 관리하는 것이 핵심
// -------------------------------------------------------------------------					
// 
// 2023.11.27
//----------------------------------------------------------------------------------------
class Menu; //단방향 맵핑을 위해서.

#include "Shape.h"

class ShapeManager {
    Menu *menu;                 // 단방향
    int deleteNShape;               // 삭제된 도형의 개수
    int nShape;                        // 현재 관리 중인 도형의 갯수
    int capacity;                    // 확보한 메모리에 담을 수 있는 도형의 최대 개수
    Shape **shapes;                    // 도형의 포인터들을 담을 수 있는 메모리
public:
    ShapeManager();

    explicit ShapeManager(int n);    // 담을 수 있는 도형의 갯수를 생성자에 전달
    // explicit 사용법을 알아보자
    // explicit -> 한정자 중 하나, 명시적 형변환을 강제로하며, 암시적 변환을 방지함.
    ~ShapeManager();

    ShapeManager(const ShapeManager &) = default; // 이거 왜있는거지..? 복사생성자 기본으로?

    void insert(Shape *);            // 도형을 추가하는 함수
    void draw() const;                // 전체 도형을 그리는 함수

    void deleteShape(Shape *);        // 도형을 삭제하는 함수 //여기서 알아야 하는점 Shape를 상속받는 모든 도형들을 가져오기 위해서는 *을 사용해야지 가능함
    void deleteNumber(int);         // 번호에 해당하는 도형을 삭제하는 함수
    void updateSize();              // 배열 길이 업데이트
    void changeNewArray(int num);   // 새로운 배열 생성

    Shape **getShape();

    int getNShape();
};
