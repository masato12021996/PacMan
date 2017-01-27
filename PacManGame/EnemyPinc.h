#pragma once
#include "Enemy.h"

PTR( EnemyPinc );

class EnemyPinc : public Enemy {
public:
	EnemyPinc( const Vector& pos );
	virtual ~EnemyPinc( );
private:
	void actor( );
};

