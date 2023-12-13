//-----------------------------------------------------------------------------
// 시험3.cpp 
//
// 2020. 12. 16 수요일
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <random>
#include "shape.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;

default_random_engine dre;

//--------
int main()
//--------
{
	// 프로젝트가 제대로 실행되는 지 확인한다.
	Triangle t;
	Circle c;

	t.draw();
	c.draw();



	//--------------------------------------------------------
	// 지금부터 문제를 순서대로 해결하고 답을 답안지에 적는다.
	//--------------------------------------------------------

	// [문제 1] Triangel 객체 한 개의 크기가 몇 byte인지 화면에 출력하고 답지에도 적어라. 
	// 객체의 크기가 왜 그렇게 되는지 이유를 설명하라.									(20) (코드 5, 이유 15)

		// 여기에 들어갈 코드를 답지에 적고 출력결과도 적는다. ~5
		// 출력된 이유를 답지에 적는다. ~15




	int num{ };			// 저장된 정수의 갯수


	// [문제 2] 파일 "시험3.txt"에는 몇 개인지 모르는 int 값이 저장되어 있다.
	// 파일을 읽어 모두 몇 개의 int가 기록되어 있는 지 화면에 출력하고 답지에도 써라.	(20) (코드 15, 갯수 5)

		// 여기에 들어갈 코드를 답지에 적는다. ~15
		// 출력결과도 답지에 적는다. ~5


	//--------------------------------------------------------------------------------------------
	// 다형성이 구현됨을 확인해 보는 문제이다.
	//--------------------------------------------------------------------------------------------
	// [문제 2]에서 확인한 int의 숫자만큼 도형을 관리할 수 있는 메모리를 생성하여 도형을 관리한다.
	//
	// 도형은 Circle과 Triangle 2가지 종류만 있다.
	// [문제 2]에서 읽은 정수의 숫자를 num 이라 하자.
	//--------------------------------------------------------------------------------------------

	cout << "관리해야 할 도형의 수 - " << num << endl;



	// [문제 3] num개의 도형을 관리할 수 있는 메모리를 확보하라. 						(10)
	// 확보한 메모리로 Circle 또는 Triangle을 관리할 수 있어야 한다.

		// 여기에 들어갈 코드를 답지에 적는다. ~10




		
	// [문제 4] 전역변수 dre와 다음 랜덤분포 uid를 사용하여 값이 홀수이면 Triangle을, 
	// 짝수라면 Circle을 i번째 도형으로 생성하여 [문제 3]에서 확보한 메모리에 저장하라.	(10)

	uniform_int_distribution<> uid{ 0, 1 };


	for (int i = 0; i < num; ++i) {
		int sel = uid( dre );

		// 랜덤 값 sel 에 따라 i번째 도형을 생성한다.
		// 여기에 들어갈 코드를 [문제 4]의 답으로 적으면 된다. ~10


	}




	// [문제 5] 관리하는 모든 도형의 draw() 멤버를 호출하여 다형성이 구현됨을 보여라.	(10)

	cout << endl << "[문제 5] 출력결과" << endl;

		// 여기에 들어갈 코드를 답지에 적는다. ~10




	// [문제 6] num 만큼 도형을 생성한 상태에서 도형 한 개를 추가하려고 한다.
	// num 보다 50% 더 많은 갯수의 도형을 관리할 수 있는 코드를 작성하고 
	// Circle을 한 개 추가하라.															(40)
	//	- num이 10이었다면 15개를 담을 수 있는 코드를 작성한다. 
	//	  기존 10개 도형의 정보는 유지되어야 한다.
	//  - [문제 3]에서 정한 메모리 이름으로 도형을 관리할 수 있어야 한다.

	cout << endl << "[문제 6] 출력결과 - (num+1 개의 도형만 출력한 것임)" << endl;


		// 여기에 들어갈 코드를 답지에 적는다. ~40




	// [문제 7] 프로그램을 끝내기 전에 돌려주지 않은 메모리가 있다면 반환하자.			(10)
	// (반환할 것이 없다면 없다고 적어라)

		// 여기에 들어갈 코드를 답지에 적는다. ~10
}