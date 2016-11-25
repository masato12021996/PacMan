#pragma once
#include "smart_ptr.h"
#include <string>

PTR( MessageBoxMaker );

class MessageBoxMaker {
public:
	MessageBoxMaker( );
	virtual ~MessageBoxMaker( );
public:
	void create( std::string title, std::string message );
	std::string keyInput( int x, int y );
};