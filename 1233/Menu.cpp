#include<iostream>
#include<random>
#include "Menu.h"
#include "Triangle.h"
#include "Circle.h"
#include "Point.h"
#include "Rectangle.h"
#include "Pentagon.h"
#include "FileManager.h"
#include "Line.h"


using namespace std;
default_random_engine dre;
uniform_int_distribution uid{1, 100};

Menu::Menu(ShapeManager &sma) {
    sm = sma;
}

void Menu::qChoice() {
    cout << "---------------Menu---------------" << endl;
    cout << " -  원하는 도형을 추가하세요." << endl;
    cout << "1.  - 삼각형" << endl;
    cout << "2.  - 사각형" << endl;
    cout << "3.  - 오각형" << endl;
    cout << "4.  - 원" << endl;
    cout << "5.  - 선" << endl;
    cout << "---------------------------------" << endl;
    cout << "6.  -  전체 도형을 그리기" << endl;
    cout << "7.  -  원하는 번호 도형 삭제하기" << endl;
    cout << "8.  -  특정 도형 삭제하기" << endl;
    cout << "9.  -  파일에 저장하기" << endl;
    cout << "10. -  파일에서 읽어오기" << endl;
    cout << "11. -  프로그램 끝내기" << endl;
    cout << "----------------입력---------------" << endl;
    cout << "입력 : ";
}

void Menu::qDeleteShape() {
    int num{};
    cout << "삭제를 원하는 도형의 번호를 입력하세요." << endl;
    cout << "---------------------------------" << endl;
    cout << "1. - 삼각형" << endl;
    cout << "2. - 사각형" << endl;
    cout << "3. - 오각형" << endl;
    cout << "4. - 원" << endl;
    cout << "5. - 선" << endl;
    cout << "입력 : " << endl;
    cin >> num;
    deleteShapeChoice(num);
}

void Menu::deleteNumber() {
    int num{};
    cout << "삭제를 원하는 번호를 입력하세요." << endl;
    cout << "입력 : ";
    cin >> num;
    sm.deleteNumber(num);
}

void Menu::deleteShapeChoice(int num) {
    switch (num) {
        case 1:
            sm.deleteShape(new Triangle());
            break;
        case 2:
            sm.deleteShape(new Rectangle());
            break;
        case 3:
            sm.deleteShape(new Pentagon());
            break;
        case 4:
            sm.deleteShape(new Circle());
            break;
        case 5:
            sm.deleteShape(new Line());
            break;
        default:
            std::cout << "잘못된 입력값 입니다." << std::endl;
            break;
    }
}

void Menu::choice(int num) {

    switch (num) {
        case 1:
            sm.insert(new Triangle(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
            break;
        case 2:
            sm.insert(new Rectangle(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
            break;
        case 3:
            sm.insert(new Pentagon(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre)),
                                   Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
            break;
        case 4:
            sm.insert(new Circle(Point(uid(dre), uid(dre)), uid(dre)));
            break;
        case 5:
            sm.insert(new Line(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
            break;
        case 6:
            sm.draw();
            break;
        case 7:
            deleteNumber();
            break;
        case 8:
            qDeleteShape();
            break;
        case 9:
            saveFile();
            break;
        case 10:
            readFile();
            break;
        case 11:
            exit(0);
            break;
        default:
            break;
    }

}

int Menu::addCapacitySize() {
    int result{};
    int num{};
    cout << "최댓값에 도달했습니다." << endl;
    cout << "도형 추가의 최댓값을 변경하고 싶으면 1번 아니면 2번을 입력하세요." << endl;
    cout << "입력 : ";
    cin >> result;
    if (result == 1) {
        cout << "몇개의 공간을 추가할까요?" << endl;
        cout << "입력 : ";
        cin >> num;
        return num;
    } else {
        return 0;
    }
}

void Menu::saveFile() {
    string fileName{};
    cout << "저장할 파일의 이름을 입력하세요." << endl;
    cout << "입력 : ";
    cin >> fileName;
    FileManager *fm = new FileManager(sm);
    fm->saveFile(fileName);
    delete fm;
}

void Menu::readFile() {
    string fileName{};
    cout << "읽어올 파일의 이름을 입력하세요." << endl;
    cout << "입력 : ";
    cin >> fileName;
    FileManager *fm = new FileManager(sm);
    fm->readFile(fileName);
    delete fm;
}

