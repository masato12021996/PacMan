#pragma once
#include "smart_ptr.h"

PTR( ViewerPlay );
PTR( PlayGame );
PTR( PlayStage );

class ViewerPlay {
public:
	ViewerPlay( );
	virtual ~ViewerPlay( );
public:
	void update( );
private:
	void drawReady( );
	void drawPlay( );
	void drawResult( );
	void drawField( PlayStagePtr stage );
private:
	PlayGamePtr _play_game;
};