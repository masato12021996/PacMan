#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Mouse );

class Mouse {
public:
	enum INPUT {
		INPUT_LEFT,
		INPUT_RIGHT
	};
public:
	Mouse( );
	virtual ~Mouse( );
public:
	Vector getPoint( ) const;
	bool isInputButton( INPUT input ) const;
};

