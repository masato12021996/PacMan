#include "ViewerPlay.h"
#include "Game.h"
#include "PlayGame.h"
#include "PlayStage.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Animation.h"
#include "MapDefine.h"
#include "GraphManager.h"
#include "Drawer.h"
#include "Stage.h"
#include <string>

const int DRAW_STAGE_POS_X = 0;
const int DRAW_STAGE_POS_Y = MapParameter::CHIP_SIZE;

ViewerPlay::ViewerPlay( GraphManagerPtr graph_manager ) {
	GamePtr game = Game::getTask( );
	_play_game = game->getPlayGame( );
	_graph_manager = graph_manager;
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
	//ƒNƒŠƒAðŒ‚Ì•`‰æ
	PlayStagePtr stage = _play_game->getPlayStage( );
	GraphManager::CHIP_ID id;
	switch ( stage->getTrems( ) ) {
	case Stage::CLEAR_TREMS_FOOD_EAT:
		id = GraphManager::CHIP_ID_TREMS_EAT;
		break;
	case Stage::CLEAR_TREMS_OUTRUN:
		id = GraphManager::CHIP_ID_TREMS_RUN;
		break;
	case Stage::CLEAR_TREMS_ENEMY_EAT:
		id = GraphManager::CHIP_ID_TREMS_KILL;
		break;
	}
	_graph_manager->drawChip( 0, 0, id );
}

void ViewerPlay::drawPlay( ) {
	PlayStagePtr stage = _play_game->getPlayStage( );
	if ( !stage ) {
		return;
	}
	//ƒtƒB[ƒ‹ƒh‚Ì•`‰æ
	drawField( stage );
	drawWall( stage );
	//ƒGƒlƒ~[‚Ì•`‰æ
	drawEnemy( stage );
	//ƒvƒŒƒCƒ„[‚Ì•`‰æ
	drawPlayer( stage );
	//UI‚Ì•`‰æ
	if ( stage->getTrems( ) == 2 ) {
		drawTime( stage->getTime( ) );
	}
	drawClearState( );
	drawClearStageNum( );
}

void ViewerPlay::drawResult( ) {
	PlayStagePtr stage = _play_game->getPlayStage( );
	drawPlay( );
	//ƒŠƒUƒ‹ƒg‚ð•`‰æ‚·‚é
	if ( stage->isDeadStage( ) ) {
		_graph_manager->drawChip( 0, 0, GraphManager::CHIP_ID_GAMEOVER );
	}
	if ( stage->isClearStage( ) ) {
		_graph_manager->drawChip( 0, 0, GraphManager::CHIP_ID_CLEAR );
	}
}

void ViewerPlay::drawField( PlayStagePtr stage ) {
	//ƒXƒe[ƒW‚Ì•`‰æ
	DrawerPtr drawer = Drawer::getTask( );
	FieldPtr field = stage->getField( );
	for ( int i = 0; i < field->getSizeX( ); i++ ) {
		for ( int j = 0; j < field->getSizeY( ); j++ ) {
			Field::OBJECT object = field->getFieldTarget( i, j );
			if ( object == Field::OBJECT_BATE ) {
				int chip_size = MapParameter::CHIP_SIZE;
				int x = DRAW_STAGE_POS_X + i * chip_size;
				int y = DRAW_STAGE_POS_Y + j * chip_size;
				GraphManager::CHIP_ID id = GraphManager::CHIP_ID_TARGET_BATE;
				_graph_manager->drawChip( x, y, id );
			}
			if ( object == Field::OBJECT_POWER_BATE ) {
				int chip_size = MapParameter::CHIP_SIZE;
				int x = DRAW_STAGE_POS_X + i * chip_size;
				int y = DRAW_STAGE_POS_Y + j * chip_size;
				GraphManager::CHIP_ID id = GraphManager::CHIP_ID_TARGET_POWER_BATE;
				_graph_manager->drawChip( x, y, id );
			}
		}
	}
}

void ViewerPlay::drawWall( PlayStagePtr stage ) {
	DrawerPtr drawer = Drawer::getTask( );
	FieldPtr field = stage->getField( );
	for ( int i = 0; i < field->getSizeX( ) + 1; i++ ) {
		for ( int j = 0; j < field->getSizeY( ) + 1; j++ ) {
			unsigned int num = 0;
			for ( int k = 0; k < 4; k++ ) {
				num <<= 1;
				int x = i - k % 2;
				int y = j - k / 2;
				if ( x < 0 || x >= field->getSizeX( ) ) {
					continue;
				}
				if ( y < 0 || y >= field->getSizeY( ) ) {
					continue;
				}
				Field::OBJECT object = field->getFieldTarget( x, y );
				if ( object == Field::OBJECT_WALL ) {
					num += 1;
				}
			}
			int x = DRAW_STAGE_POS_X + i * MapParameter::CHIP_SIZE - MapParameter::CHIP_SIZE / 2;
			int y = DRAW_STAGE_POS_Y + j * MapParameter::CHIP_SIZE - MapParameter::CHIP_SIZE / 2;
			int id = GraphManager::CHIP_ID_BACK_GROUND_0000;
			_graph_manager->drawChip( x, y, ( GraphManager::CHIP_ID  )( id + num ) );
			//‚±‚±‚Å–{—ˆ‚Ì•Ç‚Ì•`‰æ‚ð‚·‚é
		}
	}
}

void ViewerPlay::drawPlayer( PlayStagePtr stage ) {
	PlayerPtr player = stage->getPlayer( );
	Vector pos = player->getPos( );
	AnimationPtr anim = player->getAnimation( );
	int x = ( int )pos.x - MapParameter::CHIP_SIZE / 2;
	int y = MapParameter::CHIP_SIZE + ( int )pos.y - MapParameter::CHIP_SIZE / 2;
	GraphManager::CHIP_ID id = ( GraphManager::CHIP_ID )anim->getAnimGraph( );
	_graph_manager->drawChip( x, y, id );
}

void ViewerPlay::drawEnemy( PlayStagePtr stage ) {
	int num = stage->getEnemyNum( );
	for ( int i = 0; i < num; i++ ) {
		EnemyPtr enemy = stage->getEnemy( i );
		if ( enemy->isExpired( ) ) {
			Vector pos = enemy->getPos( );
			AnimationPtr anim = enemy->getAnimation( );
			int x = ( int )pos.x - MapParameter::CHIP_SIZE / 2;
			int y = MapParameter::CHIP_SIZE + ( int )pos.y - MapParameter::CHIP_SIZE / 2;
			GraphManager::CHIP_ID id = ( GraphManager::CHIP_ID )anim->getAnimGraph( );
			_graph_manager->drawChip( x, y, id );
		}
	}
}

void ViewerPlay::drawTime( double time ) {
	DrawerPtr drawer = Drawer::getTask( );
	std::string str = "Time:" + std::to_string( ( int )( time ) % 100 / 10 );
	str += std::to_string( ( int )( time ) % 10 );
	str += ".";
	str += std::to_string( ( int )( time * 100 ) % 100 / 10 );
	str += std::to_string( ( int )( time * 100 ) % 10 );
	drawer->drawString( 700, 16, str.c_str( ), false );
}

void ViewerPlay::drawClearStageNum( ) {
	int num = _play_game->getClearStageNum( );
	DrawerPtr drawer = Drawer::getTask( );
	std::string str = "ClearStageNum:" + std::to_string( num );
	drawer->drawString( 800, 16, str.c_str( ), false );
}

void ViewerPlay::drawClearState( ) {
	DrawerPtr drawer = Drawer::getTask( );
	PlayStagePtr stage = _play_game->getPlayStage( );
	std::string str;
	switch ( stage->getTrems( ) ) {
	case Stage::CLEAR_TREMS_FOOD_EAT:
		str = "‚·‚×‚Ä‚ÌƒGƒT‚ðH‚×‚ë";
		break;
	case Stage::CLEAR_TREMS_OUTRUN:
		str = "“G‚©‚ç“¦‚°‚«‚ê";
		break;
	case Stage::CLEAR_TREMS_ENEMY_EAT:
		str = "“G‚ð‚·‚×‚Ä“|‚¹";
		break;
	}
	drawer->drawString( 0, 0, str.c_str( ), false );
}
