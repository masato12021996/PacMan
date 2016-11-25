#include "Stage.h"

Stage::Stage( ) {
	_trems = CLEAR_TREMS_FOOD_EAT;
	for ( int i = 0; i < MAP_SIZE_Y; i++ ) {
		for ( int j = 0; j < MAP_SIZE_X; j++) {
			_map[ i ][ j ] = OBJECT_NAME_NONE;
		}
	}
}

Stage::~Stage( ) {
}

void Stage::setTrems( CLEAR_TREMS trems ) {
	_trems = trems;
}

void Stage::setTargetCell( int x, int y, OBJECT_NAME object ) {
	_map[ y ][ x ] = object;
}

Stage::CLEAR_TREMS Stage::getTrems( ) const {
	return _trems;
}

int Stage::getTargetCell( int x, int y ) const {
	return _map[ y ][ x ];
}