#include "Viewer.h"
#include "Application.h"
#include "MapEditor.h"
#include "TremsManager.h"
#include "Button.h"
#include "Drawer.h"

ViewerPtr Viewer::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast< Viewer >( application->getTask( getTag( ) ) );
}

Viewer::Viewer( ) {
}

Viewer::~Viewer( ) {
}

void Viewer::update( ) {
	drawTremsButton( );
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