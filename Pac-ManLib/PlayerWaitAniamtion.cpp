#include "PlayerWaitAniamtion.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 1;
const double ANIMATION_MAX_TIME = 0.2;

PlayerWaitAniamtion::PlayerWaitAniamtion( ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ){
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_1_DOWN );
}

PlayerWaitAniamtion::~PlayerWaitAniamtion( ) {
}