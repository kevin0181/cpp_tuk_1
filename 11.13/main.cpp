#include <iostream>
#include <string>
#include "STRING.h"

using namespace std;

int main() {

//    STRING::관찰 = true;
//    STRING s{"스트링"};
//    STRING::관찰 = false;
//
//    s = "2023년 11월 8일" + s;
//
//    cout << "s -";
//    s.show();

    STRING s{"C++ Programming Language"};
//     s.operator[] 에서 []는 indexOperator 라고함.
    qsort(&s[0], s.length(), sizeof(char), [](const void *a, const void *b) {
        return *(char *) a - *(char *) b;
    });

    for (int i = 0; i < s.length(); ++i) {
        cout << s[i] << ' ';
    }

    cout << '\n';
}