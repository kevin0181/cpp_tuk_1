#include <iostream>
#include <string>
#include <random>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid{-100, 100};

class Dog {
//private :  // access modifier - class에서는 private이 default임
    string name;
    int age;

public : // 멤버 함수는 public 으로 선언하여, 클래스 바깥에서 함수에 접근할 수 있게한다.

    // 내 name 을 전달해준 name으로 초기화.
    Dog(string name, int age) : name{name}, age{age} { // 생성자 (여기에도 생성자가 있네 ㅋㅋ
    }

    void show() {
        cout << name << " - " << age << endl;
    }

};


int main() {

    Dog dog{"댕댕", 3}; // 디폴트 초기화는 가능함.
    dog.show(); // {}으로 초기화를 하지 않으면 알수 없는 숫자가 찍힘, 만약 25번째 줄이 전역변수라면? 초기화된게 찍힘

}
