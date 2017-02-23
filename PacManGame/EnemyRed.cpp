#include "EnemyRed.h"
#include "MapDefine.h"
#include "Field.h"
 
EnemyRed::EnemyRed( const Vector& pos ) :
Enemy( pos, Enemy::COLOR_RED ) {
}

EnemyRed::~EnemyRed( ) {
}

void EnemyRed::actor( ) {
	FieldPtr field = getField( );
	Vector target = getPlayerPos( );
	const Vector DIR[ 4 ] = {
		Vector( -1,  0 ), 
		Vector(  1,  0 ),
		Vector(  0, -1 ),
		Vector(  0,  1 )
	};
	int min_root = 100000;
	int key = -1;
	for ( int i = 0; i < 4; i++ ) {
		Vector next_pos = getPos( ) + DIR[ i ] * MapParameter::CHIP_SIZE;
		int root_num = field->getRootNum( ( int )( target.x / MapParameter::CHIP_SIZE ), ( int )( target.y / MapParameter::CHIP_SIZE ), ( int )( next_pos.x / MapParameter::CHIP_SIZE ), ( int )( next_pos.y  / MapParameter::CHIP_SIZE ) );
		if ( min_root > root_num && root_num >= 0 ) {
			key = i;
			min_root = root_num;
		}
	}
	if ( key >= 0 ) {
		Vector move_dir = DIR[ key ];
		setDir( move_dir.normalize( ) );
	}
}