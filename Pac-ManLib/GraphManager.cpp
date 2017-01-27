#include "GraphManager.h"

const int CHIP_SIZE = 32;

GraphManager::GraphManager( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_ID_PACMAN_LEFT,		"../Resource/Graph/Player/PlayerLeft.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_RIGHT,		"../Resource/Graph/Player/PlayerRight.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_DOWN,		"../Resource/Graph/Player/PlayerDown.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_UP,			"../Resource/Graph/Player/PlayerUp.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_LD,			"../Resource/Graph/Player/PlayerLD.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_LU,			"../Resource/Graph/Player/PlayerLU.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_RD,			"../Resource/Graph/Player/PlayerRD.png" );
	drawer->loadGraph( GRAPH_ID_PACMAN_RU,			"../Resource/Graph/Player/PlayerRU.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_BAD_B,		"../Resource/Graph/Enemy/Bad/EnemyBad_B.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_BAD_W,		"../Resource/Graph/Enemy/Bad/EnemyBad_W.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_RED_DOWN,		"../Resource/Graph/Enemy/Red/RedDown.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_RED_LEFT,		"../Resource/Graph/Enemy/Red/RedLeft.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_RED_RIGHT,	"../Resource/Graph/Enemy/Red/RedRight.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_RED_UP,		"../Resource/Graph/Enemy/Red/RedUp.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_ORANGE_DOWN,	"../Resource/Graph/Enemy/Orange/OrangeDown.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_ORANGE_LEFT,	"../Resource/Graph/Enemy/Orange/OrangeLeft.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_ORANGE_RIGHT,	"../Resource/Graph/Enemy/Orange/OrangeRight.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_ORANGE_UP,	"../Resource/Graph/Enemy/Orange/OrangeUp.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_PINC_DOWN,	"../Resource/Graph/Enemy/Pinc/PincDown.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_PINC_LEFT,	"../Resource/Graph/Enemy/Pinc/PincLeft.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_PINC_RIGHT,	"../Resource/Graph/Enemy/Pinc/PincRight.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY_PINC_UP,		"../Resource/Graph/Enemy/Pinc/PincUp.png" );
	drawer->loadGraph( GRAPH_ID_TARGET,				"../Resource/Graph/Target.png" );
	drawer->loadGraph( GRAPH_ID_BACK_GROUND,		"../Resource/Graph/BackGround.png" );
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
	
	//左向き
	if ( CHIP_ID_PACMAN_1_LEFT <= id && id <= CHIP_ID_PACMAN_3_LEFT ) {
		int index = id - CHIP_ID_PACMAN_1_LEFT;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_LEFT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//右向き
	if ( CHIP_ID_PACMAN_1_RIGHT <= id && id <= CHIP_ID_PACMAN_3_RIGHT ) {
		int index = id - CHIP_ID_PACMAN_1_RIGHT;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_RIGHT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//下向き
	if ( CHIP_ID_PACMAN_1_DOWN <= id && id <= CHIP_ID_PACMAN_3_DOWN ) {
		int index = id - CHIP_ID_PACMAN_1_DOWN;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_DOWN;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//上向き
	if ( CHIP_ID_PACMAN_1_UP <= id && id <= CHIP_ID_PACMAN_3_UP ) {
		int index = id - CHIP_ID_PACMAN_1_UP;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_UP;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}

	if ( id == CHIP_ID_PACMAN_LD ) {
		int index = id - CHIP_ID_PACMAN_LD;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_LD;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}

	if ( id == CHIP_ID_PACMAN_LU ) {
		int index = id - CHIP_ID_PACMAN_LU;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_LU;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}

	if ( id == CHIP_ID_PACMAN_RD ) {
		int index = id - CHIP_ID_PACMAN_RD;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_RD;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}

	if ( id == CHIP_ID_PACMAN_RU ) {
		int index = id - CHIP_ID_PACMAN_RU;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_PACMAN_RU;
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

	//左向き
	if ( CHIP_ID_ENEMY_RED_LEFT_0 <= id && id <= CHIP_ID_ENEMY_RED_LEFT_2 ) {
		int index = id - CHIP_ID_ENEMY_RED_LEFT_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_RED_LEFT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//右向き
	if ( CHIP_ID_ENEMY_RED_RIGHT_0 <= id && id <= CHIP_ID_ENEMY_RED_RIGHT_2 ) {
		int index = id - CHIP_ID_ENEMY_RED_RIGHT_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_RED_RIGHT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//下向き
	if ( CHIP_ID_ENEMY_RED_DOWN_0 <= id && id <= CHIP_ID_ENEMY_RED_DOWN_2 ) {
		int index = id - CHIP_ID_ENEMY_RED_DOWN_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_RED_DOWN;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//上向き
	if ( CHIP_ID_ENEMY_RED_UP_0 <= id && id <= CHIP_ID_ENEMY_RED_UP_2 ) {
		int index = id - CHIP_ID_ENEMY_RED_UP_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_RED_UP;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}

	//左向き
	if ( CHIP_ID_ENEMY_ORANGE_LEFT_0 <= id && id <= CHIP_ID_ENEMY_ORANGE_LEFT_2 ) {
		int index = id - CHIP_ID_ENEMY_ORANGE_LEFT_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_ORANGE_LEFT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//右向き
	if ( CHIP_ID_ENEMY_ORANGE_RIGHT_0 <= id && id <= CHIP_ID_ENEMY_ORANGE_RIGHT_2 ) {
		int index = id - CHIP_ID_ENEMY_ORANGE_RIGHT_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_ORANGE_RIGHT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//下向き
	if ( CHIP_ID_ENEMY_ORANGE_DOWN_0 <= id && id <= CHIP_ID_ENEMY_ORANGE_DOWN_2 ) {
		int index = id - CHIP_ID_ENEMY_ORANGE_DOWN_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_ORANGE_DOWN;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//上向き
	if ( CHIP_ID_ENEMY_ORANGE_UP_0 <= id && id <= CHIP_ID_ENEMY_ORANGE_UP_2 ) {
		int index = id - CHIP_ID_ENEMY_ORANGE_UP_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_ORANGE_UP;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}

	//左向き
	if ( CHIP_ID_ENEMY_PINC_LEFT_0 <= id && id <= CHIP_ID_ENEMY_PINC_LEFT_2 ) {
		int index = id - CHIP_ID_ENEMY_PINC_LEFT_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_PINC_LEFT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//右向き
	if ( CHIP_ID_ENEMY_PINC_RIGHT_0 <= id && id <= CHIP_ID_ENEMY_PINC_RIGHT_2 ) {
		int index = id - CHIP_ID_ENEMY_PINC_RIGHT_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_PINC_RIGHT;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//下向き
	if ( CHIP_ID_ENEMY_PINC_DOWN_0 <= id && id <= CHIP_ID_ENEMY_PINC_DOWN_2 ) {
		int index = id - CHIP_ID_ENEMY_PINC_DOWN_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_PINC_DOWN;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//上向き
	if ( CHIP_ID_ENEMY_PINC_UP_0 <= id && id <= CHIP_ID_ENEMY_PINC_UP_2 ) {
		int index = id - CHIP_ID_ENEMY_PINC_UP_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_PINC_UP;
		sprite.tx = OFFSET_X + ( CHIP_SIZE + OFFSET_X ) * index;
		sprite.ty = OFFSET_Y;
	}
	//バッドアニメーション
	if ( CHIP_ID_ENEMY_BAD_B_0 <= id && id <= CHIP_ID_ENEMY_BAD_B_2 ) {
		int index = id - CHIP_ID_ENEMY_BAD_B_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_BAD_B;
		sprite.tx = ( CHIP_SIZE + OFFSET_X ) * ( index % 8 );
		sprite.ty = ( CHIP_SIZE + OFFSET_Y ) * ( index / 8 );
	}

	//バッドアニメーション
	if ( CHIP_ID_ENEMY_BAD_W_0 <= id && id <= CHIP_ID_ENEMY_BAD_W_2 ) {
		int index = id - CHIP_ID_ENEMY_BAD_W_0;
		const int OFFSET_X = 0;
		const int OFFSET_Y = 0;
		sprite.image = GRAPH_ID_ENEMY_BAD_W;
		sprite.tx = ( CHIP_SIZE + OFFSET_X ) * ( index % 8 );
		sprite.ty = ( CHIP_SIZE + OFFSET_Y ) * ( index / 8 );
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