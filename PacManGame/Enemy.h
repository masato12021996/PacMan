#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Enemy );
PTR( Player )
PTR( Field );
PTR( Animation );

class Enemy {
public:
	Enemy( const Vector& pos );
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
	void setAnimation( AnimationPtr animation );
	Vector getPlayerPos( ) const;
	Vector getPlayerDir( ) const;
	bool canMove( Vector pos );
private:
	bool onMap( Vector pos );
	void badRun( );
	void move( );
private:
	int _bad_timer = 0;
	bool _is_expired;
	bool _is_bad;
	bool _before_bad;
	Vector _pos;
	Vector _dir;
	PlayerPtr _player;
	AnimationPtr _animation;
	FieldPtr _field;
};