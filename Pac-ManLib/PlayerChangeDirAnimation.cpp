#include "PlayerChangeDirAnimation.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 1;
const double ANIMATION_MAX_TIME = 0.2;

PlayerChangeDirAnimation::PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR dir ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ) {
	switch( dir ) {
	case CHANGE_DIR_LD:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_LD );
		break;
	case CHANGE_DIR_LU:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_LU );
		break;
	case CHANGE_DIR_RD:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_RD );
		break;
	case CHANGE_DIR_RU:
		setAnimationGraph( GraphManager::CHIP_ID_PACMAN_RU );
		break;
	}
}


PlayerChangeDirAnimation::~PlayerChangeDirAnimation()
{
}
