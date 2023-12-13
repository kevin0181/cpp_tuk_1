#include <iostream>
#include <random>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"

using namespace std;

uniform_int_distribution<> uid;
default_random_engine dre;

int main()
{
	// Q1. Triangle 객체의 크기 출력.

	// 아래에 코딩
	cout <<"Triangle 객체의 크기 : " << sizeof new Triangle() << endl;


	// Loop On
	while (1) {
		cout << "엽력할 도형의 갯수: ";
		int num;
		cin >> num;

		if (num == 0)
			break;
		

		// Q2. 사용자가 입력한 숫자남큼 도형을 관리할 수 있는 메모리 확보

		// 아래에 코딩
		Shape** shapes = new Shape * [num];


		// Q3. 랜덤 엔진과 분포를 사용하여 값이 홀수이면 Triangle,
		// 짝수이면 Circle을 i번째 도형으로 생성하여 [Q2]에서 확보한 메모리에 저장하라

		for (int i{}; i < num; ++i) {
			// 아래에 코딩
			switch (uid(dre) % 2)
			{
			case 0:
				shapes[i] = new Circle();
				break;
			case 1:
				shapes[i] = new Triangle();
				break;
			default:
				break;
			}
		}

		// Q4. 도형의 draw 멤버를 호출하여 다형성이 구현됨을 보여라
		cout << endl << "Q4 출력 결과" << endl;

		// 아래에 코딩
		
		for (int i = 0; i < num; ++i) {
			shapes[i]->draw();
		}


		// Loop End

		// Q5. 다형성을 보이는 이 과정이 무한히 반복 실행 되도록
		// Loop On - Loop End 부분에 while문으로 감쌌다고 가정
		// while문으로 감싼 부분의 문제점을 지적하고 해결
		// 어느 부분에 어떤 코드가 들어가야 하는 지 정확하게 적을 것

		// 메모리 해제
		for (int i = 0; i < num; ++i) {
			delete shapes[i];
		}
		delete[] shapes;


	}

	// Q6. num만큼 도형을 생성한 상태에서 도형 한 개를 추가하려 한다.
	// num보다 50% 더 많은 갯수의 도형을 담을 수 있는 코드를 작성하고 Circle을 한개 추가하라.
	// Q5의 while loop와는 관계가 없다.
	// num이 10라면 15개를 담을 수 있는 코드를 작성하고,
	// 기존 10개 도형의 정보는 유지되어야 한다.
	// Q2에서 정한 원래의 메모리 이름으로 도형의 정보에 access 할 수 있어야한다.

	cout << endl << "Q6 출력결과 - (num + 1)개만 출력하면 됨" << endl;

	//// 아래에 코딩


	
}