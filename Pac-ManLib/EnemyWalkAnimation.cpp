#include "EnemyWalkAnimation.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 3;
const double ANIMATION_MAX_TIME = 0.2;

EnemyWalkAnimation::EnemyWalkAnimation(  COLOR color, WALK_DIR dir ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ) {
	if ( color == COLOR_BLUE ) {
		switch( dir ) {
		case WALK_DIR_LEFT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_LEFT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_LEFT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_LEFT_2 );
			break;
		case WALK_DIR_RIGHT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_RIGHT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_RIGHT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_RIGHT_2 );
			break;
		case WALK_DIR_DOWN:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_DOWN_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_DOWN_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_DOWN_2 );
			break;
		case WALK_DIR_UP:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_UP_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_UP_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BLUE_UP_2 );
			break;
		}
	}
	if ( color == COLOR_RED ) {
		switch( dir ) {
		case WALK_DIR_LEFT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_LEFT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_LEFT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_LEFT_2 );
			break;
		case WALK_DIR_RIGHT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_RIGHT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_RIGHT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_RIGHT_2 );
			break;
		case WALK_DIR_DOWN:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_DOWN_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_DOWN_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_DOWN_2 );
			break;
		case WALK_DIR_UP:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_UP_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_UP_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_RED_UP_2 );
			break;
		}
	}
	if ( color == COLOR_ORANGE ) {
		switch( dir ) {
		case WALK_DIR_LEFT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_LEFT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_LEFT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_LEFT_2 );
			break;
		case WALK_DIR_RIGHT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_RIGHT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_RIGHT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_RIGHT_2 );
			break;
		case WALK_DIR_DOWN:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_DOWN_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_DOWN_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_DOWN_2 );
			break;
		case WALK_DIR_UP:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_UP_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_UP_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_ORANGE_UP_2 );
			break;
		}
	}
	if ( color == COLOR_PINC ) {
		switch( dir ) {
		case WALK_DIR_LEFT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_LEFT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_LEFT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_LEFT_2 );
			break;
		case WALK_DIR_RIGHT:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_RIGHT_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_RIGHT_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_RIGHT_2 );
			break;
		case WALK_DIR_DOWN:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_DOWN_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_DOWN_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_DOWN_2 );
			break;
		case WALK_DIR_UP:
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_UP_0 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_UP_1 );
			setAnimationGraph( GraphManager::CHIP_ID_ENEMY_PINC_UP_2 );
			break;
		}
	}
}

EnemyWalkAnimation::~EnemyWalkAnimation( ) {
}
