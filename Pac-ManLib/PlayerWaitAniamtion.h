#pragma once
#include "smart_ptr.h"
#include "Animation.h"

PTR( PlayerWaitAniamtion );

class PlayerWaitAniamtion : public Animation {
public:
	PlayerWaitAniamtion( );
	virtual ~PlayerWaitAniamtion( );
};