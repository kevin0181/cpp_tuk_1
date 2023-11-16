//#pragma once
//
//class STRING {
//    size_t num{0};
//    char *p{nullptr};
//public:
//    // 생성 소멸
//    STRING(const char *s);
//
//    ~STRING();
//
//    // 복사 복사 할당
//    STRING(const STRING &other);
//
//    STRING &operator=(const STRING &other);
//
//    // 2023. 11. 09. 이동과 이동할당
//    STRING(STRING &&);
//
//    size_t size() const;
//
//    void show() const;
//
//    //2023.11.13
//    size_t length() const;
//
//    //입출력함수는 frien가되어야한다.
//    friend std::ostream &operator<<(std::ostream &, const STRING &);
//
//    // 스페셜 함수를 필요할 때 관찰하도록 사용 코드
//    static bool 관찰;
//
//
//};
//
//// 2023.11.13
////전역함수 operator+
//STRING &operator+(const char *, const STRING &); // (pointer보다 크면 레퍼런스로 처리하는게 이득) (변경될 이유가 없기때문에 const 사용(읽기전용))



// 헤더파일에는 using namespace std; 사용 X

// -----------------------------------------------------------------------
// STRING.h
//
// 2023.11.09 파일 분리함.
//
// 2023.11.13 필요할 때만 관찰하도록 변경
// -----------------------------------------------------------------------

#pragma once

class STRING {
    char *p{nullptr};
    size_t size{};
public:
    //2023.11.09
    STRING();

    STRING(const char *str);

    ~STRING();

    STRING(const STRING &other);

    //복사생성자와 짝이 되는 복사할당연산자를 반드시 코딩해야 한다.
    STRING &operator=(const STRING &other);

    //C++11 이동생성자와 이동할당연산자를 코딩한다.
    //&& - r - value reference, 이동(move)과 완벽전달(perfect forwarding)에 사용한다.
    STRING(STRING &&other);

    // 2023 11. 09 연산자 오버로딩 시작
    STRING operator+(const STRING &other);

    // 2023.11.13 [] 연산자
    // &를 붙이지 않으면 임시이고 &가 붙으면 원본을 보냄.
    char operator[](int idx) const;
    char& operator[](int idx); // -> 진짜이기 때문에 const를 붙일 수가 없음.

    void show() const;

    //2023.11.13
    size_t length() const;

    //2023.11.09 입출력 함수는 friend가 되어야 한다.
    friend std::ostream &operator<<(std::ostream &, const STRING &);

    static bool 관찰;  // static bool = class local이면서 전역변수
};

//전역함수 operator+      - 2023 11. 13
STRING operator+(const char *, const STRING &); // 포인터보다 크면 &를 붙이는게 좋음
