//-----------------------------------------------------------------------------
// Monster.h
//
// ��� Monster�� �θ� Ŭ�����̴�.
// Monster�� �ڽŸ��� Ư������� ���´�
// Monster�� ����Ϸ��� special ����� �����ؾ� �Ѵ�.
//-----------------------------------------------------------------------------

#pragma once

class Monster {

protected:							// �ڽ� Ŭ������ protected ����� �ڽ��� private ����� ����� �� �ִ�.
	int id;							// ������ ��� ���Ϳ� �ٴ� id
										
public:
	Monster();
	~Monster();

	int getId( ) const;				// id ���� �˷��ش�

	virtual void special() = 0;		// Ư�����
};

