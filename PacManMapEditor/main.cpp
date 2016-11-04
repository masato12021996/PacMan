#include "Application.h"
#include "MapEditor.h"
#include "Viewer.h"

void main( ) {
	ApplicationPtr application = Application::getInstance( );

	MapEditorPtr mapeditor = MapEditorPtr( new MapEditor );
	ViewerPtr viewer = ViewerPtr( new Viewer );

	application->addTask( MapEditor::getTag( ), mapeditor );
	application->addTask( Viewer::getTag( ), viewer );
}