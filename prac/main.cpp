#include <iostream>

using namespace std;

class STRING {
    int size;
    string s;
public:

    STRING(const char *a) : s(a), size(strlen(
            a)) { // string = char*을 인자로 받는 생성자 // 인자로 받은 a를 string type의 s와 길이를 구하기 위한 size에 넣음(1)

    }

    //복사 생성자
    STRING(const STRING &other) : s(other.s),
                                  size(other.size) { //STRING class가 복사되면 other이라는 변수의 멤버 변수 s와 size를 다시 할당시켜줌 (3)

    }

    int getSize() { // (2), (4)
        return size;
    }

    string show() { // (5)
        return s;
    }

    ~STRING() { //(6)
        cout << "소멸" << endl;
    }
};

int main() {

    STRING s1{"안녕하세요"}; // string을 인자로 받는 생성자 (1)
    cout << "s1 문자 길이 : " << s1.getSize() << endl; // (2)
    STRING s2 = s1; // (3)
    cout << "s2 문자 길이 : " << s2.getSize() << endl; // (4)
    cout << s2.show() << endl; // (5)

}
