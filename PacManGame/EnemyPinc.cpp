#include "EnemyPinc.h"
#include "MapDefine.h"
#include "Field.h"

EnemyPinc::EnemyPinc( const Vector& pos ) :
Enemy( pos, Enemy::COLOR_PINC ){
}


EnemyPinc::~EnemyPinc( ) {
}

void EnemyPinc::actor( ) {
	FieldPtr field = getField( );
	Vector target = getPlayerPos( );
	while ( field->getFieldTarget( target.x / MapParameter::CHIP_SIZE, target.y / MapParameter::CHIP_SIZE ) != Field::OBJECT_WALL ) {
		target += getPlayerDir( ) * MapParameter::CHIP_SIZE;
	}
	target -= getPlayerDir( ) * MapParameter::CHIP_SIZE;;
	const Vector DIR[ 4 ] = {
		Vector( -1,  0 ), 
		Vector(  1,  0 ),
		Vector(  0, -1 ),
		Vector(  0,  1 )
	};
	int min_root = 10000;
	int key = -1;
	for ( int i = 0; i < 4; i++ ) {
		Vector next_pos = getPos( ) + DIR[ i ] * MapParameter::CHIP_SIZE;
		int root_num = field->getRootNum( target.x / MapParameter::CHIP_SIZE, target.y / MapParameter::CHIP_SIZE, next_pos.x / MapParameter::CHIP_SIZE, next_pos.y  / MapParameter::CHIP_SIZE );
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