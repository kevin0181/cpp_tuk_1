//-------------
// 기말시험.cpp 
//-------------
#include <iostream>
#include <random>
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;


// 시험에 사용한 랜덤 엔진과 분포
default_random_engine dre{ 202312 };
uniform_int_distribution<> uid{ 0, 1 };					// 홀수와 짝수
uniform_int_distribution<> uidRad{ 1, 100 };			// 원의 반지름		

int findMaxRad(Shape** shapes, int nShape) {
	int maxRadIndex = -1;
	int maxRadius = numeric_limits<int>::min();

	for (int i = 0; i < nShape; ++i) {
		if (Circle* circle = dynamic_cast<Circle*>(shapes[i])) {
			if (circle->getRad() > maxRadius) {
				maxRadius = circle->getRad();
				maxRadIndex = i;
			}
		}
	}

	return maxRadIndex;
}

//--------
int main()
//--------
{
	//---------------------------------------------------
	// 시험준비가 제대로 되었는지 프로그램을 실행해 보자.
	//---------------------------------------------------
	Triangle aTriangle;
	Circle aCircle{ Point{}, uidRad( dre )};	// 중심점은 그대로 두고 반지름은 랜덤으로 초기화
			
	aTriangle.draw();							// [  1] - 삼각형
	aCircle.draw();								// [  2] - 원, 중심점( 0, 0 ), 반지름 - 60

	cout << '\n';
	cout << "출력결과는 \"시험출력예시.txt\"를 참고하라" << '\n';
	cout << '\n';


	//--------------------------------------------------------
	// 지금부터 순서대로 문제를 해결하고 답을 답안지에 적는다.
	//--------------------------------------------------------

	//-----------------------------------------------------------------------------------
	// [문제 1] Triangel 객체 한 개의 크기가 몇 byte인지 화면에 출력하고 답지에도 적어라. 
	// 객체의 크기가 왜 그렇게 출력되는지 이유를 상세하게 설명하라.					 (20) 
	//-----------------------------------------------------------------------------------

		// 여기에 들어갈 코드와 출력된 결과(byte 수)를 답지에 적는다.	(코드 10)
		// 출력된 이유를 답지에 적는다.									(이유 10)

	cout << "Triangle 의 크기 : " << sizeof Triangle << endl;

	// 이유 : // Triangle 객체는 기본적으로 Shape 클래스를 상속받고 있으며,
	//  Shape 클래스에는 가상 함수(virtual function)가 존재합니다.
	// 따라서 Triangle 객체에는 vptr(virtual function table pointer)이 존재하며, 이로 인해 객체의 크기가 더 커집니다.


	//--------------------------------------------
	// 다음은 도형을 관리하는데 필요한 변수들이다.
	//--------------------------------------------

	int nShape = 100;					// 현재 관리하는 도형의 개수를 여기에 저장한다
										// 모두 100개의 도형을 만들어 관리한다

	Shape** shapes;						// shapes는 Shape* 주소를 저장할 수 있다
	Shape* pShapes[100];				// pShapes는 Shape* 100개 배열이다

	shapes = pShapes;					// 이제 shapes는 Shape* 100개가 저장된 배열을 가리킨다	


	//----------------------------------------
	// 다형성이 구현됨을 확인해 보는 문제이다.
	//----------------------------------------

	//--------------------------------------------------------------------
	// [문제 2] 위에서 num 개의 도형을 관리할 수 있는 shapes를 생성하였다.
	// 관리하는 도형은 Circle과 Triangle 2가지 종류만 있다.
	// 
	// 랜덤엔진 dre와 랜덤분포 uid를 사용하여 값이 홀수이면 Triangle을, 
	// 짝수라면 Circle을 i번째 도형으로 생성하여
	// 100개의 도형을 shapes가 관리할 수 있도록 하라.				  (20)
	//
	// 생성 방식은 처음의 준비과정에서와 같이 
	// Triangle은 default 생성	
	// Circle은   { Point{}, uidRad( dre ) }을 인자로 생성하라.
	//-------------------------------------------------------------------- 	

	for (int i = 0; i < nShape; ++i) {
		int sel = uid( dre );
		// 랜덤 값 sel 에 따라 i번째 도형을 생성한다.
		// 여기에 들어갈 코드를 적으면 된다.			(코드 20)
		if (sel % 2 == 0) {
			shapes[i] = new Circle{ Point{},uidRad(dre) };
		}
		else {
			shapes[i] = new Triangle{};
		}
	}


	//-----------------------------------------------------
	// [문제 3] 관리하는 모든 도형의 draw() 멤버를 호출하여 
	// 다형성이 구현됨을 보여라.	                   (10)
	//-----------------------------------------------------

	cout << '\n';
	cout << "---------------------------------------------------" << '\n';
	cout << "[문제 3] 관리하는 100개 도형의 draw()를 호출한 결과" << '\n';
	cout << "---------------------------------------------------" << '\n';

	// 여기에 들어갈 코드를 답지에 적는다.			(코드 10)

	for (int i = 0; i < nShape; ++i) {
		shapes[i]->draw();
	}



	//------------------------------------------------------------------------------
	// [문제 4] 함수 findMaxRad()는 shapes와 nShape을 인자로 받아
	// shapes 중에서 가장 반지름 값이 큰 Circle을 찾은 후 그 Circle의 id를 리턴한다.
	// findMaxRad를 아래와 같이 호출하였다.
	// 함수 findMaxRad를 선언하고 정의하라. 					   (선언 5, 정의 15)
	//------------------------------------------------------------------------------

	cout << '\n';
	cout << "--------------------------------" << '\n';
	cout << "[문제 4] 반지름이 가장 큰 Circle" << '\n';
	cout << "--------------------------------" << '\n';

	
	// 이 부분의 주석을 풀고 진행하자
	
	int id = findMaxRad( shapes, nShape );
	cout << "반지름이 가장 큰 Circle => "; 
	shapes[id]->draw( );
	


	//-----------------------------------------------------------------
	// [문제 5] 관리하는 도형의 id값을 기준으로 홀수와 짝수로 분리하라.
	// 홀수가 앞에 오고 짝수는 홀수 뒤에 나온다.
	// qdsort를 사용하여 분리하라.							  (코드 20)
	//-----------------------------------------------------------------

		// 여기에 들어갈 코드를 답지에 적는다.			(20)	
		qsort(shapes, nShape, sizeof(Shape*), [](const void* a, const void* b) {
			const Shape* shapeA = *static_cast<const Shape* const*>(a);
			const Shape* shapeB = *static_cast<const Shape* const*>(b);
			
			if (shapeA->getId() % 2 == 1 && shapeB->getId() % 2 == 0) {
				return -1; 
			}
			else if (shapeA->getId() % 2 == 0 && shapeB->getId() % 2 == 1) {
				return 1;
			}
			else {
				return shapeA->getId() - shapeB->getId();
			}
		});



	cout << '\n';
	cout << "-------------------------------------------------------------------" << '\n';
	cout << "[문제 5] 홀수와 짝수로 분리 후 관리하는 도형의 draw()를 호출한 결과" << '\n';
	cout << "-------------------------------------------------------------------" << '\n';

	// draw 코드는 의도에 따라 감추었다.  
	for (int i = 0; i < nShape; ++i)
		shapes[i]->draw();



	//--------------------=-===-------------------------------------------------------- 
	// [문제 6 설명] 현재 shapes는 100개 도형의 주소를 저장하고 있는 메모리를 가리킨다.
	// 100개 도형 중에서 Circle만 골라 다른 메모리에 저장하려고 한다.
	// Circle만 따로 저장할 메모리에는 Circle을 복사하지 않고 
	// Circle이 저장된 주소만 복사해도, 원하는 문제를 해결하기에 충분하다고 생각한다.
	//-------------------------=====-----=--------------------------------------------- 

	//----------------------------------------------------------------------------------
	// [문제 6] 다음 순서에 따라 코딩하라.											(60)
	// 
	// (6-1) 100개 도형 중에서 Circle은 모두 몇 개인지 세어라. 
	//										-> Circle의 개수를 nCircle에 저장하라.	(10)
	//
	// (6-2) Circle* 형식의 자료 Circle개를 저장할 수 있는 메모리를 확보하라. 
	//										-> 이 메모리를 circles로 명명하라.		(10)
	// 
	// (6-3) shapes 중에서 nCircle개의 Circle*를 circles에 복사하라.				(10)
	// 	
	// (6-4) circles를 반지름 기준 오름차순으로 정렬하라. (qsort 사용)				(10)
	// 	
	// (6-5) [문제 1]에서 [문제 6]까지 해결하면서 사용한 메모리를 모두 반환하라.	(20)
	// 
	// (주의) 답지에 (6-1)~(6-5)답을 구분해서 적을 것	
	// (주의) 문제와 관련하여 선언한 변수나 객체를 잊지말고 적을 것
	//----------------------------------------------------------------------------------


	cout << '\n';
	cout << "-----------------------------------------------------------------" << '\n';
	cout << "[문제 6] shapes중에서 nCircle개의 Circle 만 따로 관리하는 circles" << '\n';
	cout << "-----------------------------------------------------------------" << '\n';

	int nCircle{};
	for (int i = 0; i < nShape; ++i) {
		if (dynamic_cast<Circle*>(shapes[i])) {
			++nCircle;
		}
	}

	cout << '\n';
	cout << "(6-1) nShape 중에서 Circle의 수 - "<< nCircle << '\n';

	Circle** circles = new Circle * [nCircle];

	int circleIndex = 0;
	for (int i = 0; i < nShape; ++i) {
		if (Circle* circle = dynamic_cast<Circle*>(shapes[i])) {
			circles[circleIndex++] = circle;
		}
	}

	cout << '\n';
	cout << "(6-3) circles의 draw 호출" << '\n';
	
	for (int i = 0; i < nCircle; ++i) {
		circles[i]->draw();
	}


	cout << '\n';
	cout << "(6-4) 반지름 기준 오름차순으로 정렬한 이후 circles의 draw 호출" << '\n';

	qsort(circles, nCircle, sizeof(Circle*), [](const void* a, const void* b) {
		const Circle* circleA = *static_cast<const Circle* const*>(a);
		const Circle* circleB = *static_cast<const Circle* const*>(b);
		return static_cast<int>(circleA->getRad() - circleB->getRad());
		});

	for (int i = 0; i < nCircle; ++i) {
		circles[i]->draw();
	}

	// 메모리 해제

	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}
	delete[] shapes;

}