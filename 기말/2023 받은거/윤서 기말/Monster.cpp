//-----------------------------------------------------------------------------
// Monster.CPP
//-----------------------------------------------------------------------------

#include "Monster.h"

int gid{ 0 };					// Monster ������ �� ���� id�� �ο���

Monster::Monster() 
	: id( ++gid )
{
}

Monster::~Monster()
{

}

int Monster::getId( ) const 	// id ���� �˷��ش�
{
	return id;
}
