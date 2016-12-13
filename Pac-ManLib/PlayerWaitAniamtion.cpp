#include "PlayerWaitAniamtion.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 3;
const int ANIMATION_MAX_TIME = 1;

PlayerWaitAniamtion::PlayerWaitAniamtion( ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ){
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_1 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_2 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_3 );
}

PlayerWaitAniamtion::~PlayerWaitAniamtion( ) {
}
