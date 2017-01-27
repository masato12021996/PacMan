#include "EnemyAnimationFoctory.h"
#include "EnemyBadAnimation.h"
#include "EnemyBadEndAnimation.h"
#include "EnemyWalkAnimation.h"

EnemyAnimationFoctory::EnemyAnimationFoctory( ENEMY_COLOR color ) {
	_color = color;
}

EnemyAnimationFoctory::~EnemyAnimationFoctory( ) {
}

AnimationPtr EnemyAnimationFoctory::createAnimation( STATE state ) {
	AnimationPtr animation;
	if ( state == STATE_BAD ) {
		animation = EnemyBadAnimationPtr( new EnemyBadAnimation( ) );
		return animation;
	}
	if ( state == STATE_BAD_END ) {
		animation = EnemyBadEndAnimationPtr( new EnemyBadEndAnimation( ) );
		return animation;
	}
	if ( _color == ENEMY_COLOR_RED ) {
		switch ( state ) {
		case STATE::STATE_WALK_LEFT:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_RED, EnemyWalkAnimation::WALK_DIR_LEFT ) );
			break;													   
		case STATE::STATE_WALK_RIGHT:								   
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_RED, EnemyWalkAnimation::WALK_DIR_RIGHT ) );
			break;													   
		case STATE::STATE_WALK_DOWN:								   
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_RED, EnemyWalkAnimation::WALK_DIR_DOWN ) );
			break;													   
		case STATE::STATE_WALK_UP:									   
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_RED, EnemyWalkAnimation::WALK_DIR_UP ) );
			break;
		}
	}
	if ( _color == ENEMY_COLOR_ORANGE ) {
		switch ( state ) {
		case STATE::STATE_WALK_LEFT:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_ORANGE, EnemyWalkAnimation::WALK_DIR_LEFT ) );
			break;
		case STATE::STATE_WALK_RIGHT:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_ORANGE, EnemyWalkAnimation::WALK_DIR_RIGHT ) );
			break;
		case STATE::STATE_WALK_DOWN:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_ORANGE, EnemyWalkAnimation::WALK_DIR_DOWN ) );
			break;
		case STATE::STATE_WALK_UP:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_ORANGE, EnemyWalkAnimation::WALK_DIR_UP ) );
			break;
		}
	}
	if ( _color == ENEMY_COLOR_PINC ) {
		switch ( state ) {
		case STATE::STATE_WALK_LEFT:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_PINC, EnemyWalkAnimation::WALK_DIR_LEFT ) );
			break;
		case STATE::STATE_WALK_RIGHT:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_PINC, EnemyWalkAnimation::WALK_DIR_RIGHT ) );
			break;
		case STATE::STATE_WALK_DOWN:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_PINC, EnemyWalkAnimation::WALK_DIR_DOWN ) );
			break;
		case STATE::STATE_WALK_UP:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_PINC, EnemyWalkAnimation::WALK_DIR_UP ) );
			break;
		}
	}
	if ( _color == ENEMY_COLOR_BLUE ) {
		switch ( state ) {
		case STATE::STATE_WALK_LEFT:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_BLUE, EnemyWalkAnimation::WALK_DIR_LEFT ) );
			break;
		case STATE::STATE_WALK_RIGHT:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_BLUE, EnemyWalkAnimation::WALK_DIR_RIGHT ) );
			break;
		case STATE::STATE_WALK_DOWN:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_BLUE, EnemyWalkAnimation::WALK_DIR_DOWN ) );
			break;
		case STATE::STATE_WALK_UP:
			animation = EnemyWalkAnimationPtr( new EnemyWalkAnimation( EnemyWalkAnimation::COLOR_BLUE, EnemyWalkAnimation::WALK_DIR_UP ) );
			break;
		}
	}
	return animation;
}
