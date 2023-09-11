#include <iostream>
#include <fstream>   // 파일을 읽고 쓰려면 이걸 포함해야함.
#include <chrono>    // 시간을 다루는 라이브러리
using namespace std; // ->>???

int main()
{
    void save(const std::string&);

    save("소스.cpp");
}
