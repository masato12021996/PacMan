#include "EnemyOrange.h"
#include "Field.h"
#include "MapDefine.h"

EnemyOrange::EnemyOrange( const Vector& pos ) :
Enemy( pos, Enemy::COLOR_ORANGE ) {
	_counter = 0;
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
	int key = -1;
	Vector mp = Vector( getPos( ).x / MapParameter::CHIP_SIZE, getPos( ).y / MapParameter::CHIP_SIZE );
	if ( _counter < 10 ) {
		Vector target = getPlayerPos( );
		int min_root = 100000;
		for ( int i = 0; i < 4; i++ ) {
			Vector next_pos = mp + DIR[ i ];
			int root_num = field->getRootNum( ( int )( target.x / MapParameter::CHIP_SIZE ), ( int )( target.y / MapParameter::CHIP_SIZE ), ( int )next_pos.x, ( int )next_pos.y );
			if ( min_root > root_num && root_num >= 0 ) {
				key = i;
				min_root = root_num;
			}
		}
	} else {
		int dir_list[ 4 ] ={ 0 };
		for ( int i = 0; i < 4; i++ ) {
			int ranvalue = rand( ) % 4;
			while ( dir_list[ ranvalue ] != 0 ) {
				ranvalue = rand( ) % 4;
			}
			Vector target = mp + DIR[ ranvalue ];
			if ( field->getFieldTarget( ( int )target.x, ( int )target.y ) != Field::OBJECT_WALL ) {
				key = ranvalue;
			}
			dir_list[ ranvalue ] = 1;
		}
	}
	if ( key >= 0 ) {
		Vector move_dir = DIR[ key ];
		setDir( move_dir.normalize( ) );
	}
	if ( _counter > 20 ) {
		_counter = 0;
	}
	_counter++;
}