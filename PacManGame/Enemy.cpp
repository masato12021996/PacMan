#include "Enemy.h"
#include "Animation.h"

const double SPEED = 1.0;

Enemy::Enemy( const Vector& pos  ) {
	_pos = pos;
	_dir = Vector( 1, 0, 0 );
	_is_expired = true;
	_is_bad = false;
	_animation;
}

Enemy::~Enemy( ) {
}

void Enemy::update( ) {
	if ( _is_bad ) {
		//“¦‚°‚é

	} else {
		actor( );
	}
	move( );
	_animation->update( );
}

Vector Enemy::getPos( ) const {
	return _pos;
}

Vector Enemy::getDir( ) const {
	return _dir;
}

void Enemy::setDir( const Vector& dir ) {
	_dir = dir;
}

AnimationPtr Enemy::getAnimation( ) const {
	return _animation;
}

void Enemy::setAnimation( AnimationPtr animation ) {
	_animation = animation;
}

bool Enemy::isExpired( ) const {
	return _is_expired;
}

void Enemy::move( ) {
	double speed = SPEED;
	if ( _is_bad ) {
		speed = speed / 2;
	}
	_pos += _dir * speed;
}