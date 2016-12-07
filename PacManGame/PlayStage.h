#pragma once
#include "smart_ptr.h"

PTR( PlayStage );
PTR( Stage );

class PlayStage {
public:
	PlayStage( );
	virtual ~PlayStage( );
public:
	void update( );
	void create( StagePtr stage );
	bool isEndStage( ) const;
private:
	StagePtr _stage;
};