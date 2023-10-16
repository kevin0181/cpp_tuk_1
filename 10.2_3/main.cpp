#include <iostream>

using namespace std;

int f(const void *, const void *);

int main() {
    // [문제] alpha를 오름차순으로 정렬하고 화면에 결과를 출력하라.
    char alpha[]{"the quick brown fox jumps over the lazy dog"};

    // 내코드 ------------------------------

    qsort(alpha, sizeof(alpha) / sizeof(char), sizeof(char), f);

    for (int i = 0; i < sizeof(alpha) / sizeof(char); i++) {
        cout << alpha[i] << ' ';
    }

}


int f(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}