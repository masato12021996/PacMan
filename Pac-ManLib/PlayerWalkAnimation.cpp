#include "PlayerWalkAnimation.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 3;
const double ANIMATION_MAX_TIME = 0.2;

PlayerWalkAnimation::PlayerWalkAnimation( ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ) {
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_1 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_2 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_3 );
}

PlayerWalkAnimation::~PlayerWalkAnimation( ) {
}
