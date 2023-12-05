#pragma once
//----------------------------------------------------------------------------------------
// Point.h					Point class declaration - 헤더 파일은 언제나 공개되어야 한다.
//							2차원 좌표 (x,y)를 나타낸다.
//
// 2023.11.27
//----------------------------------------------------------------------------------------

//#ifndef _Point						// 한 번만 include 할 수 있도록 함
#define _Point						// 조건부 컴파일 - 구글링 할 것

struct Point
{
    double x, y;

    Point();
    Point(double, double);
    Point(const Point&) = default;

};