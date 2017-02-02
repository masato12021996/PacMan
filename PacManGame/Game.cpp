#include "Game.h"
#include "Application.h"
#include "PlayGame.h"
#include "Title.h"
#include "Sound.h"
#include "Ranking.h"
#include <assert.h>

const int RESULT_TIME = 60 * 5;

GamePtr Game::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast<Game>( application->getTask( getTag( ) ) );
}

Game::Game( ) {
	_title = TitlePtr( new Title( ) );
	_play_game = PlayGamePtr( new PlayGame( ) );
	_ranking = RankingPtr( new Ranking( ) );
	_reset_flag = true;
}

Game::~Game( ) {
}

void Game::initialize( ) {
	_game_state = GAME_STATE_TITLE;
	_result_timer = 0;
}

void Game::update( ) {
	SoundPtr sound = Sound::getTask( );
	switch ( _game_state ) {
		case GAME_STATE_TITLE:
			if ( _reset_flag ) {
				_play_game->reset( );
				sound->playBGM( "coffeebreak.wav" );
				_reset_flag = false;
			}
			//タイトル
			_title->update( );
			if ( _title->isEndTitle( ) ) {
				sound->stopBGM( );
				_game_state = GAME_STATE_PLAY;
			}
			break;
		case GAME_STATE_PLAY:
			//ステージのプレイ
			_play_game->update( );
			if ( _play_game->isEndGame( ) ) {
				_game_state = GAME_STATE_RESULT;
				_result_timer = 0;
				_ranking->setClearNum( _play_game->getClearStageNum( ) );
			}
			break;
		case GAME_STATE_RESULT:
			//ランキング
			if ( RESULT_TIME < _result_timer ) {
				_game_state = GAME_STATE_TITLE;
				_reset_flag = true;
			}
			_result_timer++;
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

RankingPtr Game::getRanking( ) const {
	return _ranking;
}
