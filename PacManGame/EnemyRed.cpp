#include "EnemyRed.h"
 
EnemyRed::EnemyRed( const Vector& pos ) :
Enemy( pos, Enemy::COLOR_RED ) {
}

EnemyRed::~EnemyRed( ) {
}

void EnemyRed::actor( ) {
	changeDir( );
}

void EnemyRed::changeDir( ) {
	Vector move_dir = getPlayerPos( ) - getPos( );
	if ( move_dir.x > move_dir.y ) {
		move_dir = Vector( move_dir.x, 0, 0 );
	} else {
		move_dir = Vector( 0, move_dir.y, 0 );
	}
	setDir( move_dir.normalize( ) );
}