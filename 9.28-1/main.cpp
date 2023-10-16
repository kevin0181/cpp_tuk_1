//------------------------------------------------------------------------------------------
// 2023. 2학기 C++ 9월 28일 월요일                         월56목34      (4주 2일)
//------------------------------------------------------------------------------------------
// sort - bubble sort
//------------------------------------------------------------------------------------------
// [과제] 정렬 관련 내용을 구글에서 찾아보기
//------------------------------------------------------------------------------------------

#include <iostream>
#include <random>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid{1, 10'0000};

void change(int &, int &); // 함수 선언문

int main() {
    const int NUM{1'0000};
    int a[NUM];
    // a를 랜덤값으로 채우자.
    for (int i = 0; i < NUM; ++i) {
        a[i] = uid(dre);
    }

    // [문제] a를 내림차순(descending order)으로 정렬하라.
    for (int j = 0; j < NUM - 1; j++) {
        for (int i = 0; i < NUM - j - 1; i++) {
            if (a[i] < a[i + 1]) {
                change(a[i], a[i + 1]);
            }
        }
    }

    // a array 출력
    for (int num: a) {
        cout << num << ' ';
    }
    cout << endl;

}

void change(int &a, int &b) { // function definition 함수 정의
    int t{a};
    a = b;
    b = t;
}