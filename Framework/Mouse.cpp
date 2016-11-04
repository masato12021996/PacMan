#include "Mouse.h"
#include "DxLib.h"

Mouse::Mouse( ) {
}

Mouse::~Mouse( ) {
}

Vector Mouse::getPoint( ) const {
	int x = 0;
	int y = 0;
	GetMousePoint( &x, &y );
	return Vector( x, y );
}

bool Mouse::isInputButton( INPUT input ) const {
	int button = GetMouseInput( );
	bool result = false;
	switch ( input ) {
		case INPUT_LEFT:
			if ( button & MOUSE_INPUT_LEFT ) {
				result = true;
			}
			break;
		case INPUT_RIGHT:
			if ( button & MOUSE_INPUT_RIGHT ) {
				result = true;
			}
			break;
	}
	return result;
}