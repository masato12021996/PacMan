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
	MousePtr mouse = Mouse::getTask( );
	Vector mpos = mouse->getPoint( );
	if ( 0 < mpos.x && mpos.x < MAP_SIZE_X * CHIP_SIZE && 0 < mpos.y && mpos.y < MAP_SIZE_Y * CHIP_SIZE ) {
		int x = ( int )mpos.x / CHIP_SIZE;
		int y = ( int )mpos.y / CHIP_SIZE;
		_mesh_map[ y ][ x ] = 1;
	}
}

void MapEditor::putObjectUpdate( ) {
	_select_object =  _select_manager->getSelectObject( );
	MousePtr mouse = Mouse::getTask( );
	if ( mouse->isInputButton( Mouse::INPUT_ON_LEFT ) ) {
		Vector mpos = mouse->getPoint( );
		if ( 0 < mpos.x && mpos.x < MAP_SIZE_X * CHIP_SIZE && 0 < mpos.y && mpos.y < MAP_SIZE_Y * CHIP_SIZE ) {
			int x = ( int )mpos.x / CHIP_SIZE;
			int y = ( int )mpos.y / CHIP_SIZE;
			_object_map[ y ][ x ] = _select_object;
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