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
	case STATE::STATE_WALK:
		animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( ) );
		break;
	}
	return animation;
}
