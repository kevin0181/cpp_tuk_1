#pragma once

class STRING {
    size_t num;
    char* p;
public:
    // 생성 소멸
    STRING(const char* s);
    ~STRING();

    // 복사 복사 할당
    STRING(const STRING& other);
    STRING& operator=(const STRING& other);

    // 2023. 11. 09. 이동과 이동할당
    STRING(STRING&&);

    size_t size() const;

    void show() const;

    // 스페셜 함수를 필요할 때 관찰하도록 사용 코드
    static bool 관찰;
};