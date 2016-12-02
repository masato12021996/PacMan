#include "Viewer.h"
#include "Application.h"
#include "Drawer.h"
#include "Game.h"
#include "PlayGame.h"
#include "Stage.h"
#include "MapDefine.h"
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
}

void Viewer::update( ) {
	GamePtr game = Game::getTask( );
	Game::GAME_STATE game_state = game->getGameState( );
	switch ( game_state ) {
		case Game::GAME_STATE_TITILE:
			drawTitle( );
			break;
		case Game::GAME_STATE_PLAY:
			drawPlayGame( );
			break;
		default:
			assert( "NoneGameState" );
			break;
	}
}

void Viewer::drawTitle( ) {
}

void Viewer::drawPlayGame( ) {
	GamePtr game = Game::getTask( );
	PlayGamePtr play_game =game->getPlayGame( );
	StagePtr stage = play_game->getPlayStage( );
	if ( stage ) {
		drawStage( stage );
	}
}

void Viewer::drawStage( StagePtr stage ) {
	//ステージの描画
	DrawerPtr drawer = Drawer::getTask( );
	for ( int i = 0; i < MapParameter::MAP_SIZE_Y; i++ ) {
		for ( int j = 0; j < MapParameter::MAP_SIZE_X; j++ ) {
			int object = stage->getTargetCell( j, i );
			if ( object == Stage::OBJECT_NAME_WALL ) {
				int chip_size = MapParameter::CHIP_SIZE;
				drawer->drawBox( j * chip_size, i * chip_size, chip_size, true );
			}
		}
	}
}