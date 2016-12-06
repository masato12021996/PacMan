#pragma once
#include "smart_ptr.h"

PTR( ViewerTitle );

class ViewerTitle {
public:
	ViewerTitle( );
	virtual ~ViewerTitle( );
public:
	void update( );
};