#pragma once
#include "Enemy.h"

PTR( EnemyRed );

class EnemyRed : public Enemy {
public:
	EnemyRed( const Vector& pos );
	virtual ~EnemyRed( );
private:
	void actor( );
};

