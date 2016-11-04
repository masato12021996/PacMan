#pragma once
#include "smart_ptr.h"

PTR( Button );

class Button {
public:
	Button( int pos_x, int pos_y, int width, int height );
	virtual ~Button( );
public:
	bool onClick( );
	int getButtonPosX( ) const;
	int getButtonPosY( ) const;
	int getButtonWidth( ) const;
	int getButtonHeight( ) const;
	bool getFillFlag( ) const;
	void setFillFlag( bool fill_flag );
private:
	const int POS_X;
	const int POS_Y;
	const int WIDTH;
	const int HEIGHT;
	bool _fill_flag;
};