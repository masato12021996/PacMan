#include "Button.h"
#include "Mouse.h"

Button::Button( int pos_x, int pos_y, int width, int height ):
POS_X( pos_x ),
POS_Y( pos_y ),
WIDTH( width ),
HEIGHT( height ) {
	_fill_flag = false;
}

Button::~Button() {
}

bool Button::onClick( ) {
	bool result = false;
	Mouse mouse;
	int mx = ( int )mouse.getPoint( ).x;
	int my = ( int )mouse.getPoint( ).y;
	bool on_mouse = POS_X < mx && mx < POS_X + WIDTH && POS_Y < my && my < POS_Y + HEIGHT;
	bool is_click = mouse.isInputButton( Mouse::INPUT_LEFT );
	if ( on_mouse && is_click ) {
		result = true;
	}
	return result;
}

int Button::getButtonPosX( ) const {
	return POS_X;
}

int Button::getButtonPosY( ) const {
	return POS_Y;
}

int Button::getButtonWidth( ) const {
	return WIDTH;
}

int Button::getButtonHeight( ) const {
	return HEIGHT;
}

bool Button::getFillFlag( ) const {
	return _fill_flag;
}

void Button::setFillFlag( bool fill_flag ) {
	_fill_flag = fill_flag;
}