#include "Keyboard.h"
#include "Application.h"
#include "DxLib.h"

KeyboardPtr Keyboard::getTask( ) {
	ApplicationPtr fw = Application::getInstance( );
	return std::dynamic_pointer_cast< Keyboard >( fw->getTask( Keyboard::getTag( ) ) );
}

Keyboard::Keyboard( ) {
	_convert[ "A" ] = KEY_INPUT_A;
	_convert[ "B" ] = KEY_INPUT_B;
	_convert[ "C" ] = KEY_INPUT_C;
	_convert[ "D" ] = KEY_INPUT_D;
	_convert[ "E" ] = KEY_INPUT_E;
	_convert[ "F" ] = KEY_INPUT_F;
	_convert[ "G" ] = KEY_INPUT_G;
	_convert[ "H" ] = KEY_INPUT_H;
	_convert[ "I" ] = KEY_INPUT_I;
	_convert[ "J" ] = KEY_INPUT_J;
	_convert[ "K" ] = KEY_INPUT_K;
	_convert[ "L" ] = KEY_INPUT_L;
	_convert[ "N" ] = KEY_INPUT_N;
	_convert[ "M" ] = KEY_INPUT_M;
	_convert[ "O" ] = KEY_INPUT_O;
	_convert[ "P" ] = KEY_INPUT_P;
	_convert[ "Q" ] = KEY_INPUT_Q;
	_convert[ "R" ] = KEY_INPUT_R;
	_convert[ "S" ] = KEY_INPUT_S;
	_convert[ "T" ] = KEY_INPUT_T;
	_convert[ "U" ] = KEY_INPUT_U;
	_convert[ "V" ] = KEY_INPUT_V;
	_convert[ "W" ] = KEY_INPUT_W;
	_convert[ "X" ] = KEY_INPUT_X;
	_convert[ "Y" ] = KEY_INPUT_Y;
	_convert[ "Z" ] = KEY_INPUT_Z;
	_convert[ "1" ] = KEY_INPUT_1;
	_convert[ "2" ] = KEY_INPUT_2;
	_convert[ "3" ] = KEY_INPUT_3;
	_convert[ "4" ] = KEY_INPUT_4;
	_convert[ "5" ] = KEY_INPUT_5;
	_convert[ "6" ] = KEY_INPUT_6;
	_convert[ "7" ] = KEY_INPUT_7;
	_convert[ "8" ] = KEY_INPUT_8;
	_convert[ "9" ] = KEY_INPUT_9;
	_convert[ "0" ] = KEY_INPUT_0;
	_convert[ "NUM1" ] = KEY_INPUT_NUMPAD1;
	_convert[ "NUM2" ] = KEY_INPUT_NUMPAD2;
	_convert[ "NUM3" ] = KEY_INPUT_NUMPAD3;
	_convert[ "NUM4" ] = KEY_INPUT_NUMPAD4;
	_convert[ "NUM5" ] = KEY_INPUT_NUMPAD5;
	_convert[ "NUM6" ] = KEY_INPUT_NUMPAD6;
	_convert[ "NUM7" ] = KEY_INPUT_NUMPAD7;
	_convert[ "NUM8" ] = KEY_INPUT_NUMPAD8;
	_convert[ "NUM9" ] = KEY_INPUT_NUMPAD9;
	_convert[ "NUM0" ] = KEY_INPUT_NUMPAD0;
	_convert[ "ARROW_LEFT"  ] = KEY_INPUT_LEFT;
	_convert[ "ARROW_RIGHT" ] = KEY_INPUT_RIGHT;
	_convert[ "ARROW_UP"    ] = KEY_INPUT_UP;
	_convert[ "ARROW_DOWN"  ] = KEY_INPUT_DOWN;
	_convert[ "F1" ]  = KEY_INPUT_F1;
	_convert[ "F2" ]  = KEY_INPUT_F2;
	_convert[ "F3" ]  = KEY_INPUT_F3;
	_convert[ "F4" ]  = KEY_INPUT_F4;
	_convert[ "F5" ]  = KEY_INPUT_F5;
	_convert[ "F6" ]  = KEY_INPUT_F6;
	_convert[ "F7" ]  = KEY_INPUT_F7;
	_convert[ "F8" ]  = KEY_INPUT_F8;
	_convert[ "F9" ]  = KEY_INPUT_F9;
	_convert[ "F10" ] = KEY_INPUT_F10;
	_convert[ "F11" ] = KEY_INPUT_F11;
	_convert[ "F12" ] = KEY_INPUT_F12;
	_convert[ "+" ] = KEY_INPUT_ADD;
	_convert[ "-" ] = KEY_INPUT_SUBTRACT;
	_convert[ "ENTER" ] = KEY_INPUT_RETURN;
	_convert[ "ESC" ] = KEY_INPUT_ESCAPE;
	_convert[ "BACK_SPACE" ] = KEY_INPUT_BACK;
	_convert[ "SPACE" ] = KEY_INPUT_SPACE;
}

Keyboard::~Keyboard( ) {
}

void Keyboard::update( ) {
	_before_keys = _now_keys;
	if ( _before_keys.buffer[ 28 ] == 1 ) {
		int x = 0;
	}
	GetHitKeyStateAll( _now_keys.buffer );
}

bool Keyboard::isHoldKey( std::string key ) {
	int dxkey = _convert[ key ];
	return _now_keys.buffer[ dxkey ] == 1;
}

bool Keyboard::isPushKey( std::string key ) {
	int dxkey = _convert[ key ];
	return ( _now_keys.buffer[ dxkey ] == 1 ) && ( _before_keys.buffer[ dxkey ] == 0 );
}

char Keyboard::getInputChar( ) {
	return GetInputChar( TRUE );
}
