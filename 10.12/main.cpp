//------------------------------------------------------------------------------------------
// 2023. 2학기 C++ 10월 12일 목요일                         월56목34      (6주 2일)
//------------------------------------------------------------------------------------------
// sort - qsort
//------------------------------------------------------------------------------------------
// [과제] 정렬 관련 내용을 구글에서 찾아보기
//------------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <fstream>
#include <cstdlib>

using namespace std;
default_random_engine dre;
uniform_int_distribution uid;

int custom_sort(const void *, const void *);

int main() {

//    ofstream out{"int 만개"};
//    for (int i = 0; i < 1'0000; ++i) {
//        out << uid(dre) << ' ';
//        if (((i + 1) % 10) == 0) {
//            out << '\n';
//        }
//    }

// [문제] 파일 'int 만개'에는 int값 1'0000개가 저장되어 있다.
// 가장 작은 값을 찾아 화면에 출력해라.
// ------------------- 내 코드 --------------------------
//    int array[1'0000];
//    string line;
//    ifstream file("int 만개", ios::in);
//
//    if (file.is_open()) {
//        int i = 0;
//        while (getline(file, line)) {
//            array[i++] = stoi(line);
//        }
//    }
//
//    int min = array[0];
//    for (int i = 0; i < 1'0000; ++i) {
//        if (min < array[i]) {
//            min = array[i];
//        }
//    }
//
//    cout << min << endl;

    // ------------- 교수님 코드 -------------------

//    ifstream in{"int 만개"}; //RAII
//
//    if (not in) { // ! 이거보다 not 이게 더 좋다 그럼
//        cout << "파일을 열 수 없다" << "\n";
//        return 0;
//    }
//
//    int num;
//    int min{numeric_limits<int>::max()}; // 나중에 이게 뭔지 검색해바야할듯?
//    for (int i = 0; i < 1'0000; ++i) {
//        in >> num;
//        if (min > num) {
//            min = num;
//        }
//    }
//
//    cout << "최솟값 - " << min << '\n';

// [문제] 파일 'int 만개'에는 int값 1'0000개가 저장되어 있다.
// 오름 차순으로 정렬해서 결과를 화면에 출력하라.
    // --------------------- 내 코드 -------------------------
//    ifstream in{"int 만개"}; //RAII
//    int num[1'0000];
//
//    for (int i = 0; i < 1'0000; ++i) {
//        in >> num[i];
//    }
//
//    qsort(num, 1'0000, 4, custom_sort);
//
//    for (int i = 0; i < 1'0000; ++i) {
//        cout << num[i] << '\n';
//    }

    // -------------------교수님 코드 --------------------

//    ifstream in{"int 만개"};
//
//    int num[1'0000];
//
//    for (int i = 0; i < 1'0000; ++i) {
//        in >> num[i];
//    }
//
//    qsort(num, 1'0000, 4, [](const void *a, const void *b) {
//        return *(int *) a - *(int *) b;
//    });
//
//    for (int num: num)
//        cout << num << '\n';


// [문제] 어떤 글자를 찾기 원하는지 물어봐라.
// 파일 "소스.cpp"에 그 문자가 몇 개 있는 지 알려주자.
// 이 과정을 영원히 반복하라.

// ---------------------- 내 코드 --------------------
//    ifstream in{"./../main.cpp"};
//
//    if (not in)
//        return 0;
//
//    char result;
//    cout << "찾기 원하는 글자를 입력하세요 : ";
//    cin >> result;
//
//    int num{};
//    char getText;
//    while (in.good()) {
//        in >> getText;
//        if (getText == result) {
//            num++;
//        }
//    }
//
//    cout << result << "의 총 수 : " << num << endl;

    // ----------------------교수님 코드 ---------------
//    while (true) {
//        ifstream in{"./../main.cpp"};
//        cout << "찾을 문자? ";
//        char findChar;
//        cin >> findChar;
//
//        char getChar;
//        int cnt{};
//        while (in >> getChar) {
//            if (getChar == findChar) {
//                cnt++;
//            }
//        }
//        cout << findChar << "의 개수는 - " << cnt << "입니다." << endl;
//    }

    // [문제] 파일 "소스.cpp"에 있는 알파벳 소문자의 개수를 세서 다음과 같이 출력하라.
    // a=1
    // ------------------------ 내코드 ----------------------
//    ifstream in{"./../main.cpp"};
//    char array[]{};
//    char getChar{};
//    while (in.good()) {
//        in >> getChar;
//        array[(int) getChar]++;
//    }
//
//    for (int i = 0; i < sizeof(array) / sizeof(char); ++i) {
//        cout << array[i] << '\n';
//    }
    // ----------------------교수님 코드 ---------------
//    int num[26]{};
//    ifstream in("./../main.cpp");
//    char ch;
//    while (in >> ch) {
//        if (islower(ch)) //'a' <= ch and ch <= 'z' C언어같은경우 이렇게
//            num[ch - 'a']++;
//    }
//
//    for (int i = 0; i < 26; ++i) {
//        cout << static_cast<char>('a' + i) << " - " << num[i] << '\n';
//    }
    // [문제] 파일 "소스.cpp"에 있는 알파벳 소문자를 모두 대문자로 바꿔 "소스대문자.txt"에 기록하시오.
    // ------------------------ 내코드 ----------------------
//    ifstream in("./../main.cpp");
//    ofstream out{"소스대문자.txt"};
//    char ch;
//    while (in >> ch) {
//        char upper1 = toupper(ch);
//        out << upper1;
//    }

    // ----------------------교수님 코드 ---------------
    ifstream in("./../main.cpp");
    ofstream out{"소스대문자.txt"};

    char ch;
    in >> noskipws;
    while (in >> ch) {
        ch = toupper(ch);
        out << ch;
    }

    // 담주꺼

    // POD(Plain Old Data) type - char, int, double
    // User-Defined Type - 사용자 정의 타입
//class or struct    DOG{
//       int 이름;
//        int 나이;
//        int 견종;
//    };
//}
//
//Dog dog;

//내 qsort 함수
    int custom_sort(const void *a, const void *b) { //const -> 이 원소의 값을 수정할 수 없다.
        return *(int *) a - *(int *) b;
    }
