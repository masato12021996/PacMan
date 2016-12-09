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
	//クリア条件の描画
}

void ViewerPlay::drawPlay( ) {
	PlayStagePtr stage = _play_game->getPlayStage( );
	if ( !stage ) {
		return;
	}
	//フィールドの描画
	drawField( stage );
	//エネミーの描画
	//プレイヤーの描画
	//UIの描画
}

void ViewerPlay::drawResult( ) {
	drawPlay( );
	//リザルトを描画する
}

void ViewerPlay::drawField( PlayStagePtr stage ) {
	//ステージの描画
	DrawerPtr drawer = Drawer::getTask( );
	FieldPtr field = stage->getField( );
	for ( int i = 0; i < field->getSizeX( ); i++ ) {
		for ( int j = 0; j < field->getSizeY( ); j++ ) {
			Field::OBJECT object = field->getFieldTarget( i, j );
			if ( object == Field::OBJECT_WALL ) {
				int chip_size = MapParameter::CHIP_SIZE;
				int x = DRAW_STAGE_POS_X + i * chip_size;
				int y = DRAW_STAGE_POS_Y + j * chip_size;
				//ここで本来の壁の描画をする
				drawer->drawBox( x, y, chip_size, true );
			}
		}
	}
}

