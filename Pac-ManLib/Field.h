#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"
#include "MapDefine.h"
#include <array>

PTR( Field );

/*-------------------------------------------
[フィールドの管理クラス]
壁やアイテムの位置管理をする。
プレイヤーやエネミーの位置はここでは持たない。
-------------------------------------------*/

class Field {
public:
	enum OBJECT {
		OBJECT_NULL,
		OBJECT_WALL,
		OBJECT_BATE,
		OBJECT_POWER_BATE
	};
public:
	Field( );
	virtual ~Field( );
public:
	void initialize( );
	void setFieldTarget( int x, int y, OBJECT object );
	OBJECT getFieldTarget( int x, int y ) const;
	int getSizeX( ) const;
	int getSizeY( ) const;
	bool isNotBate( ) const;
	int getRootNum( const int target_x, const int target_y, const int start_x, const int start_y );
private:
	int getIndex( int x, int y ) const;
private:
	static const int MAP_CHIP_NUM_X = MapParameter::MAP_SIZE_X;
	static const int MAP_CHIP_NUM_Y = MapParameter::MAP_SIZE_Y;
	static const int CHIP_SIZE = MapParameter::CHIP_SIZE;
	static const int MAP_MAX_INDEX = MAP_CHIP_NUM_X * MAP_CHIP_NUM_Y;
private:
	std::array< OBJECT, MAP_MAX_INDEX > _field;
};
