//------------------------------------------------------------------------------------------
// 2023. 2학기 C++ 9월 28일 월요일                         월56목34      (4주 2일)
//------------------------------------------------------------------------------------------
// sort - qsort
//------------------------------------------------------------------------------------------
// [과제] 정렬 관련 내용을 구글에서 찾아보기
//------------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid{1, 99'9999};

int f(const void *a, const void *b);

int main() {
    // [문제] 랜덤값을 갖는 int 100만개를 생성하라.
    // 100만개의 int를 오름차순으로 정렬하라.
    // 정렬한 int 중 앞에서 10개를 출력하라.
    // 정렬한 int 중 뒤에서 10개를 출력하라.

    // 교수님 코드 ---------------------------------------------------
    const int NUM{100'0000};
    int numbers[NUM];

    for (int &num: numbers)
        num = uid(dre);


    qsort(numbers, NUM, sizeof(int), f);

    cout << "오름차순으로 정렬 후 앞에서 10개" << '\n';
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }

    cout << '\n';

    cout << "오름차순으로 정렬 후 뒤에서 10개" << '\n';

    for (int i = 0; i < 10; i++) {
        cout << numbers[NUM - 1 - i] << ' ';
    }

    cout << '\n';

}

int f(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}