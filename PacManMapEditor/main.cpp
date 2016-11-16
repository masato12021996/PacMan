#include "Application.h"
#include "MapEditor.h"
#include "Viewer.h"
#include "Mouse.h"

void main( ) {
	ApplicationPtr application = Application::getInstance( );
	application->setWindowSize( 1130, 768 );

	MapEditorPtr mapeditor = MapEditorPtr( new MapEditor );
	ViewerPtr viewer = ViewerPtr( new Viewer );
	MousePtr mouse = MousePtr( new Mouse );

	application->addTask( MapEditor::getTag( ), mapeditor );
	application->addTask( Viewer::getTag( ), viewer );
	application->addTask( Mouse::getTag( ), mouse );
}