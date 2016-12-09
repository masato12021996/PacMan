#include "ViewerPlay.h"
#include "Game.h"
#include "PlayGame.h"
#include "PlayStage.h"
#include "Field.h"
#include "MapDefine.h"
#include "Drawer.h"

const int DRAW_STAGE_POS_X = 0;
const int DRAW_STAGE_POS_Y = MapParameter::CHIP_SIZE;

ViewerPlay::ViewerPlay() {
	GamePtr game = Game::getTask( );
	_play_game = game->getPlayGame( );
}

ViewerPlay::~ViewerPlay() {
}

void ViewerPlay::update( ) {
	PlayGame::PLAY_STATE state = _play_game->getState( );
	switch ( state ) {
	case PlayGame::PLAY_STATE_READY:
		drawReady( );
		break;
	case PlayGame::PLAY_STATE_PLAY:
		drawPlay( );
		break;
	case PlayGame::PLAY_STATE_RESULT:
		drawResult( );
		break;
	}
}

void ViewerPlay::drawReady( ) {
	//�N���A�����̕`��
}

void ViewerPlay::drawPlay( ) {
	PlayStagePtr stage = _play_game->getPlayStage( );
	if ( !stage ) {
		return;
	}
	//�t�B�[���h�̕`��
	drawField( stage );
	//�G�l�~�[�̕`��
	//�v���C���[�̕`��
	//UI�̕`��
}

void ViewerPlay::drawResult( ) {
	drawPlay( );
	//���U���g��`�悷��
}

void ViewerPlay::drawField( PlayStagePtr stage ) {
	//�X�e�[�W�̕`��
	DrawerPtr drawer = Drawer::getTask( );
	FieldPtr field = stage->getField( );
	for ( int i = 0; i < field->getSizeX( ); i++ ) {
		for ( int j = 0; j < field->getSizeY( ); j++ ) {
			Field::OBJECT object = field->getFieldTarget( i, j );
			if ( object == Field::OBJECT_WALL ) {
				int chip_size = MapParameter::CHIP_SIZE;
				int x = DRAW_STAGE_POS_X + i * chip_size;
				int y = DRAW_STAGE_POS_Y + j * chip_size;
				//�����Ŗ{���̕ǂ̕`�������
				drawer->drawBox( x, y, chip_size, true );
			}
		}
	}
}

