#include "EnemyOrange.h"
#include "Field.h"
#include "MapDefine.h"

EnemyOrange::EnemyOrange( const Vector& pos ) :
Enemy( pos, Enemy::COLOR_ORANGE ) {
}


EnemyOrange::~EnemyOrange( ) {
}


void EnemyOrange::actor( ) {
	FieldPtr field = getField( );
	const Vector DIR[ 4 ] = {
		Vector( -1,  0 ), 
		Vector(  1,  0 ),
		Vector(  0, -1 ),
		Vector(  0,  1 )
	};
	int min_root = 100000;
	int key = -1;
	int dir_list[ 4 ] ={ 0 };
	for ( int i = 0; i < 4; i++ ) {
		int ranvalue = rand( ) % 4;
		while ( dir_list[ ranvalue ] != 0 ) {
			ranvalue = rand( ) % 4;
		}
		Vector target = getPos( ) + DIR[ ranvalue ] * MapParameter::CHIP_SIZE;
		if ( field->getFieldTarget( target.x / MapParameter::CHIP_SIZE, target.y / MapParameter::CHIP_SIZE ) != Field::OBJECT_WALL ) {
			key = ranvalue;
		}
	}
	if ( key >= 0 ) {
		Vector move_dir = DIR[ key ];
		setDir( move_dir.normalize( ) );
	}
}