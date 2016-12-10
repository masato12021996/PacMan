#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Player );
PTR( Animation );
PTR( Field );

class Player {
public:
	Player( FieldPtr field );
	virtual ~Player( );
public:
	void create( const Vector& pos );
	void update( );
	Vector getPos( ) const;
	Vector getDir( ) const;
	AnimationPtr getAnimation( ) const;
	bool isDead( ) const;
private:
	void InputControlDir( );
	void move( );
	bool canMove( Vector pos );
	bool onMap( Vector pos );
	void posNormalize( );
private:
	Vector _pos;
	Vector _dir;
	bool _is_dead;
	AnimationPtr _animation;
	FieldPtr _field;
};

