#pragma once
#include "Task.h"
#include "Field.h"
#include "Stage.h"
#include <string>

PTR( MapEditor );
PTR( Stage );
PTR( TremsManager );
PTR( SelectObjectManager );

class MapEditor : public Task {
public:
	struct OBJECT {
		std::string name;
		int size_x;
		int size_y;
	};
public:
	static MapEditorPtr getTask( );
	static std::string getTag( ) { return "MAP_EDITOR"; }
public:
	MapEditor( );
	virtual ~MapEditor( );
public:
	void update( );
	int getMeshMap( int x, int y ) const;
	TremsManagerPtr getTremsManager( ) const;
	SelectObjectManagerPtr getSelectObjectManager( ) const;
private:
	void meshMapUpdate( );
	Stage::CLEAR_TREMS getClearTrems( ) const;
private:
	static const int MAP_SIZE_X = Field::MAP_CHIP_NUM_X;
	static const int MAP_SIZE_Y = Field::MAP_CHIP_NUM_Y;
	const int CHIP_SIZE = Field::CHIP_SIZE;
	
	OBJECT _select_object;
	OBJECT _object_list[ Stage::OBJECT_NAME_MAX ];
	int _mesh_map[ MAP_SIZE_Y ][ MAP_SIZE_X ];

	TremsManagerPtr _trems_manager;
	SelectObjectManagerPtr _select_manager;
};

