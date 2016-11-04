#include "Application.h"
#include "Game.h"
#include "Viewer.h"

void main( ) {
	ApplicationPtr application = Application::getInstance( );
	GamePtr game = GamePtr( new Game );
	ViewerPtr viewer = ViewerPtr( new Viewer );

	application->addTask( Game::getTag( ), game );
	application->addTask( Viewer::getTag( ), viewer );
}