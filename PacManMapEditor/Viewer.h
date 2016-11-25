#pragma once
#include "Task.h"
#include <string>

PTR( Viewer );
PTR( GraphManager );

class Viewer : public Task {
public:
	static ViewerPtr getTask( );
	static std::string getTag( ) { return "VIEWER"; }
public:
	Viewer( );
	virtual ~Viewer( );
public:
	void update( );
private:
	void drawMatrix( );
	void drawObject( );
	void drawTremsButton( );
	void drawObjectButton( );
	void drawContorlButton( );
private:
	GraphManagerPtr _graph_manager;
};