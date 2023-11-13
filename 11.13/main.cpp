#include <iostream>
#include <string>
#include "STRING.h"

using namespace std;

// [할 일] 클래스 STRING을 main()과 같이 코딩하는 건 아니다.
// STRING의 선언부분을 STRING.h
// STRING의 정의부분을 STRING.cpp
// 파일 분리한다.


int main() {

    STRING::관찰 = true;
    STRING s{"나는 표준 string"};
    STRING t = move(s);               // C++11 이동생성

    cout << "s -";
    s.show();
    cout << "t -";
    t.show();

}