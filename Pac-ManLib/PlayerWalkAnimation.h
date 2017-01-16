#pragma once
#include "Animation.h"
#include "smart_ptr.h"

PTR( PlayerWalkAnimation );

class PlayerWalkAnimation : public Animation {
public:
	enum WALK_DIR {
		WALK_DIR_LEFT,
		WALK_DIR_RIGHT,
		WALK_DIR_DOWN,
		WALK_DIR_UP
	};
public:
	PlayerWalkAnimation( WALK_DIR dir );
	virtual ~PlayerWalkAnimation( );
};

