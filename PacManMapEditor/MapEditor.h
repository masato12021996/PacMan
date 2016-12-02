#pragma once
#include "Task.h"
#include "MapDefine.h"
#include "Stage.h"
#include <string>

PTR( MapEditor );
PTR( Stage );
PTR( TremsManager );
PTR( SelectObjectManager );
PTR( Button );

class MapEditor : public Task {
public:
	static MapEditorPtr getTask( );
	static std::string getTag( ) { return "MAP_EDITOR"; }
public:
	MapEditor( );
	virtual ~MapEditor( );
public:
	void update( );
	int getMeshMap( int x, int y ) const;
	int getObjectMap( int x, int y ) const;
	TremsManagerPtr getTremsManager( ) const;
	SelectObjectManagerPtr getSelectObjectManager( ) const;
	ButtonPtr getSaveButton( ) const;
	ButtonPtr getLoadButton( ) const;
private:
	void meshMapUpdate( );
	void putObjectUpdate( );
	Stage::CLEAR_TREMS getClearTrems( ) const;
	void save( );
	void load( );
private:
	static const int MAP_SIZE_X = MapParameter::MAP_SIZE_X;
	static const int MAP_SIZE_Y = MapParameter::MAP_SIZE_Y;
	const int CHIP_SIZE = 32;
	
	Stage::OBJECT_NAME _select_object;
	int _mesh_map[ MAP_SIZE_Y ][ MAP_SIZE_X ];
	int _object_map[ MAP_SIZE_Y ][ MAP_SIZE_X ];

	TremsManagerPtr _trems_manager;
	SelectObjectManagerPtr _select_manager;
	ButtonPtr _save_button;
	ButtonPtr _load_button;
};

