#pragma once
#include "Task.h"
#include <string>

PTR( Viewer );
PTR( ViewerTitle );
PTR( ViewerPlay );
PTR( GraphManager );
PTR( Stage );

class Viewer : public Task {
public:
	static ViewerPtr getTask( );
	static std::string getTag( ){ return "VIEWER"; };
public:
	Viewer( );
	virtual ~Viewer( );
public:
	void update( );
	void initialize( );
private:
	GraphManagerPtr _graph_manager;
	ViewerTitlePtr _titile;
	ViewerPlayPtr _play;
};