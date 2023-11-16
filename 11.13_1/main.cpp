#include <iostream>

using namespace std;

//class INT {
//private:
//    int n;
//public:
//    INT(int num) {
//        n = num;
//    }
//
//    int operator++(int num) {
//        return n++;
//    }
//
//    int show() {
//        return n;
//    }
//};


class INT {
    int num;
public:
    INT() {}

    INT(int val) : num{val} {}

    //pre-increment
    INT &operator++() { //올리고 자기 자신을 리턴?
        ++num;
        return *this;
    }

    //post-increment
    INT operator++(int) { //올리고 자기 자신을 리턴? // 레퍼런스가 아니고 임시변수!! temp를 넘기는거임
        INT temp = *this; // 나 자신을 세이브.
        ++num;
        return temp;
    }

    //int처럼 더하기가 계속안붙게하는방법은 뭐지??

    friend ostream &operator<<(ostream &os, const INT &i) {
        os << i.num;
        return os;
    }

};

int main() {
    INT n{100};
//    n++;
//    cout << n << endl;
//    INT X = ++ ++ ++ ++n; //=> n.operator++(); // pre-increment, ++ -> unary-operator
//    int x = n++ ++ ++; // -> 안됨 (이유 : x에들어가는값은 100인데 n은 101임.
    INT x = n++ ++; // operator++ (int) int인자를 받아야하는 꼼수를 부려야댐. (약속임)
    cout << x << endl;
    cout << n << endl;
}
