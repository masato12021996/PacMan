#pragma once
#include "smart_ptr.h"

PTR( PlayerAnimationFactory );
PTR( Animation );

class PlayerAnimationFactory {
public:
	enum STATE {
		STATE_WAIT,
		STATE_WALK_LEFT,
		STATE_WALK_RIGHT,
		STATE_WALK_DOWN,
		STATE_WALK_UP
	};
public:
	PlayerAnimationFactory( );
	virtual ~PlayerAnimationFactory( );
public:
	static AnimationPtr createAnimation( STATE state );
};