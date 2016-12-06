#include "ViewerPlay.h"
#include "Game.h"
#include "PlayGame.h"
#include "Stage.h"
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
	StagePtr stage = _play_game->getPlayStage( );
	if ( stage ) {
		drawStage( stage );
	}
}

void ViewerPlay::drawStage( StagePtr stage ) {
	//ステージの描画
	DrawerPtr drawer = Drawer::getTask( );
	for ( int i = 0; i < MapParameter::MAP_SIZE_Y; i++ ) {
		for ( int j = 0; j < MapParameter::MAP_SIZE_X; j++ ) {
			int object = stage->getTargetCell( j, i );
			if ( object == Stage::OBJECT_NAME_WALL ) {
				int chip_size = MapParameter::CHIP_SIZE;
				int x = DRAW_STAGE_POS_X + j * chip_size;
				int y = DRAW_STAGE_POS_Y + i * chip_size;
				//ここで本来の壁の描画をする
				drawer->drawBox( x, y, chip_size, true );
			}
		}
	}
}