#pragma once

#include "task.h"
#include <string>
#include <map>

PTR( Keyboard );

class Keyboard : public Task {
public:
	static std::string getTag( ) { return "KEYBOARD"; }
	static KeyboardPtr getTask( );
public:
	Keyboard( );
	virtual ~Keyboard( );
public:
	virtual void update( );
public:
	bool isPushKey( std::string key );
	bool isHoldKey( std::string key );
	char getInputChar( );
private:
	struct KEYS {
		char buffer[ 256 ];
	};
private:
	KEYS _now_keys;
	KEYS _before_keys;
	std::map< std::string, int > _convert;
};
