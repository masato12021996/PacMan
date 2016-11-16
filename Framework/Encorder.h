#pragma once
#include "smart_ptr.h"
#include <string>

PTR( Encorder );

class Encorder {
public:
	Encorder( );
	virtual ~Encorder( );
public:
	void encode( std::string filename );
};