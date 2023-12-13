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
	// Q1. Triangle ��ü�� ũ�� ���.

	// �Ʒ��� �ڵ�
	cout <<"Triangle ��ü�� ũ�� : " << sizeof new Triangle() << endl;


	// Loop On
	while (1) {
		cout << "������ ������ ����: ";
		int num;
		cin >> num;

		if (num == 0)
			break;
		

		// Q2. ����ڰ� �Է��� ���ڳ�ŭ ������ ������ �� �ִ� �޸� Ȯ��

		// �Ʒ��� �ڵ�
		Shape** shapes = new Shape * [num];


		// Q3. ���� ������ ������ ����Ͽ� ���� Ȧ���̸� Triangle,
		// ¦���̸� Circle�� i��° �������� �����Ͽ� [Q2]���� Ȯ���� �޸𸮿� �����϶�

		for (int i{}; i < num; ++i) {
			// �Ʒ��� �ڵ�
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

		// Q4. ������ draw ����� ȣ���Ͽ� �������� �������� ������
		cout << endl << "Q4 ��� ���" << endl;

		// �Ʒ��� �ڵ�
		
		for (int i = 0; i < num; ++i) {
			shapes[i]->draw();
		}


		// Loop End

		// Q5. �������� ���̴� �� ������ ������ �ݺ� ���� �ǵ���
		// Loop On - Loop End �κп� while������ ���մٰ� ����
		// while������ ���� �κ��� �������� �����ϰ� �ذ�
		// ��� �κп� � �ڵ尡 ���� �ϴ� �� ��Ȯ�ϰ� ���� ��

		// �޸� ����
		for (int i = 0; i < num; ++i) {
			delete shapes[i];
		}
		delete[] shapes;


	}

	// Q6. num��ŭ ������ ������ ���¿��� ���� �� ���� �߰��Ϸ� �Ѵ�.
	// num���� 50% �� ���� ������ ������ ���� �� �ִ� �ڵ带 �ۼ��ϰ� Circle�� �Ѱ� �߰��϶�.
	// Q5�� while loop�ʹ� ���谡 ����.
	// num�� 10��� 15���� ���� �� �ִ� �ڵ带 �ۼ��ϰ�,
	// ���� 10�� ������ ������ �����Ǿ�� �Ѵ�.
	// Q2���� ���� ������ �޸� �̸����� ������ ������ access �� �� �־���Ѵ�.

	cout << endl << "Q6 ��°�� - (num + 1)���� ����ϸ� ��" << endl;

	//// �Ʒ��� �ڵ�


	
}