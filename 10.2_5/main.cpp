#include <iostream>

using namespace std;

int main() {
    int a[]{2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
    // a를 오름차순으로 정렬

    int f(const void *, const void *);
    qsort(a, 10, sizeof(int), f);

    for (int num : a){
        cout << num << ' ';
    }
}

int f(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}