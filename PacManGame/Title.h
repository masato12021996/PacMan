#pragma once
#include "smart_ptr.h"

PTR( Title );

class Title {
public:
	Title( );
	virtual ~Title( );
public:
	void update( );
	bool isEndTitle( );
};

