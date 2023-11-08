#include <iostream>
//#include <windows.h>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")
#include <cstdlib>

using namespace std;

class Dog {
private: //access modifier
    string name;
    int age;

public:

    Dog(string name, int age) : name{name}, age{age} {
        cout << name << "이 생성되었습니다." << endl;
//        PlaySound(L"dogsound.mp3", NULL, SND_SYNC);
        system("open ./../dogsound.mp3");
    }

    Dog() : name{}, age{} { // ->기본생성자
        cout << "디폴트 생성자 : " << name << " " << age << endl;
    }

    //객체가 소멸되기 직전에 이 함수를 호출한다 - destructor(dtor)
    //틸다?
    //객체를 정리할 필요가 있다면 이 함수를 코딩한다.
    ~Dog() {
        cout << name << "소멸 되기 직전" << endl;
    }

    //복사 생성사(copy constructor) //const and 레퍼런스를 사용하여 원본 객체를 손상시키지 않고 가져옴
    Dog(const Dog &other) : name{other.name}, age{other.age} {
        cout << "복사생성자 호출" << name << " " << age << endl;
    }

    //복사 할당 연산자 (copy assignment opeator)
    Dog &operator=(const Dog &other) {
        name = other.name;
        age = other.age;
        cout << "객체가 복사할당되었음" << endl;
        return *this;
    }


    void show() {
        cout << name << " - " << age << endl;
    }

};


int main() {
//------------------------------------------------------------------------------------------------
    //여기서 중요햔 포인트는 생성자를 통해서 객체 내부에서 생성 후, 지워지는 부분이 중요함 틸트함수를 통해 객체가 지워지는걸 알 수 있음.ㄴ
//    Dog dog[3]{{"댕댕", 3},
//               {"코코", 2},
//               {"나비", 10}};
//    dog.show();
//------------------------------------------------------------------------------------------------

// 여기서 중요한 포인트는 지역객체는 지역에서만 life time이 돌아간다는것 순서를 변경하기 위해서는 중괄호를 없애면 됨.
// 출력되는 순서가 다름
//    {
//        Dog d{"x", 0};
//    }

//    cout << "저장하기 전" << endl;
//------------------------------------------------------------------------------------------------

//    new Dog{"댕", 10};

//    Dog *p = new Dog{"댕", 10};
//    delete p;

//    Dog *p2 = new Dog[2]{{"댕",  10},
//                         {"댕2", 1}};
//    delete[] p2;
//------------------------------------------------------------------------------------------------
    //smart pointer
    // 이유 : 지역객체인 p가 사라질때 물고있는 자원을 알아서 소멸시켜줌
//    {
//        unique_ptr<Dog> p{new Dog{"댕", 10}}; // 자원관리를 -> RALL 이렇게한다.
//    }
//    cout << "지역 끝 " << endl;
//------------------------------------------------------------------------------------------------

//    Dog d{}; // ->이때 이게 왜 안돌아가는지 설명하기? -> 생성자에서 받는 매개변수가 두개이기때문에 그래서 빈생성자를 또 만들어줘야함.
//    Dog dog{"댕", 1};

//    d.show();
//------------------------------------------------------------------------------------------------

//    Dog dog{"댕댕이", 3};
//    Dog d = dog; // 객체 d가 dog를 복사해서 생성되는 순간...
    // Dog d (dog); => 복사

//    Dog dog{"댕댕이", 3};
//    Dog d;
//    d = dog; //이미 만들어진 d를 dog와 똑같은 값이 되도록 해달라는 요청 //copy assignment operator //생성자가 아니고 연산자임

//    Dog dog{"댕댕이", 3};
//    Dog d(dog);

}
