#include <iostream>

using namespace std;

//상속(Inheritance)과 다형성(Polymorphism)

class Animal {
    int age;

public:
    Animal() {
        cout << "Animal class 생성자" << endl;
    }

    Animal(int a) : age(a) {}

    ~Animal() {
        cout << "Animal class 소멸자" << endl;
    }

    int getAge() const {
        return age;
    }
};

class Dog : public Animal { // private,protective도 가능한데 public이 기본이다~~
    string name;

public:
    Dog() {
        cout << "Dog class 생성자" << endl;
    }

    Dog(string n) : name(n) {}

    Dog(string s, int a) : name(s), Animal{a} {} // Animal class 에서 받을 수 있는 생성자를 만들어줘야댐

    ~Dog() {
        cout << "Dog class 소멸자" << endl;
    }

    string getDogName() const {
        return name;
    }

    int getDogAge() const {
        return Animal::getAge();
    }

    void show() const {
        cout << "이름 : " << name << ", 나이 : " << Animal::getAge() << endl;
    }

};

class Bird : public Animal {
    bool fly{true};

    Bird() {
        cout << "Bird class 생성자" << endl;
    }

    ~Bird() {
        cout << "Bird class 소멸자" << endl;
    }

};

int main() {
//    Dog dog;        // 메모리 크기, 생성자와 소멸자 호출 순서는? (부모와 자식 전부 관찰 메시지 출력)
    Dog dog{"댕댕", 3};
    cout << "Dog class 메모리 크기 : " << sizeof(dog) << endl;
    cout << "Dog class name : " << dog.getDogName() << ", Dog class age : " << dog.getDogAge() << endl;

}
