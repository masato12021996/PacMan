#include "GraphManager.h"

const int CHIP_SIZE = 32;

GraphManager::GraphManager( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_ID_PACMAN_LEFT, "../Resource/Graph/PlayerLeft.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_RIGHT, "../Resource/Graph/PlayerRight.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_DOWN, "../Resource/Graph/PlayerDown.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_UP, "../Resource/Graph/PlayerUp.png" );
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
	
	//¶Œü‚«
	if ( CHIP_ID_PACMAN_1_LEFT <= id && id <= CHIP_ID_PACMAN_3_LEFT ) {
		int index = id - CHIP_ID_PACMAN_1_LEFT;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_LEFT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//‰EŒü‚«
	if ( CHIP_ID_PACMAN_1_RIGHT <= id && id <= CHIP_ID_PACMAN_3_RIGHT ) {
		int index = id - CHIP_ID_PACMAN_1_RIGHT;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_RIGHT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//‰ºŒü‚«
	if ( CHIP_ID_PACMAN_1_DOWN <= id && id <= CHIP_ID_PACMAN_3_DOWN ) {
		int index = id - CHIP_ID_PACMAN_1_DOWN;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_DOWN;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//ãŒü‚«
	if ( CHIP_ID_PACMAN_1_UP <= id && id <= CHIP_ID_PACMAN_3_UP ) {
		int index = id - CHIP_ID_PACMAN_1_UP;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_UP;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	if ( CHIP_ID_PACMAN_DEAD_01 <= id && id <= CHIP_ID_PACMAN_DEAD_11 ) {
		int index = id - CHIP_ID_PACMAN_DEAD_01;
		const int OFFSET_X = 4;
		const int OFFSET_Y = CHIP_SIZE + 4;
		sprite.image = GRAPH_ID_PACMAN_DEAD;
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
	if ( CHIP_ID_BACK_GROUND_000010000 <= id && id <= CHIP_ID_BACK_GROUND_011111000 ) {
		int index = id - CHIP_ID_BACK_GROUND_000010000;
		sprite.image = GRAPH_ID_BACK_GROUND;
		sprite.tx = CHIP_SIZE * ( index % 7 );
		sprite.ty = CHIP_SIZE * ( index / 7 );
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