#include "Game.h"
#include "Application.h"
#include "PlayGame.h"
#include "Title.h"
#include <assert.h>

GamePtr Game::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast<Game>( application->getTask( getTag( ) ) );
}

Game::Game( ) {
	_title = TitlePtr( new Title( ) );
	_play_game = PlayGamePtr( new PlayGame( ) );
}

Game::~Game( ) {
}

void Game::initialize( ) {
	_game_state = GAME_STATE_PLAY;
}

void Game::update( ) {
	switch ( _game_state ) {
		case GAME_STATE_TITILE:
			//タイトル
			_title->update( );
			break;
		case GAME_STATE_PLAY:
			//ステージのプレイ
			_play_game->update( );
			break;
		case GAME_STATE_RESULT:
			//ランキング
			break;
		default:
			assert( "NoneGameState" );
			break;
	}
}

Game::GAME_STATE Game::getGameState( ) const {
	return _game_state;
}

PlayGamePtr Game::getPlayGame( ) const {
	return _play_game;
}