#include "Viewer.h"
#include "Application.h"
#include "Drawer.h"
#include "Game.h"
#include "Field.h"
#include <assert.h>

enum GRAPH {
	GRAPH_WALL
};

ViewerPtr Viewer::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast<Viewer>( application->getTask( getTag( ) ) );
}

Viewer::Viewer( ) {
}

Viewer::~Viewer( ) {
}

void Viewer::initialize( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_WALL, "../Resource/Graph/WALL.png" );
}

void Viewer::update( ) {
	GamePtr game = Game::getTask( );
	Game::GAME_STATE game_state = game->getGameState( );
	switch ( game_state ) {
		case Game::GAME_STATE_TITILE:
			break;
		case Game::GAME_STATE_PLAY:
			break;
		default:
			assert( "NoneGameState" );
			break;
	}
}