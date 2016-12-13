#include "PlayerAnimationFactory.h"
#include "PlayerWaitAniamtion.h"

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
	}
	return animation;
}
