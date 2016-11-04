#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"
#include <array>

PTR( Field );
PTR( Object )

/*-------------------------------------------
[フィールドの管理クラス]
壁やアイテムの位置管理をする。
プレイヤーやエネミーの位置はここでは持たない。
-------------------------------------------*/

class Field {
public:
	static const int CHIP_SIZE = 32;
	static const int MAP_CHIP_NUM_X = 30;
	static const int MAP_CHIP_NUM_Y = 24;
public:
	Field( );
	virtual ~Field( );
public:
	void initialize( );
	void setFieldTarget( const Vector& pos, ObjectPtr object );
	ObjectPtr getFieldTarget( const Vector& pos ) const;
	int getSizeX( ) const;
	int getSizeY( ) const;
private:
	int getIndex( const Vector& pos ) const;
private:
	static const int MAP_MAX_INDEX = MAP_CHIP_NUM_X * MAP_CHIP_NUM_Y;
private:
	const int CHIP_SIZE_X = CHIP_SIZE;
	const int CHIP_SIZE_Y = CHIP_SIZE;
	std::array< ObjectPtr, MAP_MAX_INDEX > _field;
};
