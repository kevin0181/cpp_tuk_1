#include <iostream>

using namespace std;

// [문제] std::string은 c언어의 char*를 대체한다.
// 이와 유사한 기능을 하는 STRING을 직접 코딩하여 사용자정의자료형을 더 깊게 이해한다.
// main이 문제없이 실행되도록 코딩하라.

class STRING {
private:
    int size; // size_t type으로 변경해도됨 size-> size_t타입임
    char *p;
public:
    STRING(const char *s) : size{static_cast<int>((strlen(s)))} {
        p = new char[size];
        memcpy(p, s, size);
        cout << "STRING(char*) - " << size << ", 번지 - " << (void *) p << endl;
    }

    //복사 생성자
    STRING(const STRING &other) : size(other.size) {
        p = new char[size];
        memcpy(p, other.p, size);
        cout << "STRING(const STRING&) - " << size << ", 번지 - " << (void *) p << endl;
    }

    //복사할당연산자
    // 복사생성자와 짝이 되는 복사할당 연산자를 반드시 코딩해야한다.
    STRING &operator=(const STRING &other) { // t=t=t=t=t 이런걸 막기위해 나를 나로 할당하는걸 방지해야댐
        if (this == &other)
            return *this;

        delete[] p;
        size = other.size;
        p = new char[size];
        memcpy(p, other.p, size);
        cout << "operator = (const STRING&) - " << size << ", 번지 - " << (void *) p << endl;
        return *this;
    }

    // C++11 이동생성자와 이동할당연산자
    //이동생성자     // && -> r-value reference, 이동(move)과 완벽전달(perfect forwarding)에 사용한다.
    STRING(STRING &&other) : size{other.size} {
        // other의 자원을 가져온다.
        p = other.p;
        // other를 초기화 (초기화를 무조건 해줘야지 돌아감)이유는..??
        other.size = 0;
        other.p = nullptr;
//        other = nullptr; //-> 이건 왜 안댐..?

        cout << "STRING(STRING&&) - " << size << ", 번지 - " << (void *) p << endl;
    }

    STRING operator+(const STRING &other) {
        //코딩하여 + 동작을 완성하자.
    }

    ~STRING() {
        cout << "~STRING() - " << size << ", 번지 - " << (void *) p << endl;
        delete p;
    }

    void show() const {
        for (int i = 0; i < size; ++i) {
            cout << p[i];
        }
        cout << endl;
    }
};

int main() {

//    STRING s{"안녕하세요. 나는 스트링입니다."};
//    STRING t = s;

//    STRING s{"안녕하세요. 나는 스트링입니다."};
//    STRING t{"나는 STRING입니다."};
//    t = s;
//    t = t = t = t = t = t = t = t;
//
//    string k{"스트링"};
//    string p = move(k);
//
//    cout << "k - " << k << '\n';
//    cout << "p - " << p << '\n';

//    STRING s{"안녕하세요. 나는 스트링입니다."}; // string 했을때랑 좀 다른데 그이유는..?
//    STRING t = move(s); // 이동생성자를 통해 이동을 시킬라고하는데 없어서 복사생성자를 통해서 실행됨. //move semantics

    STRING s{"스트링"};
    STRING t{"입니다."};
    STRING u = s + t;
    s.show();
    t.show();
}
