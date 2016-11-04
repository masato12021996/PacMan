#include "Viewer.h"
#include "Application.h"
#include "MapEditor.h"
#include "TremsManager.h"
#include "SelectObjectManager.h"
#include "Button.h"
#include "Drawer.h"

enum GRAPH_ID {
	GRAPH_ID_PACMAN,
};

ViewerPtr Viewer::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast< Viewer >( application->getTask( getTag( ) ) );
}

Viewer::Viewer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_ID_PACMAN, "../Resource/Graph/Player.png" );
}

Viewer::~Viewer( ) {
}

void Viewer::update( ) {
	drawTremsButton( );
	drawObjectButton( );
	drawMatrix( );
}

void Viewer::drawMatrix( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	for ( int i = 0; i < 24; i++ ) {
		for ( int j = 0; j < 30; j++ ) {
			bool flag = map_editor->getMeshMap( j, i ) == 1;
			drawer->drawBox( j * 32, i * 32, 32, flag );
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
		Drawer::Sprite sprite;
		sprite.x = px;
		sprite.y = py;
		sprite.tx = 4;
		sprite.ty = 0;
		sprite.width = width;
		sprite.height = height;
		sprite.image = GRAPH_ID_PACMAN;
		sprite.trans_flag = true;
		drawer->setSprite( sprite );
		drawer->drawBox( px, py, width, height, fill_flag );
	}
}