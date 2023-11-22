#include <iostream>
#include <random>
#include <fstream>

using namespace std;

class Dog {
    int age{};
    string name{};
public:

    Dog() = default; // 컴파일러가 default 생성자를 만들도록 함

    void show() const {
        cout << "나이 : " << age << ", 이름 : " << name << endl;
    }

    friend istream &operator>>(istream &is, Dog &dog) {
        return is >> dog.age >> dog.name;
    }

    int getAge() const {
        return age;
    }

};

int main() {
    //[문제] 개10마리.txt 파일에는 Dog 10마리 정보가 기록되어있다.
    // 나이 오름차순으로 정렬한 후 화면에 출력하라.
    // class Dog의 멤버는 다음과 같으며
    //    class Dog {
    //        int age{};
    //        string name{};
    //    }
    //    파일에는 이 정보를 다음과 같은 방법으로 기록하였다.
    //    friend ostream &operator<<(ostream &os, const Dog &dog) {
    //        os << dog.age << " " << dog.name << " ";
    //        return os;
    //    }

    Dog dog;

    ifstream in{"개10마리.txt"};
//    if (not in) {
//        cout << "파일 열기 실패" << '\n';
//        return 0;
//    }
//
//    while (in >> dog) {
//        dog.show();
//    }

    Dog dogs[10];

    for (int i = 0; i < 10; ++i) {
        in >> dogs[i];
    }

    qsort(dogs, 10, sizeof(dog), [](const void *a, const void *b) { //포인터일때는 화살표로 접근!
        return ((Dog *) a)->getAge() - ((Dog *) b)->getAge();
    });

    cout << " - 나이 오름차순 정렬 결과 - " << '\n';
    for (const Dog &dog: dogs)
        dog.show();


}
