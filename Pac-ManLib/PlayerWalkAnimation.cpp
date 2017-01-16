#include "PlayerWalkAnimation.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 3;
const double ANIMATION_MAX_TIME = 0.2;

PlayerWalkAnimation::PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR dir ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ) {
	switch( dir ) {
	case WALK_DIR_LEFT:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_1_LEFT );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_2_LEFT );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_3_LEFT );
		break;
	case WALK_DIR_RIGHT:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_1_RIGHT );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_2_RIGHT );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_3_RIGHT );
		break;
	case WALK_DIR_DOWN:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_1_DOWN );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_2_DOWN );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_3_DOWN );
		break;
	case WALK_DIR_UP:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_1_UP );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_2_UP );
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_3_UP );
		break;
	}
}

PlayerWalkAnimation::~PlayerWalkAnimation( ) {
}
