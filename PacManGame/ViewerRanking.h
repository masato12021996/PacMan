#pragma once
#include "smart_ptr.h"

PTR( ViewerRanking );
PTR( GraphManager );

class ViewerRanking {
public:
	ViewerRanking( GraphManagerPtr graph_manager );
	virtual ~ViewerRanking( );
public:
	void update( );
private:
	GraphManagerPtr _graph_manager;
};

