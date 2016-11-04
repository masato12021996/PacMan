#pragma once
#include "smart_ptr.h"

PTR( Object );

/*----------------------------------------------
[�t�B�[���h��ɑ��݂���I�u�W�F�N�g�̊��N���X]
Tag:���̃I�u�W�F�N�g������������

----------------------------------------------*/

class Object {
public:
	enum TAG {
		TAG_WALL,
		TAG_ITEM,
		TAG_PLAYER,
		TAG_ENEMY
	};
public:
	Object( TAG tag );
	virtual ~Object( );
public:
	TAG getTag( ) const;
private:
	TAG _tag;
};