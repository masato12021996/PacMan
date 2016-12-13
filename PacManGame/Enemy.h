#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Enemy );
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
	bool isExpired( ) const;
protected:
	virtual void actor( ) = 0;//çsìÆÇÃåàíË
	void setDir( const Vector& dir );
	void setAnimation( AnimationPtr animation );
private:
	void move( );
private:
	bool _is_expired;
	bool _is_bad;
	Vector _pos;
	Vector _dir;
	AnimationPtr _animation;
};