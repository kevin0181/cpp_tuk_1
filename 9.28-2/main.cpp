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
uniform_int_distribution uid{1, 10'0000};

int custom_sort(const void *, const void *);

int main() {

    const int NUM{200};
    int a[NUM];
    
    // a를 랜덤값으로 채우자.
    for (int i = 0; i < NUM; ++i) {
        a[i] = uid(dre);
    }

    // [문제] a를 정렬하라
    // 정렬할 대상의 수가 NUM개가 있다.
    // 비교연산의 횟수가 많아진다면? 1억번이라면?
    // 비교연산의 횟수를 줄이기 위해 qsort
    // 실제로 버블 정렬을 사용하지 않는 이유는 속도가 느리고 비교연산 또한 많아진다.!!
    qsort(a, NUM, sizeof(int), custom_sort);


    // a array 출력
    for (int num: a) {
        cout << num << ' ';
    }
    cout << endl;

}

int custom_sort(const void *a, const void *b) { //여기서 void는 무슨형식으로 받아올지 몰라서 void로 받아옴
    int *p = (int *) a;
    int *q = (int *) b;
    if (*p > *q)
        return 1; // 바꾸라는 표시
    else if (*p < *q)
        return -1; //안바꿔도된다는 표시

    return 0; //이도저도아님
}
