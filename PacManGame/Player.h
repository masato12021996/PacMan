#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Player );
PTR( Animation );
PTR( Field );

class Player {
public:
	enum STATE {
		STATE_WAIT,
		STATE_WALK,
		STATE_CHANGE_DIR,
	};
public:
	Player( FieldPtr field );
	virtual ~Player( );
public:
	void create( const Vector& pos );
	void update( );
	Vector getPos( ) const;
	Vector getDir( ) const;
	void stateUpdate( );
	AnimationPtr getAnimation( ) const;
	bool isExpired( ) const;
private:
	void InputControlDir( );
	void move( );
	bool canMove( Vector pos );
	bool onMap( Vector pos );
	void posNormalize( );
	void animator( );
private:
	Vector _pos;
	Vector _dir;
	bool _is_expired;
	AnimationPtr _animation;
	FieldPtr _field;
	STATE _state;

	STATE _befor_state;
	Vector _befor_dir;
	Vector _befor_pos;
};

