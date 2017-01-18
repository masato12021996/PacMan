#pragma once
#include "Animation.h"

PTR( PlayerChangeDirAnimation );

class PlayerChangeDirAnimation : public Animation {
public:
	enum CHANGE_DIR {
		CHANGE_DIR_LU,
		CHANGE_DIR_LD,
		CHANGE_DIR_RU,
		CHANGE_DIR_RD,
	};
public:
	PlayerChangeDirAnimation( CHANGE_DIR dir );
	virtual ~PlayerChangeDirAnimation( );
};