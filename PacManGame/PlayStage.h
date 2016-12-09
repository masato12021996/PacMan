#pragma once
#include "smart_ptr.h"
#include <vector>

PTR( PlayStage );
PTR( Stage );
PTR( Field );
PTR( Player );
PTR( Enemy );

class PlayStage {
public:
	PlayStage( );
	virtual ~PlayStage( );
public:
	void update( );
	void create( StagePtr stage );
	bool isEndStage( ) const;
	FieldPtr getField( ) const;
	PlayerPtr getPlayer( ) const;
private:
	FieldPtr _field;
	PlayerPtr _player;
	std::vector< EnemyPtr > _enemies;
};