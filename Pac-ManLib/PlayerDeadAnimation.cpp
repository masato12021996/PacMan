#include "PlayerDeadAnimation.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 11;
const double ANIMATION_MAX_TIME = 1.1;

PlayerDeadAnimation::PlayerDeadAnimation( ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ) {
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_01 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_02 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_03 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_04 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_05 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_06 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_07 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_08 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_09 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_10 );
	setAnimationGraph( GraphManager::CHIP_ID_PACMAN_DEAD_11 );
}

PlayerDeadAnimation::~PlayerDeadAnimation( ) {
}
