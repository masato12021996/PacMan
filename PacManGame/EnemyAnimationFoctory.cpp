#include "EnemyAnimationFoctory.h"
#include"PlayerWalkAnimation.h"

EnemyAnimationFoctory::EnemyAnimationFoctory( ENEMY_COLOR color ) {
	_color = color;
}

EnemyAnimationFoctory::~EnemyAnimationFoctory( ) {
}

AnimationPtr EnemyAnimationFoctory::createAnimation( STATE state ) {
	AnimationPtr animation;
	if ( _color == ENEMY_COLOR_RED ) {
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
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LD ) );
			break;
		case STATE::STATE_CHANGE_DIR_LU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LU ) );
			break;
		case STATE::STATE_CHANGE_DIR_RD:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RD ) );
			break;
		case STATE::STATE_CHANGE_DIR_RU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RU ) );
			break;
		}
	}
	if ( _color == ENEMY_COLOR_ORANGE ) {
		switch ( state ) {
		case STATE::STATE_WALK_LEFT:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_LEFT ) );
			break;
		case STATE::STATE_WALK_RIGHT:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_RIGHT ) );
			break;
		case STATE::STATE_WALK_DOWN:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_DOWN ) );
			break;
		case STATE::STATE_WALK_UP:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_UP ) );
			break;
		case STATE::STATE_CHANGE_DIR_LD:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LD ) );
			break;
		case STATE::STATE_CHANGE_DIR_LU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LU ) );
			break;
		case STATE::STATE_CHANGE_DIR_RD:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RD ) );
			break;
		case STATE::STATE_CHANGE_DIR_RU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RU ) );
			break;
		}
	}
	if ( _color == ENEMY_COLOR_PINC ) {
		switch ( state ) {
		case STATE::STATE_WALK_LEFT:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_LEFT ) );
			break;
		case STATE::STATE_WALK_RIGHT:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_RIGHT ) );
			break;
		case STATE::STATE_WALK_DOWN:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_DOWN ) );
			break;
		case STATE::STATE_WALK_UP:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_UP ) );
			break;
		case STATE::STATE_CHANGE_DIR_LD:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LD ) );
			break;
		case STATE::STATE_CHANGE_DIR_LU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LU ) );
			break;
		case STATE::STATE_CHANGE_DIR_RD:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RD ) );
			break;
		case STATE::STATE_CHANGE_DIR_RU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RU ) );
			break;
		}
	}
	if ( _color == ENEMY_COLOR_BLUE ) {
		switch ( state ) {
		case STATE::STATE_WALK_LEFT:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_LEFT ) );
			break;
		case STATE::STATE_WALK_RIGHT:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_RIGHT ) );
			break;
		case STATE::STATE_WALK_DOWN:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_DOWN ) );
			break;
		case STATE::STATE_WALK_UP:
			//animation = PlayerWalkAnimationPtr( new PlayerWalkAnimation( PlayerWalkAnimation::WALK_DIR_UP ) );
			break;
		case STATE::STATE_CHANGE_DIR_LD:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LD ) );
			break;
		case STATE::STATE_CHANGE_DIR_LU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_LU ) );
			break;
		case STATE::STATE_CHANGE_DIR_RD:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RD ) );
			break;
		case STATE::STATE_CHANGE_DIR_RU:
			//animation = PlayerChangeDirAnimationPtr( new PlayerChangeDirAnimation( PlayerChangeDirAnimation::CHANGE_DIR_RU ) );
			break;
		}
	}
	return animation;
}
