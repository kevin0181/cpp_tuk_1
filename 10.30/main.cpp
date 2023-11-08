#include<iostream>

using namespace std;

// [문제] 나는 MemoryMonster다. 생성 시 int값을 받아 그 값에 해당하는 메모리를
// Free-Store에 할당한 후, 모든 값을 1부터 시작하는 정수로 채운다.

class MemoryMonster {
public :
    int a;

    MemoryMonster(int num) {
        a = num;
    }

private:
    void show() {

    }
};

int main() {
    MemoryMonster a{100}; // Free store에 int 100개가 들어갈 공간을 확보한다.
    // 그 공간을 1, 2, 3, ..., 100으로 채운다.
    a.show(); // 1부터 100까지의 합계 = 5050 이라고 출력한다.
}