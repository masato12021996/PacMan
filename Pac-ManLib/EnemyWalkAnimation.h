#pragma once
#include "Animation.h"

PTR( EnemyWalkAnimation );

class EnemyWalkAnimation : public Animation {
public:
	enum COLOR {
		COLOR_BLUE,
		COLOR_RED,
		COLOR_ORANGE,
		COLOR_PINC
	};
	enum WALK_DIR {
		WALK_DIR_LEFT,
		WALK_DIR_RIGHT,
		WALK_DIR_DOWN,
		WALK_DIR_UP
	};
public:
	EnemyWalkAnimation( COLOR color, WALK_DIR dir );
	virtual ~EnemyWalkAnimation( );
};

