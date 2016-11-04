#include "Field.h"
#include "Object.h"

Field::Field( ) {
}

Field::~Field( ) {
}

void Field::initialize( ) {
	for ( int i = 0; i < MAP_MAX_INDEX; i++ ) {
		_field[ i ] = ObjectPtr( new Object( Object::TAG_WALL ) );
	}
}

//�t�B�[���h�̏��ݒ�
void Field::setFieldTarget( const Vector& pos, ObjectPtr value ) {
	int index = getIndex( pos );
	_field[ index ] = value;
}

//�t�B�[���h�̏��擾
ObjectPtr Field::getFieldTarget( const Vector& pos ) const {
	int index = getIndex( pos );
	return _field[ index ];
}

int Field::getIndex( const Vector& pos ) const {
	int x = ( int )pos.x;
	int y = ( int )pos.y;
	return ( y / CHIP_SIZE_Y ) * MAP_CHIP_NUM_X + ( x / CHIP_SIZE_X );
}

int Field::getSizeX( ) const {
	return MAP_CHIP_NUM_X;
}

int Field::getSizeY( ) const {
	return MAP_CHIP_NUM_Y;
}