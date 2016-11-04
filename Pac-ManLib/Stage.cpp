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
