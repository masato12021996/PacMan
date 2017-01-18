#include "PlayerAnimationFactory.h"
#include "PlayerWalkAnimation.h"
#include "PlayerChangeDirAnimation.h"

PlayerAnimationFactory::PlayerAnimationFactory( ) {
}

PlayerAnimationFactory::~PlayerAnimationFactory( ) {
}

AnimationPtr PlayerAnimationFactory::createAnimation( STATE state ) {
	AnimationPtr animation;
	switch ( state ) {
	case STATE::STATE_WALK_LEFT:
		animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_LEFT ) );
		break;
	case STATE::STATE_WALK_RIGHT:
		animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_RIGHT ) );
		break;
	case STATE::STATE_WALK_DOWN:
		animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_DOWN ) );
		break;
	case STATE::STATE_WALK_UP:
		animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_UP ) );
		break;
	case STATE::STATE_CHANGE_DIR_LD:
		animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LD ) );
		break;
	case STATE::STATE_CHANGE_DIR_LU:
		animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LU ) );
		break;
	case STATE::STATE_CHANGE_DIR_RD:
		animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RD ) );
		break;
	case STATE::STATE_CHANGE_DIR_RU:
		animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RU ) );
		break;
	}
	return animation;
}
