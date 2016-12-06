#pragma once
#include "smart_ptr.h"

PTR( ViewerPlay );
PTR( PlayGame );
PTR( Stage );

class ViewerPlay {
public:
	ViewerPlay( );
	virtual ~ViewerPlay( );
public:
	void update( );
private:
	void drawStage( StagePtr stage );
private:
	PlayGamePtr _play_game;
};