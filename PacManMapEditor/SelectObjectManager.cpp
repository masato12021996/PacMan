#include "SelectObjectManager.h"
#include "Button.h"

const int BUTTON_WIDTH = 32;
const int BUTTON_HEIGHT = 32;

const int INDEX_POS_X = 1150 - BUTTON_WIDTH - 20;
const int INDEX_POS_Y = 200;
const int DIFF_POS_Y = 30;

const int BUTTON_POS_X[ Stage::CLEAR_TREMS_MAX ] = {

};

const int BUTTON_POS_Y[ Stage::CLEAR_TREMS_MAX ] = {
};

SelectObjectManager::SelectObjectManager( ) {
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