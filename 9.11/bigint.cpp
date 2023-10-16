//
// Created by 유영빈 on 2023/09/11.
//

#include "bigint.h"
#include <iostream>

using namespace std;

void bigint() {
    //int 의 역할
    int n = 0x7f'ff'ff'ff; // -> 이렇게도 최대값 출력가능
    n = n + 1; // => 최솟값
    int j = 0x80000000; // 이렇게는 x, 이유 :
    long j2 = 0x80000000;
    long j3 = 0x7f'ff'ff'ff;
    j2 = j2 + 1;
    j3 = j3 + 1;
    int k_max = numeric_limits<int>::max(); // 최대값
    int k_min = numeric_limits<int>::min(); // 최대값

    //[문제] n에 저장할 수 있는 최댓값을 출력하라?
//    cout << INT_MAX << '\n';
//    //[문제] n에 최소값?
//    cout << INT_MIN << '\n';
    cout << j << '\n';
    cout << j2 << '\n';
    cout << j3 << '\n';
    cout << LONG_MAX << '\n';

    // 할당 및 초기화
//    int n = 123;        //초기화 - initialization
//    int k;
//    k = 123;            //할당, 배정, 대입 - assignment
//    cout << n << '\t' << k << '\n';


    // int 배열
    // int [10] -> contiguous (4byte 짜리 10개)
    int array1[10];
    cout << typeid(array1).name() << '\n';


    //[문제] n의 값 중 가장 큰 값을 찾아 화면에 출력하라.
    int array2[10]{1, 5, 2, 43, 5, 26, 17, 84, 91, 52};
    int maxData = 0; // 값 하나하나 비교할거라 가장 낮은 값으로 초기화
    for (int i = 0; i < 10; i++) { // array2라는 배열을 0번부터 9번까지 반복함
        if (maxData < array2[i]) { // 만약 maxData가 array2배열에 하나씩 비교해서 maxData가 더 작으면?
            maxData = array2[i];    // maxData에 비교한 값을 넣음
        }
    } // 반복문이 끝나면? maxData에는 가장 큰값이 있음.

    cout << "가장 큰 수는 : " << maxData << '\n';
}
