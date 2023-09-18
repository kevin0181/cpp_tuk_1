//
// Created by 유영빈 on 2023/09/18.
//

#include "find_number.h"

#include "format"
#include <iostream>
#include <random>  // 랜덤엔진과 분포를 사용한다.

using namespace std;

default_random_engine dre; //랜덤 숫자를 생성하는 엔진
uniform_int_distribution uid{1, 999}; // 숫자 1부터 999까지 가공해줘. (확률 분포를 조작하는 객체)


void find_number() {
    int numbers[1'000]{}; // 배열을 초기화함

    // 랜덤 값으로 채울거임
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        numbers[i] = uid(dre);
    }

    // [문제] 사용자가 입력한 숫자가 있는지 있다면 몇 번째 원소인지 출력하자.
    // 없으면 못 찾았다고 출력하라.
    // 내코드 -------------------------------------------------------------
    int putNum;
    bool check;
    cout << "숫자 하나를 입력하세요 : ";
    cin >> putNum;

    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        if (putNum == numbers[i]) {
            check = true;
            cout << "해당 숫자는 " << i + 1 << "번째에 있습니다." << '\n';
        }
    }

    if (!check) {
        cout << "해당 숫자는 존재하지 않습니다." << '\n';
    }

    //교수님 코드 -------------------------------------------------------------
    // 모든 값을 한 번에 하나씩 가져와서 찾는 값과 비교한다.
    // 시험 문제로 string 입력했을때 왜 무한루프를 도는지 -> 같은거 낼수도??
    // 무한루프 이유 : 잘못된 값을 입력했을 경우 cin이 내부적으로 fail 상태로 설정되기 때문에 fail 상태를 무한적으로 호출하기 때문임.
    // 무한루프 해결 : cin.clear() 함수를 사용하여 cin의 내부 상태를 초기화함.
    // 하지만 잘못입력했던 입력 버퍼가 그대로 남아있기 때문에 cin.ignore(100,'\n') 함수를 사용해서 입력 스트림 버퍼 지워준다.
    while (true) {
        cout << "찾을 숫자를 입력 : ";
        int number{0};
        cin >> number;
        int cnt{};
        for (int num: numbers) {
            cnt++;
            if (number == num) {
                cout << cnt << " 위치에서 " << number << "를 찾았습니다." << '\n';
                break;
            }
        }
        if (cnt == 1'000)
            cout << number << "는 없습니다." << '\n';
    }
}
