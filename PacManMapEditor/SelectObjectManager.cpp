#include "SelectObjectManager.h"
#include "Button.h"

const int BUTTON_WIDTH = 32;
const int BUTTON_HEIGHT = 32;

const int INDEX_POS_X = 980;
const int INDEX_POS_Y = 200;

const int MARGIN_BUTTON = 64;

const int BUTTON_POS_X[ Stage::OBJECT_NAME_MAX ] = {
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 0
};

const int BUTTON_POS_Y[ Stage::OBJECT_NAME_MAX ] = {
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 0,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 1,
	MARGIN_BUTTON * 2,
	MARGIN_BUTTON * 2,
	MARGIN_BUTTON * 3,
	MARGIN_BUTTON * 3,
	MARGIN_BUTTON * 4
};

SelectObjectManager::SelectObjectManager( ) {
	_select_object = Stage::OBJECT_NAME_NONE;
	for ( int i = 0; i < BUTTON_NUM; i++ ) {
		int x = INDEX_POS_X + BUTTON_POS_X[ i ];
		int y = INDEX_POS_Y + BUTTON_POS_Y[ i ];
		int width = BUTTON_WIDTH;
		int height = BUTTON_HEIGHT;
		if ( i == BUTTON_NUM - 1 ) {
			width *= 2;
			height *= 2;
		}
		_button[ i ] = ButtonPtr( new Button( x, y, width, height ) );
	}
	_button[ 0 ]->setFillFlag( true );
}

SelectObjectManager::~SelectObjectManager( ) {

}

void SelectObjectManager::update( ) {
	for ( int i = 0; i < BUTTON_NUM; i++ ) {
		if ( _button[ i ]->onClick( ) ) {
			_button[ _select_object ]->setFillFlag( false );
			_select_object = ( Stage::OBJECT_NAME )i;
			_button[ _select_object ]->setFillFlag( true );
		}
	}
}

int SelectObjectManager::getButtonNum( ) {
	return BUTTON_NUM;
}

ButtonPtr SelectObjectManager::getButton( int id ) {
	return _button[ id ];
}