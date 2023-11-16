#include <iostream>
#include "STRING.h"
#include <algorithm>
#include <array> //? 시험은 내지 않아서 몰라도 상관없는데 앞으로는 무조건쓸것임.

//여기에서 중요한건 함수호출연산자를 오버로딩한 클래스인게 중요한듯..?

using namespace std;

//함수호출연산자()를 오버로딩한 "class 길이오름"은
//이제 함수처럼 호출할 수 있다.
//이런 class는 callable type이라고함.
//이러한 class의 객체를 다른말로 function object(functor)라고함
class 길이오름 {
public:
//    int operator()(const void *a, const void *b) const {       //함수호출연산자를 오버로딩
//        return static_cast<int> (((STRING *) a)->length() -     // STRING 을 가르키는 포인터 a에게 몇글자인지 물어봄
//                                 ((STRING *) b)->length());
//    }
    int operator()(const STRING &a, const STRING &b) const {       //함수호출연산자를 오버로딩
        return a.length() < b.length();
    }
};

int main() {

    //c++에서 쓰지 말아야 할 것 - [](배열), *(포인터)
    //대신 사용하는거 -> array, smart pointer
    STRING s[]{"오늘은", "수능시험일", "비가 오고있다.", "11월 16일", "나도 내년에 수능봐야지."};

    array<STRING, 5> s2{"오늘은", "수능시험일", "비가 오고있다.", "11월 16일", "나도 내년에 수능봐야지."};

    //s를 길이오름차순으로 정렬한다.
//    qsort(s2.data(), s2.size(), sizeof(STRING), [](const void *a, const void *b) {
//        return static_cast<int> (((STRING *) a)->length() -     // STRING 을 가르키는 포인터 a에게 몇글자인지 물어봄
//                                 ((STRING *) b)->length());
//    });

//    qsort(s2.data(), s2.size(), sizeof(STRING), 길이오름()); //-> 교수님왈 : c에서 사용하는거라 C++에서 사용하는건??

    // C++ 표준 라이브러리에서 정렬은 sort를 사용한다.
    sort(s2.begin(), s2.end(), 길이오름());

    길이오름 a;

    cout << boolalpha << a(s[1], s[0]) << endl;
    cout << boolalpha << a.operator()(s[1], s[0]) << endl; //사실 위에가 이문장임.

    for (const STRING &s: s2)
        cout << s << '\n';

}
