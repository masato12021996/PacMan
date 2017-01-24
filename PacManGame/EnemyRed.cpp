#include "EnemyRed.h"
#include "EnemyAnimationFoctory.h"
 
EnemyRed::EnemyRed( const Vector& pos ) :
Enemy( pos ) {
	_anim_factory = EnemyAnimationFoctoryPtr( new EnemyAnimationFoctory( EnemyAnimationFoctory::ENEMY_COLOR_RED ) );
	setAnimation( _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_WALK_LEFT ) );
}

EnemyRed::~EnemyRed( ) {
}

void EnemyRed::actor( ) {
	changeDir( );
	changeAnimation( );
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

void EnemyRed::changeAnimation( ) {
}