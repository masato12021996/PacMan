#include "TremsManager.h"
#include "Button.h"

const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 30;

const int INDEX_POS_X = 1110 - BUTTON_WIDTH;
const int INDEX_POS_Y = 0;
const int DIFF_POS_Y = 30;

TremsManager::TremsManager( ) {
	_select_trems = Stage::CLEAR_TREMS_FOOD_EAT;
	for ( int i = 0; i < BUTTON_NUM; i++ ) {
		_button[ i ] = ButtonPtr( new Button( INDEX_POS_X, INDEX_POS_Y + i * DIFF_POS_Y, BUTTON_WIDTH, BUTTON_HEIGHT ) );
	}
	_button[ 0 ]->setFillFlag( true );
	_button_name[ 0 ] = "FOOD_EAT";
	_button_name[ 1 ] = "ENEMY_EAT";
	_button_name[ 2 ] = "OUTRUN";
}

TremsManager::~TremsManager( ) {
}

void TremsManager::update( ) {
	for ( int i = 0; i < BUTTON_NUM; i++ ) {
		if ( _button[ i ]->onClick( ) ) {
			_button[ _select_trems ]->setFillFlag( false );
			_select_trems = (Stage::CLEAR_TREMS)i;
			_button[ _select_trems ]->setFillFlag( true );
		}
	}
}

Stage::CLEAR_TREMS TremsManager::getClearTrems( ) const {
	return _select_trems;
}

int TremsManager::getButtonNum( ) const{
	return BUTTON_NUM;
}

ButtonPtr TremsManager::getButton( int id ) const{
	return _button[ id ];
}

std::string TremsManager::getButtonName( int id ) const{
	return _button_name[ id ];
}

void TremsManager::setClearTrems( Stage::CLEAR_TREMS trems ) {
	_button[ _select_trems ]->setFillFlag( false );
	_select_trems = trems;
	_button[ _select_trems ]->setFillFlag( true );
}