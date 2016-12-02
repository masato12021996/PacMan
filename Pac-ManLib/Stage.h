#pragma once
#include "smart_ptr.h"
#include "MapDefine.h"

PTR( Stage );

class Stage {
public:
	enum CLEAR_TREMS {
		CLEAR_TREMS_FOOD_EAT,//餌を全て食べる
		CLEAR_TREMS_ENEMY_EAT,//敵を全て食べる
		CLEAR_TREMS_OUTRUN,//逃げ切る
		CLEAR_TREMS_MAX
	};
	enum OBJECT_NAME {
		OBJECT_NAME_NONE,
		OBJECT_NAME_PLAYER,
		OBJECT_NAME_ENEMY_RED,
		OBJECT_NAME_ENEMY_PINC,
		OBJECT_NAME_ENEMY_BLUE,
		OBJECT_NAME_ENEMY_ORANGE,
		OBJECT_NAME_BATE,
		OBJECT_NAME_POWER_BATE,
		OBJECT_NAME_WALL,
		OBJECT_NAME_MAX
	};
public:
	Stage( );
	virtual ~Stage( );
public:
	void setTrems( CLEAR_TREMS trems );
	void setTargetCell( int x, int y, OBJECT_NAME object );
	CLEAR_TREMS getTrems( ) const;
	int getTargetCell( int x, int y ) const;
private:
	static const int MAP_SIZE_X = MapParameter::MAP_SIZE_X;
	static const int MAP_SIZE_Y = MapParameter::MAP_SIZE_Y;
	CLEAR_TREMS _trems;
	OBJECT_NAME _map[ MAP_SIZE_Y ][ MAP_SIZE_X ];
};