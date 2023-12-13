#pragma once

class Shape {
	static int gid;					// ��ü�� ����Ʈ �����Ҷ����� ������ȣ�� �ο��Ѵ�

protected:							// Shape�� protected �����
	int id;							// �ڽ� Ŭ���������� private ����� �ȴ�.

public:
	Shape() : id( ++gid ) { }

	virtual void draw() const = 0;
};

int Shape::gid{ 0 };
