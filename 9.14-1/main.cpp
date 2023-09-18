#include <iostream>
#include <format>
#include <random>
using namespace std;

default_random_engine dre;            // 랜덤 숫자를 생성하는 엔진
uniform_int_distribution uid{1, 999}; // 숫자 1부터 999까지 가공해줘. (확률 분포를 조작하는 객체)

int main()
{
    int numbers[100]{}; // 배열을 초기화함
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
    {
        numbers[i] = uid(dre);
    }
    for (int num : numbers)
    { // 범위 기반 for 문
        cout << format("{:4d}", num) << '\n';
    }
    std::cout << std::format("Hello {}!\n", "world");
}