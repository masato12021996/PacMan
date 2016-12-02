#include "Application.h"
#include "Game.h"
#include "Viewer.h"
#include "MapDefine.h"

void main( ) {
	ApplicationPtr application = Application::getInstance( );
	application->setWindowSize( MapParameter::MAP_SIZE_X * MapParameter::CHIP_SIZE, MapParameter::MAP_SIZE_Y * MapParameter::CHIP_SIZE );
	GamePtr game = GamePtr( new Game );
	ViewerPtr viewer = ViewerPtr( new Viewer );

	application->addTask( Game::getTag( ), game );
	application->addTask( Viewer::getTag( ), viewer );
}