#include <iostream>

using namespace std;

int cnt{};

void f(string);

int main() {
    f("시험중");
}

void f(string msg) {
    cout << msg << " " << ++cnt;
    f(msg);
}
