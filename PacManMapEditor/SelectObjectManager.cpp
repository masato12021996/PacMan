#include "SelectObjectManager.h"
#include "Button.h"

const int BUTTON_WIDTH = 33;
const int BUTTON_HEIGHT = 33;

const int INDEX_POS_X = 980;
const int INDEX_POS_Y = 100;

const int MARGIN_BUTTON = 35;

const int BUTTON_POS_X[ SelectObjectManager::BUTTON_NUM ] = {
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1
};

const int BUTTON_POS_Y[ SelectObjectManager::BUTTON_NUM ] = {
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 2,
	MARGIN_BUTTON * 2,
	MARGIN_BUTTON * 3,
	MARGIN_BUTTON * 3,
	MARGIN_BUTTON * 4,
	MARGIN_BUTTON * 4
};

const Stage::OBJECT_NAME BUTTON_LIST[ SelectObjectManager::BUTTON_NUM ] = {
	Stage::OBJECT_NAME_PLAYER,
	Stage::OBJECT_NAME_ENEMY_RED,
	Stage::OBJECT_NAME_ENEMY_PINC,
	Stage::OBJECT_NAME_ENEMY_BLUE,
	Stage::OBJECT_NAME_ENEMY_ORANGE,
	Stage::OBJECT_NAME_BATE,
	Stage::OBJECT_NAME_POWER_BATE,
	Stage::OBJECT_NAME_WALL,
	Stage::OBJECT_NAME_NONE
};

SelectObjectManager::SelectObjectManager( ) {
	_select_object = Stage::OBJECT_NAME_PLAYER;
	_select_index = 0;
	for ( int i = 0; i < BUTTON_NUM; i++ ) {
		int x = INDEX_POS_X + BUTTON_POS_X[ i ];
		int y = INDEX_POS_Y + BUTTON_POS_Y[ i ];
		int width = BUTTON_WIDTH;
		int height = BUTTON_HEIGHT;
		_button[ i ] = ButtonPtr( new Button( x, y, width, height ) );
	}
	_button[ 0 ]->setFillFlag( true );
}

SelectObjectManager::~SelectObjectManager( ) {

}

void SelectObjectManager::update( ) {
	for ( int i = 0; i < BUTTON_NUM; i++ ) {
		if ( _button[ i ]->onClick( ) ) {
			_button[ _select_index ]->setFillFlag( false );
			_select_index = i;
			_select_object = BUTTON_LIST[ i ];
			_button[ _select_index ]->setFillFlag( true );
		}
	}
}

int SelectObjectManager::getButtonNum( ) {
	return BUTTON_NUM;
}

ButtonPtr SelectObjectManager::getButton( int id ) {
	return _button[ id ];
}

Stage::OBJECT_NAME SelectObjectManager::getSelectObject( ) const {
	return _select_object;
}