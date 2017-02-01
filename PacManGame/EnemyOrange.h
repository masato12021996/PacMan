#pragma once
#include "Enemy.h"

PTR( EnemyOrange );

class EnemyOrange : public Enemy {
public:
	EnemyOrange( const Vector& pos );
	virtual ~EnemyOrange();
private:
	void actor( );
private:
	int _counter;
};

