//-----------------------------------------------------------------------------
// Shape.h
//-----------------------------------------------------------------------------
#pragma once

class Shape {
	static int gid;					// ��ü�� ����Ʈ �����Ҷ����� ������ȣ�� �ο��Ѵ�

protected:							// Shape�� protected �����
	int id;							// �ڽ� Ŭ���������� private ����� �ȴ�.

public:
	Shape() : id( ++gid ) { }

	virtual ~Shape( ) { }			// ��ӱ������� �θ��� �Ҹ��ڴ� virtual �̾�� �Ѵ�

	int getId( ) const {			// id ���� �����ش�
		return id;
	}

	virtual void draw() const = 0;
};

int Shape::gid{ 0 };
