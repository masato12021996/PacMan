#include "EnemyBadAnimation.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 3;
const double ANIMATION_MAX_TIME = 0.2;

EnemyBadAnimation::EnemyBadAnimation( ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ) {
	setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BAD_B_0 );
	setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BAD_B_1 );
	setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BAD_B_2 );
}

EnemyBadAnimation::~EnemyBadAnimation( ) {
}
