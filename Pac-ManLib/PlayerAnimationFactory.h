#pragma once
#include "smart_ptr.h"

PTR( PlayerAnimationFactory );
PTR( Animation );

class PlayerAnimationFactory {
public:
	enum STATE {
		STATE_WAIT,
		STATE_WALK,
	};
public:
	PlayerAnimationFactory( );
	virtual ~PlayerAnimationFactory( );
public:
	static AnimationPtr createAnimation( STATE state );
};