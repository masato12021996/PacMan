#pragma once
#include "smart_ptr.h"

PTR( EnemyAnimationFoctory );
PTR( Animation );

class EnemyAnimationFoctory {
public:
	enum ENEMY_COLOR {
		ENEMY_COLOR_RED,
		ENEMY_COLOR_ORANGE,
		ENEMY_COLOR_BLUE,
		ENEMY_COLOR_PINC
	};
	enum STATE {
		STATE_WALK_LEFT,
		STATE_WALK_RIGHT,
		STATE_WALK_DOWN,
		STATE_WALK_UP,
		STATE_BAD,
		STATE_BAD_END
	};
public:
	EnemyAnimationFoctory( ENEMY_COLOR color );
	virtual ~EnemyAnimationFoctory();
public:
	AnimationPtr createAnimation( STATE state );
private:
	ENEMY_COLOR _color;
};

