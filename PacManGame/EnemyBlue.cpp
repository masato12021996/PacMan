#include "EnemyBlue.h"
#include "MapDefine.h"
#include "Field.h"

EnemyBlue::EnemyBlue( const Vector& pos ) :
Enemy( pos, COLOR_BLUE ){
}


EnemyBlue::~EnemyBlue() {
}

void EnemyBlue::actor( ) {
	FieldPtr field = getField( );
	Vector mp = Vector( getPos( ).x / MapParameter::CHIP_SIZE, getPos( ).y / MapParameter::CHIP_SIZE );
	Vector next_pos = mp + getDir( ).normalize( );
	const Vector DIR[ 4 ] = {
		Vector( -1,  0 ), 
		Vector(  0, -1 ),
		Vector(  1,  0 ),
		Vector(  0,  1 )
	};
	if ( field->getFieldTarget( ( int )next_pos.x, ( int )next_pos.y ) == Field::OBJECT_WALL ) {
		int key = 0;
		for ( int i = 0; i < 4; i++ ) {
			if ( DIR[ i ] == getDir( ).normalize( ) ) {
				key = i;
				break;
			}
		}
		for ( int i = 0; i < 3; i++ ) {
			next_pos = mp + DIR[ ( key + i ) % 4 ];
			if ( field->getFieldTarget( ( int )next_pos.x, ( int )next_pos.y ) != Field::OBJECT_WALL ) {
				setDir( DIR[ ( key + i ) % 4 ] );
				break;
			}
		}
	}
}
