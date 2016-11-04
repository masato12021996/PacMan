#pragma once
#include "smart_ptr.h"
#include "Stage.h"
#include <string>

PTR( TremsManager );
PTR( Button );

class TremsManager {
public:
	TremsManager( );
	virtual ~TremsManager( );
public:
	void update( );
	Stage::CLEAR_TREMS getClearTrems( ) const;
	int getButtonNum( ) const;
	ButtonPtr getButton( int id ) const;
	std::string getButtonName( int id ) const;
private:
	Stage::CLEAR_TREMS _select_trems;
	static const int BUTTON_NUM = Stage::CLEAR_TREMS_MAX;
	ButtonPtr _button[ BUTTON_NUM ];
	std::string _button_name[ BUTTON_NUM ];
};