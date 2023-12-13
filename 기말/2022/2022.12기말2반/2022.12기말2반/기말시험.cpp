//--------------------------------------------------------------------------
// 기말시험.cpp 
// 
// (주의) 헤더 파일의 class를 마음대로 수정하여 문제를 해결하면 안됨
// 컴파일 환경 - Release/X64, 언어표준 최신
//---------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <fstream>
#include "game.h"
#include "player.h"
#include "monster.h"
#include "tree.h"
using namespace std;


//-----------------------------------------------------------------------------------------
// 다수의 플레이어, 몬스터, 나무 객체가 있는 게임을 만드는 중이다.
//
// 부모 클래스 Game을 이용하여 다형성을 구현하려 한다.
// Game 클래스에 render()를 순수가상함수로 만들어 모든 자식 클래스가 오버라이드하게 하였다.
//
// 부모 클래스 - Game
// 자식 클래스 - Player, Monster, Tree
//-----------------------------------------------------------------------------------------


default_random_engine dre{ 202212 };				// 객체 생성에 사용할 엔진

//--------
int main()
//--------
{
	// 프로젝트를 문제의 그림과 같이 만들었다면 다음 코드가 문제없이 컴파일되고 실행될 것이다.
	// 출력결과는 "기말시험출력예시.txt"를 참고하라.

	{
		cout << "-----------------------------------------------" << endl;
		cout << "기말시험 - 플레이어, 몬스터, 나무를 생성해 본다" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << endl;

		Player aPlayer;
		Monster aMonster;
		Tree aTree;

		aPlayer.render();
		aMonster.render();
		aTree.render();
	}


	//-----------------------------------
	// 다형성을 구현하는 코드를 작성한다
	//-----------------------------------

	//-------------------------------------------------------------------------------
	// 이 게임에는 플레이어, 몬스터, 나무의 숫자를 합쳐 모두 num개의 객체가 존재한다.
	// 이 객체들의 부모 클래스는 Game이다.
	//-------------------------------------------------------------------------------

	ifstream in{ "기말시험.txt" };			// 여기에는 몇 개인지 모르는 int가 저장되어 있다.
	int num{ };								// 객체의 개수


	//--------------------------------------------------------
	// 지금부터 문제를 순서대로 해결하고 답을 답안지에 적는다.
	//--------------------------------------------------------

	// [문제 1] 파일 "기말시험.txt"에는 몇 개인지 모르는 int 값이 text로 저장되어 있다.
	// 생성할 객체의 개수 num은 
	// 파일 "기말시험.txt"에 저장되어 있는 int의 값에서 숫자 1의 개수를 세서 정해보자.

	// 파일을 읽어 모두 몇 개의 "1"이 기록되어 있는 지 화면에 출력하고 그 값을 num에 저장하라.
	// 화면 출력한 값을 답지에도 써라.						(20) (코드 15, 갯수 5)


		// 여기에 들어갈 코드를 답지에 적는다.				(15점)
		// 화면 출력결과를 답지에 적는다.					(5점)





	//------------------------------------------------------------------------------------------
	// num개 만큼의 객체를 생성하여 다형성을 구현해 보는 문제이다.
	//  - 생성할 객체는 Player, Monster, Tree 중 하나이다
	//------------------------------------------------------------------------------------------
	// 앞 문제에서 int의 개수를 알지 못하였으면 num = 100 이라고 가정하고 이하 문제를 풀면 된다.
	// 답지에 num = 100 으로 가정하고 문제를 풀었다고 적어 놓자.
	//------------------------------------------------------------------------------------------


	// [문제 2] 다형성을 시험할 수 있도록, num개의 게임 객체를 관리할 수 있는 메모리를 생성하라.	(10)

		// 여기에 들어갈 코드를 답지에 적는다.					(10점)





	uniform_int_distribution<int> ui{ 0, 2 };


	// [문제 3] sel 값에 따라 [문제 2]에서 생성한 메모리에 게임 객체 num개를 생성하여 저장하라.		(10)

	for (int i = 0; i < num; ++i) {
		int sel = ui(dre);	

		// sel 값에 따라 객체를 생성하여 저장하라. 
		// sel 값이 0이면 Player, 1이면 Monster, 2이면 Tree를 생성한다. 
		// 여기에 들어갈 코드를 답지에 적는다.					(10점)







	}





	// [문제 4] 관리하는 num개 객체의 render()를 호출하여 다형성이 구현됨을 확인하라.			(10)

	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "[문제 4] num개 객체의 render를 호출                    " << endl;
	cout << " 참고 - render 호출 전에 loop 변수 값을 화면 출력하였다" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << endl;

		// 여기에 들어갈 코드를 답지에 적는다. (10점)









	// [문제 5] 범위 [0, num-1] 내의 숫자를 입력받아 해당 숫자의 객체를 삭제하는 코드를 작성하려 한다.
	// 부족한 부분을 채워 코드를 완성하라.		(30)
	// 해당 객체를 메모리에서 삭제하고 전체 갯수를 조정하여야 한다. 출력예시를 참조하라.
	// -1을 입력하면 반복문을 끝낸다.
	// 항상 유효한 숫자가 입력된다고 가정한다(입력한 숫자가 유효한지 검사할 필요는 없다.)


	while ( true ) {
		cout << endl;
		cout << "[0] ~ " << "[" << num - 1 << "] 범위에서 번호로 객체를 삭제합니다." << endl;
		cout << "끝내려면 -1을 입력하세요" << endl;

		int n;

		cout << endl;
		cout << "지울 객체의 번호를 입력하세요? ";
		cin >> n;
		if ( n == -1 )
			break;

		// 여기에 들어갈 코드를 답지에 적는다. (30점)






		
		// 여기에서 문제4의 답을 활용하여 render를 출력해 보았다. 
		// 따라서 출력 코드는 보이지 않는다.

	}

	
	
	//----------------------------------------------------------------------------------------------------
	// 함수 fightingKorea()는 [문제 2]에서 생성한 변수와 객체의 수 num을 인자로 받아 다음과 같이 동작한다.
	//
	// 각 객체를 검사하여 
	//		그 객체가 Player이고 
	//			그 Player의 국가가 Korea라면 hp 값을 1000으로 만든다.
	//----------------------------------------------------------------------------------------------------


	// [문제 6] 이러한 동작을 하는 함수 fightingKorea 함수를 선언하고 정의한 후 호출하라.	(30)
	// (선언, 정의, 호출을 구분하여 답지에 적어라)

	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "[문제 6] fightingKorea()를 호출한 후 다시 render()를 호출한 결과" << endl;
	cout << "----------------------------------------------------------------" << endl;


		// 여기에서 fightingKorea 함수를 호출하였다. 
		// (선언 10점)(정의 10점)(호출 10점) - 각 코드의 위치를 구분해서 답지에 적어라.

	

		// 여기에서 문제4의 답을 활용하여 render를 출력해 보았다. 
		// 따라서 출력 코드는 보이지 않는다.





	// [문제 7] 할당받은 메모리가 있다면 깨끗이 정리하고 프로그램을 끝내라.	(10)
	// (1바이트도 해제하지 못한 메모리가 있으면 안된다)

		// 여기에 들어갈 코드를 답지에 적는다. (10점)
}

