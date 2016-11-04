#pragma once
#include "smart_ptr.h"

PTR( Object );

/*----------------------------------------------
[フィールド上に存在するオブジェクトの基底クラス]
Tag:このオブジェクトが何かを示す

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