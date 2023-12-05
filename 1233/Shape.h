#pragma once
//----------------------------------------------------------------------------------------
// Shape.h					class Shape - Virtual Base Class
//							이 클래스는 추상 클래스(abstract class)이다.
// 2023.11.27
//----------------------------------------------------------------------------------------

//#ifndef _Shape							// _Shape이 앞에서 정의되지 않았다면
#define _Shape                            // _Shape을 정의한다.

#include<iostream>

class Shape {
public:
    Shape() {};

    ~Shape() {};

    virtual void draw() const = 0;

    virtual void saveDraw(std::ostream&) = 0;

    virtual const std::type_info &getType() const = 0; // 객체의 타입을 비교하기 위해서 만듬
    virtual void deleteF() = 0;
};
