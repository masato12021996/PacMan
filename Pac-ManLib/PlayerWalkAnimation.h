#pragma once
#include "Animation.h"
#include "smart_ptr.h"

PTR( PlayerWalkAnimation );

class PlayerWalkAnimation : public Animation {
public:
	PlayerWalkAnimation( );
	virtual ~PlayerWalkAnimation( );
};

