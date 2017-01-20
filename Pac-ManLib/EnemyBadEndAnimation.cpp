#include "EnemyBadEndAnimation.h"
#include "GraphManager.h"

const int ANIMATION_FREAM = 3;
const double ANIMATION_MAX_TIME = 0.2;

EnemyBadEndAnimation::EnemyBadEndAnimation( ) :
Animation( ANIMATION_FREAM, ANIMATION_MAX_TIME ) {
	setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BAD_W_0 );
	setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BAD_B_1 );
	setAnimationGraph( GraphManager::CHIP_ID_ENEMY_BAD_W_2 );
}

EnemyBadEndAnimation::~EnemyBadEndAnimation()
{
}
