//------------------------------------------------------------------------------------------
// 2023. 2학기 C++ 9월 18일 월요일                         월56목34      (3주 1일)
//------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------
// [과제] int가 여러개 있을때 어떤 동작을 하고 싶은가?
//------------------------------------------------------------------------------------------

#include <format>
#include <iostream>
#include <random>  // 랜덤엔진과 분포를 사용한다.

using namespace std;

default_random_engine dre; //랜덤 숫자를 생성하는 엔진
uniform_int_distribution uid{1, 6}; // 숫자 1부터 999까지 가공해줘. (확률 분포를 조작하는 객체)

// [문제] 주사위를 1'0000던졌다. 각 숫자가 나온 횟수와 확률을 출력하시오.
// 1 - 1650번 확률 : 16.5%
// 2 -
// 3 -

int main() {
    //내가 짠 코드 -------------------------------------------------------------------------------------
    int numbers[1'0000]{}; //주사위 던진 횟수

    for (int i = 0; i < size(numbers); i++) { // 랜덤으로 돌린 주사위 던진 수
        numbers[i] = uid(dre);
    }

    int dice_1{0}, dice_2{0}, dice_3{0}, dice_4{0}, dice_5{0}, dice_6{0}; //주사위 1번 ~ 6번

    for (int n: numbers) {
        switch (n) {
            case 1:
                dice_1++;
                break;
            case 2:
                dice_2++;
                break;
            case 3:
                dice_3++;
                break;
            case 4:
                dice_4++;
                break;
            case 5:
                dice_5++;
                break;
            case 6:
                dice_6++;
                break;
            default:
                break;
        }
    }

    cout.precision(4);
    cout << "1번 - 횟수 : " << dice_1 << "번" << '\t' << "| 확률 : " << dice_1 / (double) 100 << "%" << '\n';
    cout << "2번 - 횟수 : " << dice_2 << "번" << '\t' << "| 확률 : " << dice_2 / (double) 100 << "%" << '\n';
    cout << "3번 - 횟수 : " << dice_3 << "번" << '\t' << "| 확률 : " << dice_3 / (double) 100 << "%" << '\n';
    cout << "4번 - 횟수 : " << dice_4 << "번" << '\t' << "| 확률 : " << dice_4 / (double) 100 << "%" << '\n';
    cout << "5번 - 횟수 : " << dice_5 << "번" << '\t' << "| 확률 : " << dice_5 / (double) 100 << "%" << '\n';
    cout << "6번 - 횟수 : " << dice_6 << "번" << '\t' << "| 확률 : " << dice_6 / (double) 100 << "%" << '\n';

    // 교수님 코드 -------------------------------------------------------------------------------------

    int num1{}, num2{}, num3{}, num4{}, num5{}, num6{};

    for (int i = 0; i < 1'0000; i++) {
        int number = uid(dre);

        if (number == 1)
            num1++;
        else if (number == 2)
            num2++;
        else if (number == 3)
            num3++;
        else if (number == 4)
            num4++;
        else if (number == 5)
            num5++;
        else
            num6++;
    }

    cout << 1 << " - " << num1 << "번, 확률:" << format("{:2.1f}", num1 / 100.) << "%" << '\n';
    cout << 2 << " - " << num2 << "번, 확률:" << format("{:2.1f}", num2 / 100.) << "%" << '\n';
    cout << 3 << " - " << num3 << "번, 확률:" << format("{:2.1f}", num3 / 100.) << "%" << '\n';
    cout << 4 << " - " << num4 << "번, 확률:" << format("{:2.1f}", num4 / 100.) << "%" << '\n';
    cout << 5 << " - " << num5 << "번, 확률:" << format("{:2.1f}", num5 / 100.) << "%" << '\n';
    cout << 6 << " - " << num6 << "번, 확률:" << format("{:2.1f}", num6 / 100.) << "%" << '\n';


    // 교수님 개선 코드 -------------------------------------------------------------------------------------
    int num[6]{};

    for (int i = 0; i < 1'0000; i++) {
        num[uid(dre) - 1]++;
    }

    for (int i = 0; i < 6; i++) {
        cout << i + 1 << " - " << num[i] << "번, 확률:" << format("{:2.1f}", num[i] / 100.) << "%" << '\n';
    }

}
