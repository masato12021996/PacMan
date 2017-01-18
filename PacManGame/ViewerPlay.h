#pragma once
#include "smart_ptr.h"

PTR( ViewerPlay );
PTR( PlayGame );
PTR( PlayStage );
PTR( GraphManager );

class ViewerPlay {
public:
	ViewerPlay( GraphManagerPtr graph_manager );
	virtual ~ViewerPlay( );
public:
	void update( );
private:
	void drawReady( );
	void drawPlay( );
	void drawResult( );
	void drawField( PlayStagePtr stage );
	void drawPlayer( PlayStagePtr stage );
	void drawTime( double time );
	void drawClearStageNum( );
private:
	PlayGamePtr _play_game;
	GraphManagerPtr _graph_manager;
};