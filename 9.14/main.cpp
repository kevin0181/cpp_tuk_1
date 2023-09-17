//------------------------------------------------------------------------------------------
// 2023. 2학기 C++ 9월 14일 월요일                         월56목34      (2주 2일)
//------------------------------------------------------------------------------------------
// int n; 의 의미 - sizeOf, addressOf, typeId(id).name()
//------------------------------------------------------------------------------------------
// [과제] 공부한 내용 반복 해서 실행 가능 하도록 하자
//------------------------------------------------------------------------------------------
#include <iostream>
#include <format>
#include <random>  // 랜덤엔진과 분포를 사용한다.
#include "복습.cpp"

using namespace std;

default_random_engine dre; //랜덤 숫자를 생성하는 엔진
uniform_int_distribution uid{1, 999}; // 숫자 1부터 999까지 가공해줘. (확률 분포를 조작하는 객체)

//int numbers[100]; // 전역 선언 : 0으로 전체 초기화해서 줌

int main() {

//    복습();

//    int numbers[100]; //=> 지역 선언 : 임의의 값들이 들어가 있음. 즉 -> 메모리만 줌
// 근데 만약에 전역에 선언한것 처럼 깨끗하게 초기화 하고싶다면? 다음과 같이 작성
    int numbers[100]{}; // 배열을 초기화함



    // 랜덤 값으로 채울거임
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        numbers[i] = uid(dre);
    }
    for (int num: numbers) { // 범위 기반 for 문
        cout << num << '\t';
//        cout << format("{:4d}",num) << '\n'; 왜 안될까
    }

    std::cout << std::format("Hello {}!\n", "world");

    cout << '\n';

    int maxInt = 0;
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        if (maxInt < numbers[i]) {
            maxInt = numbers[i];
        }
    }

    cout << "가장 큰 값 : " << maxInt << '\n';


    //교수님이 짠 코드
    int value{numeric_limits<int>::min()};
    for (int num: numbers) { // 범위 기반 for 문
        if (value < num) {
            value = num;
        }
    }
    cout << "가장 큰 값 : " << value << '\n';


}
