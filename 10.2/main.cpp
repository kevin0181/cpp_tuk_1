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
uniform_int_distribution uid{1, 99};

int custom_sort(const void *, const void *);

int main() {

    const int NUM{100};
    int a[NUM];

    // [문제] C언어의 qsort를 사용하여 a를 내림차순으로 정렬하라.

    for (int i = 0; i < NUM; ++i) {
        a[i] = uid(dre);
    }

    qsort(a, NUM, sizeof(int), custom_sort);

    for (int num: a) {
        cout << num << ' ';
    }
    cout << endl;

}

int custom_sort(const void *a, const void *b) { //const -> 이 원소의 값을 수정할 수 없다.
    int *p = (int *) a;
    int *q = (int *) b;
    if (*p < *q)
        return 1;
    else if (*p > *q)
        return -1;

    return 0;
}