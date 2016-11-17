#include "GraphManager.h"

const int CHIP_SIZE = 32;

GraphManager::GraphManager( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_ID_PACMAN, "../Resource/Graph/Player.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY, "../Resource/Graph/Enemy.png" );
	drawer->loadGraph( GRAPH_ID_TARGET, "../Resource/Graph/Target.png" );
	drawer->loadGraph( GRAPH_ID_BACK_GROUND, "../Resource/Graph/BackGround.png" );
}

GraphManager::~GraphManager( ) {
}

void GraphManager::drawChip( int x, int y, CHIP_ID id ) {
	Drawer::Sprite sprite;
	sprite = getSprite( x, y, id );
	DrawerPtr drawer = Drawer::getTask( );
	drawer->setSprite( sprite );
}

Drawer::Sprite GraphManager::getSprite( int x, int y, CHIP_ID id ) {
	Drawer::Sprite sprite;
	sprite.x = x;
	sprite.y = y;
	sprite.height = CHIP_SIZE;
	sprite.width = CHIP_SIZE;
	sprite.trans_flag = true;
	
	if ( CHIP_ID_PACMAN_1 <= id && id <= CHIP_ID_PACMAN_3 ) {
		int index = id - CHIP_ID_PACMAN_1;
		const int OFFSET_X = 4;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	if ( CHIP_ID_PACMAN_DEAD_01 <= id && id <= CHIP_ID_PACMAN_DEAD_11 ) {
		int index = id - CHIP_ID_PACMAN_DEAD_01;
		const int OFFSET_X = 4;
		const int OFFSET_Y = CHIP_SIZE + 4;
		sprite.image = GRAPH_ID_PACMAN;
		sprite.tx = ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	if ( CHIP_ID_ENEMY_RED_RIGHT_0 <= id && id <= CHIP_ID_ENEMY_ORANGE_UP_1 ) {
		int index = id - CHIP_ID_ENEMY_RED_RIGHT_0;
		const int OFFSET_X = 4;
		const int OFFSET_Y = 4;
		sprite.image = GRAPH_ID_ENEMY;
		sprite.tx = ( CHIP_SIZE + OFFSET_X ) * ( index % 8 );
		sprite.ty = ( CHIP_SIZE + OFFSET_Y ) * ( index / 8 );
	}
	if ( CHIP_ID_BACK_GROUND_NONE <= id && id <= CHIP_ID_BACK_GROUND_UDLR ) {
		int index = id - CHIP_ID_BACK_GROUND_NONE;
		sprite.image = GRAPH_ID_BACK_GROUND;
		sprite.tx = CHIP_SIZE * ( index % 8 );
		sprite.ty = CHIP_SIZE * ( index / 8 );
	}
	if ( CHIP_ID_TARGET_CHERRY <= id && id <= CHIP_ID_TARGET_POWER_BATE ) {
		int index = id - CHIP_ID_TARGET_CHERRY;
		const int OFFSET_X = 4;
		const int OFFSET_Y = 4;
		sprite.image = GRAPH_ID_TARGET;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	return sprite;
}