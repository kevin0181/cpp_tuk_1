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

class MemoryMonster {
    int size;
    int *p;
public :

    MemoryMonster() {

    }

    MemoryMonster(int num) : size{num} {
        p = new int[size];
        for (int i = 0; i < num; ++i)
            p[i] = uid(dre);
        cout << "생성(" << num << ") - " << p[0] << '\n';
    }

    MemoryMonster(const MemoryMonster &other) : size(other.size) { //복사 생성자 (객체 크기가 1,2,4,8바이트가 아니고 훨신 커서 주소로 가져와야댐) 약속임
        p = new int[size];
//        for (int i = 0; i < size; ++i) // -> 메모리 이렇게 카피하면 안됨 메모리 누수나는듯?
//            p[i] = other.p[i];
        //DMA 를 사용해서 메모리를 카피함 (고속 메모리 복사?)
        memcpy(p, other.p, size * sizeof(int)); //얘보다 빠른 명령어는 없음 메모리 블락 카피할때는 젤빠른듯
        cout << "복사 생성(" << size << ") - " << p[0] << '\n';
    }

    // show 함수는 스페셜 함수를 다 사용 후, 쓸 수 있음
    // 이런 유형의 함수는 외부에 보낼 수 있는 함수이기때문에 인터페이스 함수라고함
    // interface function
    void show() const {
        cout << "메모리 몬스터 - " << size << ", 첫 원소값 - " << p[0] << '\n';
    }

    ~MemoryMonster() {
        cout << "소멸 - " << size << " - " << p[0] << '\n';
        delete[] p;
    }
};

int main() {
//    MemoryMonster a{100};
//    MemoryMonster b{a};
//    MemoryMonster b = a; // -> 복사 생성하는 동작이다~~~
//    MemoryMonster c;

    const int num = 0; //한정사 -> 초기값을 정해주고 읽기만 가능

    MemoryMonster mons[]{1, 3, 5};
    cout << "\n\n\n";
    for (const MemoryMonster &mon: mons)
        mon.show();
    cout << "\n\n\n";

//    for (int i = 0; i < 3; ++i) { // 이렇게 안쓰는 이유가 뭐징
//        mons[i].show();
//    }

}