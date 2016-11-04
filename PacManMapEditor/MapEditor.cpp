#include "MapEditor.h"
#include "Application.h"
#include "Stage.h"
#include "Mouse.h"
#include "TremsManager.h"
#include "SelectObjectManager.h"

MapEditorPtr MapEditor::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast< MapEditor >( application->getTask( getTag( ) ) );
}

MapEditor::MapEditor( ) {
	_trems_manager = TremsManagerPtr( new TremsManager );
	_select_manager = SelectObjectManagerPtr( new SelectObjectManager );
	for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
		for ( int j = 0; j < MAP_SIZE_X; j++ ) {
			_mesh_map[ i ][ j ] = 0;
			_object_map[ i ][ j ] = 0;
		}
	}
	_object_list[ Stage::OBJECT_NAME_NONE ]		= { Stage::OBJECT_NAME_NONE, 1, 1 };
	_object_list[ Stage::OBJECT_NAME_WALL ]		= { Stage::OBJECT_NAME_WALL, 2, 2 };
	_object_list[ Stage::OBJECT_NAME_PLAYER ]	= { Stage::OBJECT_NAME_PLAYER, 1, 1 };
	_object_list[ Stage::OBJECT_NAME_ENEMY_BLUE ]		= { Stage::OBJECT_NAME_ENEMY_BLUE, 1, 1 };
	_object_list[ Stage::OBJECT_NAME_ENEMY_RED ]		= { Stage::OBJECT_NAME_ENEMY_RED, 1, 1 };
	_object_list[ Stage::OBJECT_NAME_ENEMY_ORANGE ]		= { Stage::OBJECT_NAME_ENEMY_ORANGE, 1, 1 };
	_object_list[ Stage::OBJECT_NAME_ENEMY_PINC ]		= { Stage::OBJECT_NAME_ENEMY_PINC, 1, 1 };
	_object_list[ Stage::OBJECT_NAME_BATE ]		= { Stage::OBJECT_NAME_BATE, 1, 1 };
	_object_list[ Stage::OBJECT_NAME_POWER_BATE ]		= { Stage::OBJECT_NAME_POWER_BATE, 1, 1 };
	_select_object = _object_list[ Stage::OBJECT_NAME_NONE ];
}

MapEditor::~MapEditor( ) {
}

void MapEditor::update( ) {
	_trems_manager->update( );
	_select_manager->update( );
	meshMapUpdate( );
	putObjectUpdate( );
}

void MapEditor::meshMapUpdate( ) {
	for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
		for ( int j = 0; j < MAP_SIZE_X; j++ ) {
			_mesh_map[ i ][ j ] = 0;
		}
	}
	Mouse mouse;
	Vector mpos = mouse.getPoint( );
	if ( 0 < mpos.x && mpos.x < MAP_SIZE_X * CHIP_SIZE && 0 < mpos.y && mpos.y < MAP_SIZE_Y * CHIP_SIZE ) {
		for ( int i = 0; i < _select_object.size_y; i++ ) {
			for ( int j = 0; j < _select_object.size_x; j++ ) {
				int x = ( int )mpos.x / CHIP_SIZE + j;
				int y = ( int )mpos.y / CHIP_SIZE + i;
				_mesh_map[ y ][ x ] = 1;
			}
		}
	}
}

void MapEditor::putObjectUpdate( ) {
	int id =  _select_manager->getSelectObject( );
	_select_object = _object_list[ id ];
	Mouse mouse;
	if ( mouse.isInputButton( Mouse::INPUT_LEFT ) ) {
		Vector mpos = mouse.getPoint( );
		if ( 0 < mpos.x && mpos.x < MAP_SIZE_X * CHIP_SIZE && 0 < mpos.y && mpos.y < MAP_SIZE_Y * CHIP_SIZE ) {
			for ( int i = 0; i < _select_object.size_y; i++ ) {
				for ( int j = 0; j < _select_object.size_x; j++ ) {
					int x = ( int )mpos.x / CHIP_SIZE + j;
					int y = ( int )mpos.y / CHIP_SIZE + i;
					_object_map[ y ][ x ] = _select_object.name;
				}
			}
		}
	}
}

int MapEditor::getMeshMap( int x, int y ) const {
	return _mesh_map[ y ][ x ];
}

int MapEditor::getObjectMap( int x, int y ) const {
	return _object_map[ y ][ x ];
}

Stage::CLEAR_TREMS MapEditor::getClearTrems( ) const{
	return _trems_manager->getClearTrems( );
}

TremsManagerPtr MapEditor::getTremsManager( ) const {
	return _trems_manager;
}

SelectObjectManagerPtr MapEditor::getSelectObjectManager( ) const {
	return _select_manager;
}