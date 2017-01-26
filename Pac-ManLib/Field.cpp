#include "Field.h"
#include "MapDefine.h"
#include <queue>

typedef std::pair< int, int > VECTOR_INT;
typedef std::pair< VECTOR_INT, int > ROOT_KEY;

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

bool Field::isNotBate( ) const {
	bool result = true;
	for( int i = 0; i < MAP_MAX_INDEX; i++ ) {
		int obj = _field[ i ];
		if ( obj == OBJECT_BATE || obj == OBJECT_POWER_BATE ) {
			result = false;
			break;
		}
	}
	return result;
}

int Field::getRootNum( const int target_x, const int target_y, const int start_x, const int start_y ) {
	int result = -1;

	const VECTOR_INT DIR[ 4 ] = {
		std::make_pair( -1,  0 ),//LEFT
		std::make_pair(  1,  0 ),//RIGHT
		std::make_pair(  0, -1 ),//UP
		std::make_pair(  0,  1 ) //DOWN
	};
	int visited_map[ MAP_MAX_INDEX ];
	for ( int i = 0;i < MAP_MAX_INDEX; i++ ) {
		visited_map[ i ] = 0;
	}
	std::queue< ROOT_KEY > queue;
	ROOT_KEY key = std::make_pair( std::make_pair( start_x, start_y ), 0 );
	visited_map[ getIndex( start_x, start_y ) ] = 1;
	queue.push( key );

	while ( !queue.empty( ) ) {
		ROOT_KEY temp = queue.front( );
		queue.pop( );
		VECTOR_INT pos = temp.first;
		if ( target_x == pos.first && target_y == pos.second  ) {
			result = temp.second;
			break;
		}
		for ( int i = 0; i < 4; i++ ) {
			VECTOR_INT next_pos = std::make_pair( pos.first + DIR[ i ].first, pos.second + DIR[ i ].second );
			if ( getFieldTarget( next_pos.first, next_pos.second ) != OBJECT_WALL && visited_map[ getIndex( next_pos.first, next_pos.second ) ] == 0 ) {
				ROOT_KEY next_key = std::make_pair( next_pos, temp.second + 1 );
				visited_map[ getIndex( next_pos.first, next_pos.second ) ] = 1;
				queue.push( next_key );
			}
		}
	}
	return result;
}