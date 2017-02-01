#pragma once
#include "Enemy.h"

PTR( EnemyBlue );

class EnemyBlue : public Enemy {
public:
	EnemyBlue( const Vector& pos );
	virtual ~EnemyBlue( );
private:
	void actor( );
};

