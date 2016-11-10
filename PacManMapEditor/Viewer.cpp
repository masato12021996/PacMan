#include "Viewer.h"
#include "Application.h"
#include "MapEditor.h"
#include "TremsManager.h"
#include "SelectObjectManager.h"
#include "Button.h"
#include "GraphManager.h"
#include "Drawer.h"

const int CHIP_SIZE = 32;

const GraphManager::CHIP_ID OBJECT_LIST[ 7 ] = {
	GraphManager::CHIP_ID_PACMAN_1,
	GraphManager::CHIP_ID_ENEMY_RED_DOWN_0,
	GraphManager::CHIP_ID_ENEMY_PINC_DOWN_0,
	GraphManager::CHIP_ID_ENEMY_BLUE_DOWN_0,
	GraphManager::CHIP_ID_ENEMY_ORANGE_DOWN_0,
	GraphManager::CHIP_ID_TARGET_BATE,
	GraphManager::CHIP_ID_TARGET_POWER_BATE,
};

ViewerPtr Viewer::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast< Viewer >( application->getTask( getTag( ) ) );
}

Viewer::Viewer( ) {
	_graph_manager = GraphManagerPtr( new GraphManager );
}

Viewer::~Viewer( ) {
}

void Viewer::update( ) {
	drawTremsButton( );
	drawObjectButton( );
	drawMatrix( );
	drawObject( );
}

void Viewer::drawMatrix( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	for ( int i = 0; i < 24; i++ ) {
		for ( int j = 0; j < 30; j++ ) {
			bool flag = map_editor->getMeshMap( j, i ) == 1;
			drawer->drawBox( j * CHIP_SIZE, i * CHIP_SIZE, CHIP_SIZE, flag );
		}
	}
}

void Viewer::drawObject( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	for ( int i = 0; i < 24; i++ ) {
		for ( int j = 0; j < 30; j++ ) {
			int id = map_editor->getObjectMap( j, i );
			int x = CHIP_SIZE * j;
			int y = CHIP_SIZE * i;
			switch ( id ) {
			case Stage::OBJECT_NAME_PLAYER:
				_graph_manager->drawChip( x, y, GraphManager::CHIP_ID_PACMAN_1 );
				break;
			case Stage::OBJECT_NAME_ENEMY_RED:
				_graph_manager->drawChip( x, y, GraphManager::CHIP_ID_ENEMY_RED_DOWN_0 );
				break;
			case Stage::OBJECT_NAME_ENEMY_PINC:
				_graph_manager->drawChip( x, y, GraphManager::CHIP_ID_ENEMY_PINC_DOWN_0 );
				break;
			case Stage::OBJECT_NAME_ENEMY_BLUE:
				_graph_manager->drawChip( x, y, GraphManager::CHIP_ID_ENEMY_BLUE_DOWN_0 );
				break;
			case Stage::OBJECT_NAME_ENEMY_ORANGE:
				_graph_manager->drawChip( x, y, GraphManager::CHIP_ID_ENEMY_ORANGE_DOWN_0 );
				break;
			case Stage::OBJECT_NAME_BATE:
				_graph_manager->drawChip( x, y, GraphManager::CHIP_ID_TARGET_BATE );
				break;
			case Stage::OBJECT_NAME_POWER_BATE:
				_graph_manager->drawChip( x, y, GraphManager::CHIP_ID_TARGET_POWER_BATE );
				break;
			default:
				break;
			}
		}
	}
}

void Viewer::drawTremsButton( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	TremsManagerPtr trems_manager = map_editor->getTremsManager( );
	for ( int i = 0; i < trems_manager->getButtonNum( ); i++ ) {
		ButtonPtr button = trems_manager->getButton( i );
		int px = button->getButtonPosX( );
		int py = button->getButtonPosY( );
		int width = button->getButtonWidth( );
		int height = button->getButtonHeight( );
		bool fill_flag = button->getFillFlag( );
		drawer->drawBox( px, py, width, height, fill_flag );
		drawer->drawString( px + 5, py + 5, trems_manager->getButtonName( i ).c_str( ), fill_flag );
	}
}

void Viewer::drawObjectButton( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	SelectObjectManagerPtr select_manager = map_editor->getSelectObjectManager( );
	for ( int i = 0; i < select_manager->getButtonNum( ); i++ ) {
		ButtonPtr button = select_manager->getButton( i );
		int px = button->getButtonPosX( );
		int py = button->getButtonPosY( );
		int width = button->getButtonWidth( );
		int height = button->getButtonHeight( );
		bool fill_flag = button->getFillFlag( );
		_graph_manager->drawChip( px, py, OBJECT_LIST[ i ] );
		if ( i == select_manager->getButtonNum( ) - 1 ) {
			_graph_manager->drawChip( px, py, GraphManager::CHIP_ID_BACK_GROUND__D_RS );
			_graph_manager->drawChip( px + CHIP_SIZE, py, GraphManager::CHIP_ID_BACK_GROUND__DL_S );
			_graph_manager->drawChip( px, py + CHIP_SIZE, GraphManager::CHIP_ID_BACK_GROUND_U__RS );
			_graph_manager->drawChip( px + CHIP_SIZE, py + CHIP_SIZE, GraphManager::CHIP_ID_BACK_GROUND_U_L_S );
		}
		drawer->drawBox( px, py, width, height, fill_flag );
	}
}