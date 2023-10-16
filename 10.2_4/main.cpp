#include <iostream>

using namespace std;


int main() {
    // [문제] alpha를 오름차순으로 정렬하고 화면에 결과를 출력하라.
    char alpha[]{"the quick brown fox jumps over the lazy dog"};

    // 교수님 코드 ------------------------------

    int f(const void *a, const void *b);
    qsort(alpha, strlen(alpha), sizeof(char), f);

    cout << alpha << '\n';

}

int f(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}

