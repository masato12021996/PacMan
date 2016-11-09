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
		const int OFFSET_Y = 4;
		sprite.image = GRAPH_ID_PACMAN;
		sprite.tx = ( CHIP_SIZE + OFFSET_X ) * id;
		sprite.ty = OFFSET_Y;
	}
	return sprite;
}