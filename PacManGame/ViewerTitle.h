#pragma once
#include "smart_ptr.h"

PTR( ViewerTitle );
PTR( GraphManager );

class ViewerTitle {
public:
	ViewerTitle( GraphManagerPtr graph_manager );
	virtual ~ViewerTitle( );
public:
	void update( );
private:
	GraphManagerPtr _graph_manager;
};