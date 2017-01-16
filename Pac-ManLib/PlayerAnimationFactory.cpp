#include "PlayerAnimationFactory.h"
#include "PlayerWaitAniamtion.h"
#include "PlayerWalkAnimation.h"

PlayerAnimationFactory::PlayerAnimationFactory( ) {
}

PlayerAnimationFactory::~PlayerAnimationFactory( ) {
}

AnimationPtr PlayerAnimationFactory::createAnimation( STATE state ) {
	AnimationPtr animation;
	switch ( state ) {
	case STATE::STATE_WAIT:
		animation = PlayerWaitAniamtionPtr( new PlayerWaitAniamtion( ) );
		break;
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
	}
	return animation;
}
