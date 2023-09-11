//----------------------------------------------------------------------------
// save.cpp - 한 학기 강의를 저장하는 함수
// 2023.9.7
//----------------------------------------------------------------------------

#include <iostream>
#include <fstream>   // 파일을 읽고 쓰려면 이걸 포함해야함.
#include <chrono>    // 시간을 다루는 라이브러리

using namespace std; // ->>???

void save(const string &fileName) {
    /*
            "소스.cpp"의 내용을 읽어서 하드디스크에 파일로 기록한다.
            1. 소스.cpp를 읽는다.
                - 소스.cpp 파일을 연다.									//(ctrl + o ) 해당 파일에 파일 탐색기 열기
                - 파일에서 한 글자를 읽어서 저장한다.
            2. 읽은 내용을 다른 파일에 쓴다.
                - 저장할 파일을 연다.
                - 읽은 글자를 저장할 파일에 기록한다.
    */

    // :: 범위 지정 연산자.
    std::ifstream in{fileName};                                                // 읽어올 파일
    std::ofstream out{"2023년 2학기 C++ 월56목34 강의 저장.txt", std::ios::app}; // 저장할 파일

    // 저장한 시간을 기록
    auto now = std::chrono::system_clock::now();          // time_point를 얻는다.
    auto utc = std::chrono::system_clock::to_time_t(now); // utc 시간으로 변경
    auto lt = std::localtime(&utc);                       // 주소값을 넘김? //지역시간으로 변경
    auto old = out.imbue(std::locale("ko_KR"));                 //한글로 변경하는 스트림

    out << '\n'
        << '\n';
    out << "==============================" << '\n';
    out << "저장시간 : " << std::put_time(lt, "%x %A %X") << '\n';
    out << "==============================" << '\n';
    out.imbue(old); //다시 되돌림
    cout << '\n\n\n' << "저장 완료 : " << lt << '\n';

    char c;

    in >> std::noskipws; // tap, space 포함

    while (in >> c) { // 실제로 읽는 부분
        out << c;
    }
}