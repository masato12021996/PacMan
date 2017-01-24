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
	bool isClearStage( ) const;
	bool isDeadStage( ) const;
	FieldPtr getField( ) const;
	PlayerPtr getPlayer( ) const;
	int getEnemyNum( ) const;
	EnemyPtr getEnemy( int index ) const;
	double getTime( ) const;
	int getTrems( ) const;
private:
	FieldPtr _field;
	PlayerPtr _player;
	std::vector< EnemyPtr > _enemies;
	int _trems;
	int _start_time;
	int _stage_time;
};