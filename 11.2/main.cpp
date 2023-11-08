#include<iostream>
#include<random>

using namespace std;

// [문제] 나는 MemoryMonster다. 생성 시 int값을 받아 그 값에 해당하는 메모리를
// Free-Store에 할당한 후, int 메모리의 값을 랜덤값 [1,9999]으로 채운다.

default_random_engine dre;
uniform_int_distribution uid{1, 9999};

class User { // 클래스 선언 순서임 표준!
public:
    User() { // 생성자

    }

    User(const User &) { //복사 생성자

    }

    //생략
    ~User() { //소멸자

    }

protected:
private:
};

//이렇게 하면 a 객체가 메모리 몬스터에 있는 값을 가져올 수 없음.
class MemoryMonster {
public :

    MemoryMonster(int num) {
        int *p = new int[num];
        for (int i = 0; i < num; ++i)
            p[i] = uid(dre);
    }

    // show 함수는 스페셜 함수를 다 사용 후, 쓸 수 있음
    // 이런 유형의 함수는 외부에 보낼 수 있는 함수이기때문에 인터페이스 함수라고함
    // interface function
    void show() {
        cout << "메모리 몬스터 - " << '\n';
    }

};

int main() {
    MemoryMonster a{100}; // Free store에 int 100개가 들어갈 공간을 확보한다.
    // 그 공간을 1, 2, 3, ..., 100으로 채운다.
    a.show(); // "메모리몬스터 - 100, 첫원소의 값 - 1352"
}