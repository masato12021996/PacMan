#include "Application.h"
#include "Keyboard.h"
#include "Game.h"
#include "Viewer.h"
#include "MapDefine.h"

void main( ) {
	ApplicationPtr application = Application::getInstance( );
	application->setWindowSize( MapParameter::MAP_SIZE_X * MapParameter::CHIP_SIZE, MapParameter::MAP_SIZE_Y * ( MapParameter::CHIP_SIZE + 1 ) );
	KeyboardPtr keyboad = KeyboardPtr( new Keyboard( ) );
	GamePtr game = GamePtr( new Game );
	ViewerPtr viewer = ViewerPtr( new Viewer );


	application->addTask( Keyboard::getTag( ), keyboad );
	application->addTask( Game::getTag( ), game );
	application->addTask( Viewer::getTag( ), viewer );
}