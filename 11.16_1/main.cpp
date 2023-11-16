#include <iostream>
#include "STRING.h"
#include <random>
//#include <string>
#include <fstream>

using namespace std;
default_random_engine dre;
uniform_int_distribution uidAge{0, 99};

int id{0};

class Dog {
    int age{};
//    STRING name{};
    string name{};
public:
    Dog() {
        age = uidAge(dre);
        name = "댕댕이-" + to_string(++id) + "호";
    }

    friend ostream &operator<<(ostream &os, const Dog &dog) {
//        os << "나이 : " << dog.age << ", 이름 : " << dog.name;
        os << dog.age << " " << dog.name << " ";
        return os;
    }

    friend istream &operator>>(istream &is, Dog &dog) {
        is >> dog.age >> dog.name;
        return is;
    }
};

int main() {
//    Dog dog;
//    operator<<(cout, dog) << '\n';

//    Dog dogs[10];
//    ofstream out{"개10마리.txt"};
//
//    for (const Dog &dog: dogs)
//        out << dog << '\n';

    //[문제] 개10마리.txt 파일에는 Dog 10마리 정보가 기록되어있다.
    // 읽어서 화면에 출력하라.
//    Dog dog;
//    ifstream in{"개10마리.txt"};
//    Dog dog2[10];
//
//    if (not in)
//        return 0;
//
//    for (int i = 0; i < 10; ++i) {
//        in >> dog;      // operator >> (in,dog)
//        in >> dog2[i];
//        cout << dog << '\n';
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        cout << dog2[i] << endl;
//    }

    //[문제] 개10마리.txt 파일에는 Dog 10마리 정보가 기록되어있다.
    // 나이 오름차순으로 정렬한 후 화면에 출력하라.

}
