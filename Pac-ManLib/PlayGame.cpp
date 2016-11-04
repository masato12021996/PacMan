#include "PlayGame.h"


PlayGame::PlayGame( ) {
}

PlayGame::~PlayGame( ) {
}

void PlayGame::initialize( ) {
	_clear_stage_num = 0;
	_play_state = PLAY_STATE_PLAY;
}

void PlayGame::update( ) {
	switch( _play_state ) {
	case PLAY_STATE_TITLE:
		break;
	case PLAY_STATE_PLAY:
		break;
	case PLAY_STATE_RESULT:
		break;
	}
}

PlayGame::PLAY_STATE PlayGame::getPlayState( ) const {
	return _play_state;
}

void PlayGame::addStage( StagePtr stage ) {
	if ( _stage_list.size( ) > MAX_STAGE_NUM ) {
		return;
	}
	_stage_list.push_back( stage );
}