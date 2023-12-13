//-----------------------------------------------------------------------------
// 시험3.cpp - 헤더 파일의 class를 수정하면 안된다.
//
//-----------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <fstream>
#include "game.h"
#include "player.h"
#include "monster.h"
#include "tree.h"
using namespace std;

//-----------------------------------------------------------------------------------------
// 플레이어, 몬스터, 나무 객체들이 여러 개 존재하는 게임을 구상 중이다.
//
// 다형성을 구현할 수 있도록 조상 클래스 Game을 만들었다.
// Game 클래스에 render()를 순수가상함수로 만들어 모든 자식 클래스가 오버라이드하게 하였다.
//
// 부모 클래스 - Game
// 자식 클래스 - Player, Monster, Tree
//-----------------------------------------------------------------------------------------

void f(Game** game, int num) { //선언
	//정의
	for (int i = 0; i < num; ++i) {
		if (dynamic_cast<Player*>(game[i])) {
			Player* player = dynamic_cast<Player*>(game[i]);
			if (player->getNation() == 0)
				player->setHp(0);
		}
	}

}

int main()
{
	// 프로젝트를 그림과 같이 만들었다면 다음 코드가 문제없이 컴파일되고 실행될 것이다.


	cout << "--------------------------------------------------" << endl;
	cout << "시험3 - 플레이어, 몬스터, 나무를 1개씩 생성해 본다" << endl;
	cout << "--------------------------------------------------" << endl;

	Player p;
	Monster m;
	Tree t;

	p.render();
	m.render();
	t.render();



	//-----------------------------------
	// 다형성을 구현하는 코드를 작성한다
	//-----------------------------------

	// 이 게임에는 플레이어, 몬스터, 나무의 숫자를 합쳐 모두 num개의 객체가 존재한다.
	// 이들 모두의 조상은 Game 클래스이다.

	// 객체의 수 num은 다음 파일에 저장되어 있는 int의 개수이다.

	ifstream in{ "시험3.txt" };			// 여기에는 몇 개인지 모르는 int가 저장되어 있다.
	int num{ };


	//--------------------------------------------------------
	// 지금부터 문제를 순서대로 해결하고 답을 답안지에 적는다.
	//--------------------------------------------------------

	// [문제 1] 파일 "시험3.txt"에는 몇 개인지 모르는 int 값이 저장되어 있다.
	// 파일을 읽어 모두 몇 개의 int가 기록되어 있는 지 num에 기록한 후 화면에 출력하고 답지에도 써라.	(20) (코드 15, 개수 5)
	// 
	// 여기에 들어갈 코드를 답지에 적는다.  ~15
	int result{};
	while (in >> result) {
		++num;
	}

	// 화면 출력결과를 답지에 적는다. ~5


	cout << num << endl;

	//--------------------------------------------------------------------------------------------
	// num개의 객체를 생성하여 다형성을 구현해 보는 문제이다.
	//  - 각 객체는 Player, Monster, Tree 중 하나가 될 수 있다
	//--------------------------------------------------------------------------------------------
	// int의 개수를 알지 못하면 num = 123 이라고 가정하고 이하 문제를 풀면 된다.
	// 답지에 num = 123 으로 가정하고 문제를 풀었다고 적어 놓자.
	// 주의 - 변수 num을 사용해서 문제를 풀어야 한다. ( 위의 int num { }; --> int num { 123 }; )						
	//--------------------------------------------------------------------------------------------


	// [문제 2] num개의 객체를 관리할 수 있는 변수를 생성하라.									(10)

		// 여기에 들어갈 코드를 답지에 적는다. ~10
		Game** game = new Game*[num];

	// [문제 3] sel 값에 따라 [문제 2]에서 생성한 변수에 객체 num개를 생성하여 저장하라.		(10)

	uniform_int_distribution<int> uid{ 0, 2 };
	default_random_engine dre;

	for (int i = 0; i < num; ++i) {
		int sel = uid(dre);

		// sel 값에 따라 객체를 생성하여 저장하라. 
		// sel 값이 0이면 Player, 1이면 Monster, 2이면 Tree를 생성한다. 
		// 여기에 들어갈 코드를 답지에 적는다. ~10

		switch (sel) {
		case 0:
			game[i] = new Player();
			break;
		case 1:
			game[i] = new Monster();
			break;
		case 2:
			game[i] = new Tree();
			break;
		}

	}


	// [문제 4] 관리하는 num개 객체의 render()를 호출하여 다형성이 구현됨을 확인하라.			(10)

	cout << "-----------------------------------" << endl;
	cout << "[문제 4] num개 객체의 render를 호출" << endl;
	cout << "-----------------------------------" << endl;

	// 여기에 들어갈 코드를 답지에 적는다. ~10

	for (int i = 0; i < num; ++i)
		game[i]->render();



	// [문제 5] num개의 객체 중 나무는 몇 그루인가 세서 출력하고 답지에도 적어라.				(20) (코드 15, 개수 5)
	cout << "-------------------------" << endl;
	cout << "[문제 5] 생성한 나무의 수" << endl;
	cout << "-------------------------" << endl;

	int numOfTree{ 0 };

	// 여기에 들어갈 코드를 답지에 적는다. ~15
	for (int i = 0; i < num; ++i) {
		if (dynamic_cast<Tree*>(game[i])) {
			numOfTree++;
		}
	}


	// 문제 5 결과 출력 예시
	cout << "num개 객체 중 나무의 수 - " << numOfTree << endl;

	// 출력되는 개수도 답지에 적는다. ~5


	//-----------------------------------------------------------------------------------------
	// 함수 f()는 [문제 2]에서 생성한 변수와 객체의 수 num을 인자로 받아 다음과 같이 동작한다.
	//
	// 각 객체를 검사하여 
	//		그 객체가 Player이고 
	//			그 Player의 국가가 Korea가 아니라면 hp 값을 0으로 만든다.
	//-----------------------------------------------------------------------------------------	


	// [문제 6] 이러한 동작을 하는 함수 f를 선언하고 정의한 후 호출하라.						(30)
	// (선언, 정의, 호출을 구분하여 답지에 적어라)
	f(game, num); //호출
	
	cout << "----------------------------------------------------" << endl;
	cout << "[문제 6] f()를 호출한 후 다시 render()를 호출한 결과" << endl;
	cout << "----------------------------------------------------" << endl;

	// 여기에 들어갈 코드를 답지에 적는다. (선언 ~10)(정의 ~10)(호출 ~10)
	
	for (int i = 0; i < num; ++i) {
		game[i]->render();
	}

	// [문제 7] 할당받은 메모리가 있다면 깨끗이 정리하고 프로그램을 끝내라.						(10)
	// (1바이트도 해제하지 못한 메모리가 있으면 안된다)


	// 여기에 들어갈 코드를 답지에 적는다. ~10

	for (int i = 0; i < num; ++i) {
		delete game[i];
	}

	delete[] game;

}
