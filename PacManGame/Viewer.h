#pragma once
#include "Task.h"
#include <string>

PTR( Viewer );

class Viewer : public Task {
public:
	static ViewerPtr getTask( );
	static std::string getTag( ){ return "VIEWER"; };
public:
	Viewer( );
	virtual ~Viewer( );
public:
	void initialize( );
	void update( );
private:
	void drawTitle( );
	void drawPlayGame( );
};

