#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Player );
PTR( Animation );

class Player {
public:
	Player( );
	virtual ~Player( );
public:
	void create( const Vector& pos );
	void update( );
	Vector getPos( ) const;
	Vector getDir( ) const;
	bool isDead( ) const;
private:
	void InputControlDir( );
private:
	Vector _pos;
	Vector _dir;
	bool _is_dead;
	AnimationPtr _animation;
};
