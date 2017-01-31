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
	_reset_flag = false;
}

Game::~Game( ) {
}

void Game::initialize( ) {
	_game_state = GAME_STATE_TITLE;
}

void Game::update( ) {
	switch ( _game_state ) {
		case GAME_STATE_TITLE:
			if ( _reset_flag ) {
				_play_game->reset( );
				_reset_flag = false;
			}
			//タイトル
			_title->update( );
			if ( _title->isEndTitle( ) ) {
				_game_state = GAME_STATE_PLAY;
			}
			break;
		case GAME_STATE_PLAY:
			//ステージのプレイ
			_play_game->update( );
			if ( _play_game->isEndGame( ) ) {
				_game_state = GAME_STATE_RESULT;
			}
			break;
		case GAME_STATE_RESULT:
			//ランキング
			_play_game->getClearStageNum( );
			_reset_flag = true;
			if ( true ) {
				_game_state = GAME_STATE_TITLE;
			}
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