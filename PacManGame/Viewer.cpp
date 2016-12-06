#include "Application.h"
#include "Viewer.h"
#include "ViewerTitle.h"
#include "ViewerPlay.h"
#include "Game.h"
#include "MapDefine.h"
#include <assert.h>


ViewerPtr Viewer::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast<Viewer>( application->getTask( getTag( ) ) );
}

Viewer::Viewer( ) {
}

Viewer::~Viewer( ) {
}

void Viewer::initialize( ) {
	_titile = ViewerTitlePtr( new ViewerTitle( ) );
	_play = ViewerPlayPtr( new ViewerPlay( ) );
}

void Viewer::update( ) {
	GamePtr game = Game::getTask( );
	Game::GAME_STATE game_state = game->getGameState( );
	switch ( game_state ) {
		case Game::GAME_STATE_TITILE:
			_titile->update( );
			break;
		case Game::GAME_STATE_PLAY:
			_play->update( );
			break;
		default:
			assert( "NoneGameState" );
			break;
	}
}