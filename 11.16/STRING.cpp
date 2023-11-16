//#include <iostream>
//#include "STRING.h"
//
//bool STRING::관찰{false};
//
//STRING::STRING(const char *s) : size{strlen(s)} {
//    p = new char[size];
//    memcpy(p, s, size);
//
//    if (관찰)
//        std::cout << "생성자(const char*) -" << size << ", 메모리:" << (void *) p << '\n';
//}
//
//STRING::~STRING() {
//    if (관찰)
//        std::cout << "소멸자 -" << size << ", 메모리:" << (void *) p << '\n';
//    delete[] p;
//}
//
//// 2023. 11. 9 복사생성자(스페셜 함수)
//STRING::STRING(const STRING &other)
//        : num{other.size} {
//    p = new char[size];
//    // deep-copy
//    memcpy(p, other.p, size);      // DMA
//
//    if (관찰)
//        std::cout << "복사 생성자 -" << size << ", 메모리:" << (void *) p << '\n';
//
//}
//
//// 2023. 11. 9 복사생성자를 만들었다면 이와 짝이되는 copy assignment operator를
//// 반드시 코딩해야한다
//STRING &STRING::operator=(const STRING &other) {
//    // 가장 먼저 해야 할 일은 자기 자신을 할당하지않도록 해야한다.
//    if (this == &other)
//        return *this;
//
//    delete[] p;
//
//    size = other.size;
//    p = new char[size];
//    memcpy(p, other.p, size);
//    if (관찰)
//        std::cout << "copy assignment 연산자 -" << size << ", 메모리:" << (void *) p << '\n';
//
//    return *this;
//}
//
////STRING STRING::operator+(const STRING &other) {
////    STRING temp;
////    temp.num = num + other.num;
////    temp.p = new char[temp.num];
////    memcpy(temp.p, p, num);
////    memcpy(temp.p + num, other.p, other.num);
////
////    return temp;
////}
//
//// 2023. 11. 09. 이동과 이동할당
//STRING::STRING(STRING &&other)
//        : size{other.size}, p{other.p} {
//    // other를 초기화한다.
//    other.size = 0;
//    other.p = nullptr;
//}
//
//
//void STRING::show() const {
//    for (int i = 0; i < size; ++i)
//        std::cout << p[i];
//    std::cout << '\n';
//}
//
//size_t STRING::length() const {
//    return size;
//}
//
////2023.11.09 입출력 함수는 friend가 되어야 한다.
//std::ostream &operator<<(std::ostream &os, const STRING &s) {
//    for (int i = 0; i < s.size; ++i)
//        os << s.p[i];
//    return os;
//}
//
//// 2023.11.13
////전역함수 operator+
//STRING &operator+(const char *p, const STRING &s) {
//    STRING temp{p};
//    temp = temp + s;
//    return temp; //RVO
//}




// -----------------------------------------------------------------------
// STRING.cpp
//
// 2023.11.09 파일 분리함.
//
// // 2023.11.13 필요할 때만 관찰하도록 변경
// -----------------------------------------------------------------------
// 2023.11.13 필요할 때만 관찰하도록 변경
#include <iostream>
#include "STRING.h"

bool STRING::관찰{false};

//2023.11.09
STRING::STRING() {
    if (관찰)
        std::cout << "디폴트 생성자 - " << size << ". 번지 : " << (void *) p << std::endl;
}

STRING::STRING(const char *str) {
    size = strlen(str);
    p = new char[size];
    memcpy(p, str, size);
    if (관찰)
        std::cout << "STRING(char*) - " << size << " , 번지:" << (void *) p << '\n';
}

STRING::~STRING() {
    if (관찰)
        std::cout << "~STRING() - " << size << " , 번지:" << (void *) p << '\n';
    delete[] p;
}

STRING::STRING(const STRING &other) {
    size = other.size;
    p = new char[size];
    memcpy(p, other.p, size);
    if (관찰)
        std::cout << "STRING(const STRING& other) - " << size << " , 번지:" << (void *) p << '\n';
}

//복사생성자와 짝이 되는 복사할당연산자를 반드시 코딩해야 한다.
STRING &STRING::operator=(const STRING &other) {
    // 가장 먼저 해야 할 일은 자기 자신을 할당하지않도록 해야한다.
    if (this == &other)
        return *this;

    delete[] p;

    size = other.size;
    p = new char[size];
    memcpy(p, other.p, size);
    if (관찰)
        std::cout << "copy assignment 연산자 -" << size << ", 메모리:" << (void *) p << '\n';

    return *this;
}

//C++11 이동생성자와 이동할당연산자를 코딩한다.
//&& - r - value reference, 이동(move)과 완벽전달(perfect forwarding)에 사용한다.
STRING::STRING(STRING &&other) {
    size = other.size;
    p = other.p;
    other.p = nullptr;
    if (관찰)
        std::cout << "STRING(STRING&& other) - " << size << " , 번지:" << (void *) p << '\n';
}

void STRING::show() const {
    for (int i = 0; i < size; ++i) {
        std::cout << p[i];
    }
    std::cout << '\n';
}

size_t STRING::length() const {
    return size;
}

STRING STRING::operator+(const STRING &other) {
    STRING temp;
    temp.size = size + other.size;
    temp.p = new char[temp.size];
    memcpy(temp.p, p, size);
    memcpy(temp.p + size, other.p, other.size);

    return temp;
}

char STRING::operator[](int idx) const {
    return p[idx];
}

char &STRING::operator[](int idx) {
    return p[idx];
}

//2023.11.09 입출력 함수는 friend가 되어야 한다.
std::ostream &operator<<(std::ostream &os, const STRING &s) {
    for (int i = 0; i < s.size; ++i)
        os << s.p[i];
    return os;
}

STRING operator+(const char *p, const STRING &s) {
    STRING temp{p};
    temp = temp + s;
    return temp;      // RVO가 됨.
}

