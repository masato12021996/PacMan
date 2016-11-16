#pragma once
#include "Task.h"
#include "smart_ptr.h"
#include "mathmatics.h"
#include <string>

PTR( Mouse );

class Mouse : public Task {
public:
	static MousePtr getTask( );
	static std::string getTag( ) { return "MOUSE"; }
public:
	enum INPUT {
		INPUT_ON_LEFT,
		INPUT_ON_RIGHT,
		INPUT_HOLD_LEFT,
		INPUT_HOLD_RIGHT
	};
public:
	Mouse( );
	virtual ~Mouse( );
public:
	void update( );
	Vector getPoint( ) const;
	bool isInputButton( INPUT input ) const;
private:
	int _button_log;
	int _button;
};

