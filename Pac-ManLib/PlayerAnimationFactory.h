#pragma once
#include "smart_ptr.h"

PTR( PlayerAnimationFactory );
PTR( Animation );

class PlayerAnimationFactory {
public:
	enum STATE {
		STATE_WALK_LEFT,
		STATE_WALK_RIGHT,
		STATE_WALK_DOWN,
		STATE_WALK_UP,
		STATE_CHANGE_DIR_LU,
		STATE_CHANGE_DIR_LD,
		STATE_CHANGE_DIR_RU,
		STATE_CHANGE_DIR_RD,
		STATE_DEAD
	};
public:
	PlayerAnimationFactory( );
	virtual ~PlayerAnimationFactory( );
public:
	static AnimationPtr createAnimation( STATE state );
};