//
// Created by 유영빈 on 2023/09/14.
//

#include "복습.h"
#include <iostream>
#include <vector>

using namespace std;

void 복습() {
    int array2[10]{1, 5, 2, 43, 5, 26, 17, 84, 91, 52}; // => 자료형 (int [10]) int를 10개 담은 자료형
    // 크기 => sizeof
    // 주소 => addressof
    // 자료형 => typeid(array2).name()
    // array2 => 의 주소와 array2[0]의 주소는 같다.

    // contiguous => 공간의 연속
    // continuous => 시간의 연속

    // 지정된 배열의 메모리 주소와 배열 자체의 메모리 주소는 같나? --> 같다.
    cout << addressof(array2) << '\n'; // 실질적으로 출력해보면 주소값이 같음 : 0x16b1e37d0
    cout << addressof(array2[0]) << '\n';// : 0x16b1e37d0

    // array2에 있는 값을 모두 출력하라. (반복문을 사용해서 0부터 9까지 돌려서 출력함)
    // (size()함수를 사용해서 array2의 배열의 크기값을 가져와서 for문을 돌림) (vector라는 라이브러리를 가져와야 사용가능)
//    for (int i = 0; i < size(array2); i++) {
//        cout << array2[i] << '\n';
//    } //이거 말고 그냥
//    for (int i = 0; i < sizeof(array2) / sizeof(int); i++) {
//        cout << array2[i] << '\n';
//    }
//    for (int i = 0; i < 10; i++) { //일케써도댐ㅋ
//        cout << array2[i] << '\n';
//    }

    for (int number: array2) { // 가장 많이 쓰는 for문
        cout << number << '\n';
    }

    // c++에서 사용할 배열 방식 =>
    array<int, 10> arrayC{1, 5, 2, 43, 5, 26, 17, 84, 91, 52};


    cout << sizeof(cout) << '\n'; //출력값 : 160byte
    cout << addressof(cout) << '\n'; // 출력값 : 0x1e8d54198
    cout << typeid(cout).name() << '\n'; //출력값 : NSt3__113basic_ostreamIcNS_11char_traitsIcEEEE

//    cout << sizeof(복습) << '\n'; // -> 이게 안되면서 알수있는것 => 함수는 메모리를 먹고있는게 아니다.
    cout << addressof(복습) << '\n'; // 출력값 : 1
    cout << typeid(복습).name() << '\n'; //출력값 : FvvE

}
