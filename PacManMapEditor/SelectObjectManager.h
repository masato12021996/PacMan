#pragma once
#include "smart_ptr.h"
#include "Stage.h"

PTR( SelectObjectManager );
PTR( Button );

class SelectObjectManager {
public:
	SelectObjectManager( );
	virtual ~SelectObjectManager( );
public:
	void update( );
	Stage::OBJECT_NAME getSelectObject( ) const;
	int getButtonNum( );
	ButtonPtr getButton( int id );
public:
	static const int BUTTON_NUM = 8;
private:
	Stage::OBJECT_NAME _select_object;
	int _select_index;
	ButtonPtr _button[ BUTTON_NUM ];
};