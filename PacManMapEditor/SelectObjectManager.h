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
private:
	Stage::OBJECT_NAME _select_object;
	static const int BUTTON_NUM = Stage::OBJECT_NAME_MAX - 1;
	ButtonPtr _button[ BUTTON_NUM ];
};