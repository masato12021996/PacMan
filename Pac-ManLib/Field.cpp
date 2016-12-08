#include "Field.h"
#include "MapDefine.h"

Field::Field( ) {
	initialize( );
}

Field::~Field( ) {
}

void Field::initialize( ) {
	for ( int i = 0; i < MAP_MAX_INDEX; i++ ) {
		_field[ i ] = OBJECT_NULL;
	}
}

//フィールドの情報設定
void Field::setFieldTarget( int x, int y, OBJECT value ) {
	int index = getIndex( x, y );
	_field[ index ] = value;
}

//フィールドの情報取得
Field::OBJECT Field::getFieldTarget( int x, int y ) const {
	int index = getIndex( x, y );
	Field::OBJECT object = _field[ index ];
	return object;
}

int Field::getIndex( int x, int y ) const {
	return y * MAP_CHIP_NUM_X + x;
}

int Field::getSizeX( ) const {
	return MAP_CHIP_NUM_X;
}

int Field::getSizeY( ) const {
	return MAP_CHIP_NUM_Y;
}