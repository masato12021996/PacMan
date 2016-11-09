#pragma once
#include "smart_ptr.h"
#include "Field.h"

PTR( Stage );

class Stage {
public:
	enum CLEAR_TREMS {
		CLEAR_TREMS_FOOD_EAT,//�a��S�ĐH�ׂ�
		CLEAR_TREMS_ENEMY_EAT,//�G��S�ĐH�ׂ�
		CLEAR_TREMS_OUTRUN,//�����؂�
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
	void loadStage( );
	void setTrems( CLEAR_TREMS trems );
	void setTargetCell( OBJECT_NAME object );
private:
	static const int MAP_SIZE_X = Field::MAP_CHIP_NUM_X;
	static const int MAP_SIZE_Y = Field::MAP_CHIP_NUM_Y;
	CLEAR_TREMS _trems;
	OBJECT_NAME _map[ MAP_SIZE_X ][ MAP_SIZE_Y ];
};