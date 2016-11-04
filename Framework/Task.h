#pragma once
#include "smart_ptr.h"

PTR( Task );

class Task {
public:
	Task( );
	virtual ~Task( );
public:
	virtual void update( ) = 0; 
	virtual void initialize( ) { }
	virtual void finalize( ) { }
};

