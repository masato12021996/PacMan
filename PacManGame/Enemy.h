#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Enemy );
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
private:
	bool onMap( Vector pos );
	bool canMove( Vector pos );
	void badRun( );
	void move( );
private:
	int _bad_timer = 0;
	bool _is_expired;
	bool _is_bad;
	bool _before_bad;
	Vector _pos;
	Vector _dir;
	AnimationPtr _animation;
	FieldPtr _field;
};