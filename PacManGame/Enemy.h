#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Enemy );
PTR( Player )
PTR( Field );
PTR( Animation );
PTR( EnemyAnimationFoctory );

class Enemy {
protected:
	enum COLOR{
		COLOR_RED,
		COLOR_BLUE,
		COLOR_ORANGE,
		COLOR_PINC,
		COLOR_MAX
	};
public:
	enum STATE {
		STATE_WALK,
		STATE_BAD,
		STATE_BAD_END
	};
public:
	Enemy( const Vector& pos, COLOR color );
	virtual ~Enemy( );
public:
	void update( );
	Vector getPos( ) const;
	Vector getDir( ) const;
	AnimationPtr getAnimation( ) const;
	void setBad( );
	bool isExpired( ) const;
protected:
	virtual void actor( ) = 0;//çsìÆÇÃåàíË
	void setDir( const Vector& dir );
	Vector getPlayerPos( ) const;
	Vector getPlayerDir( ) const;
	bool canMove( Vector pos );
private:
	bool onMap( Vector pos );
	void badRun( );
	void move( );
	void stateUpdate( );
	void animator( );
private:
	Vector _pos;
	Vector _dir;
	Vector _before_dir;
	STATE _state;
	STATE _before_state;
	bool _is_bad;
	int _bad_timer = 0;
	bool _is_expired;

	PlayerPtr _player;
	FieldPtr _field;
	AnimationPtr _animation;
	EnemyAnimationFoctoryPtr _anim_factory;
};