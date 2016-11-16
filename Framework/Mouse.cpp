#include "Mouse.h"
#include "Application.h"
#include "DxLib.h"

MousePtr Mouse::getTask( ) {
	ApplicationPtr app = Application::getInstance( );
	return std::dynamic_pointer_cast< Mouse >( app->getTask( getTag( ) ) );
}

Mouse::Mouse( ) {
	_button_log = 0;
	_button = 0;
}

Mouse::~Mouse( ) {
}

void Mouse::update( ) {
	_button_log = _button;
	_button = GetMouseInput( );
}

Vector Mouse::getPoint( ) const {
	int x = 0;
	int y = 0;
	GetMousePoint( &x, &y );
	return Vector( x, y );
}

bool Mouse::isInputButton( INPUT input ) const {
	bool result = false;
	switch ( input ) {
		case INPUT_ON_LEFT:
			if ( _button & MOUSE_INPUT_LEFT && !( _button_log & MOUSE_INPUT_LEFT ) ) {
				result = true;
			}
			break;
		case INPUT_ON_RIGHT:
			if ( _button & MOUSE_INPUT_RIGHT && !( _button_log & MOUSE_INPUT_RIGHT ) ) {
				result = true;
			}
			break;
		case INPUT_HOLD_LEFT:
			if ( _button & MOUSE_INPUT_LEFT ) {
				result = true;
			}
			break;
		case INPUT_HOLD_RIGHT:
			if ( _button & MOUSE_INPUT_RIGHT ) {
				result = true;
			}
			break;
	}
	return result;
}