#include "Enemy.h"
#include "Animation.h"
#include "MapDefine.h"
#include "Game.h"
#include "PlayGame.h"
#include "PlayStage.h"
#include "Player.h"
#include "Field.h"
#include "EnemyBadAnimation.h"
#include "EnemyBadEndAnimation.h"

const int MAP_TOP_BORDER = 0;
const int MAP_BOTTOM_BORDER = MAP_TOP_BORDER + MapParameter::MAP_SIZE_Y * MapParameter::CHIP_SIZE;
const int MAP_LEFT_BORDER = 0;
const int MAP_RIGHT_BORDER = MAP_LEFT_BORDER + MapParameter::MAP_SIZE_X * MapParameter::CHIP_SIZE;
const int MAP_OUT_BORDER = 4;
const double ENEMY_RANGE = 10;

const double SPEED = 1.0;

const int BAD_END_TIME = 180;
const int BAD_LIMIT_TIME = BAD_END_TIME + 60;

Enemy::Enemy( const Vector& pos  ) {
	_pos = pos;
	_dir = Vector( 1, 0, 0 );
	_is_expired = true;
	_is_bad = false;
	_animation;
	GamePtr game = Game::getTask( );
	PlayGamePtr play_game = game->getPlayGame( );
	PlayStagePtr play_stage = play_game->getPlayStage( );
	_field = play_stage->getField( );
	_bad_timer = 0;
}

Enemy::~Enemy( ) {
}

void Enemy::update( ) {
	if ( _is_bad ) {
		badRun( );//逃げる
	} else {
		actor( );
	}
	if ( canMove( _pos ) ) {
		move( );
	}
	if ( _is_bad && !_before_bad ) {
		_animation = EnemyBadAnimationPtr( new EnemyBadAnimation( ) );//青いやつ
		_bad_timer = 0;
	}
	if ( _is_bad ) {
		_bad_timer++;
	}
	if ( _bad_timer > BAD_END_TIME ) {
		_animation = EnemyBadEndAnimationPtr( new EnemyBadEndAnimation( ) );//青い白いやつ
	}
	if ( _bad_timer > BAD_LIMIT_TIME ) {
		_is_bad = false;
	}

	_animation->update( );
	_before_bad = _is_bad;
}

Vector Enemy::getPos( ) const {
	return _pos;
}

Vector Enemy::getDir( ) const {
	return _dir;
}

void Enemy::setDir( const Vector& dir ) {
	_dir = dir;
}

void Enemy::setBad( ) {
	_is_bad = true;
}

AnimationPtr Enemy::getAnimation( ) const {
	return _animation;
}

void Enemy::setAnimation( AnimationPtr animation ) {
	if ( _is_bad ) {
		return;
	}
	_animation = animation;
}

bool Enemy::isExpired( ) const {
	return _is_expired;
}

bool Enemy::onMap( Vector pos ) {
	bool result = false;
	int x = ( int )pos.x;
	int y = ( int )pos.y;
	if ( MAP_LEFT_BORDER <= x && x <= MAP_RIGHT_BORDER ) {
		if ( MAP_TOP_BORDER <= y && y <= MAP_BOTTOM_BORDER ) {
			result = true;
		}
	}
	return result;
}

bool Enemy::canMove( Vector pos ) {
	bool result = true;
	//まず自分のいるマスを取得する
	int px = ( int )pos.x / MapParameter::CHIP_SIZE + ( int )_dir.x;
	int py = ( int )pos.y / MapParameter::CHIP_SIZE + ( int )_dir.y;
	//そのあと進行方向のマスとそのうえ側のマスと下側のマスを取得する
	for ( int i = 0; i < 3; i++ ) {
		int x = px;
		int y = py;
		if ( _dir.x > 0 ) {
			y += i - 1;
		} else {
			x += i - 1;
		}
		if ( onMap( Vector( x * MapParameter::CHIP_SIZE, y * MapParameter::CHIP_SIZE ) ) ) {
			//各マスが壁か判断する。
			int object_id = _field->getFieldTarget( x, y );
			if ( object_id == Field::OBJECT_WALL ){
				double bsx = x * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2;
				double bsy = y * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2;
				Vector bsp = Vector( bsx, bsy );
				Vector diff = bsp - pos;
				//その後正方形と円のあたり判定をする
				double box_length = MapParameter::CHIP_SIZE / 2;
				//方法としては正方形と円のベクトルを取りその角度を利用して当たりそうな正方形の辺の長さを求め判定する。
				double length = diff.getLength( );
				if ( length < box_length + ENEMY_RANGE ) {
					result = false;
				}
			}
		}
	}
	return result;
}

void Enemy::move( ) {
	double speed = SPEED;
	if ( _is_bad ) {
		speed = speed / 2;
	}
	_pos += _dir * speed;
}

void Enemy::badRun( ) {
	GamePtr game = Game::getTask( );
	PlayGamePtr play_game = game->getPlayGame( );
	PlayStagePtr play_stage = play_game->getPlayStage( );
	PlayerPtr player = play_stage->getPlayer( );

	Vector move_dir = player->getPos( ) - getPos( );
	if ( move_dir.x > move_dir.y ) {
		move_dir = Vector( -move_dir.x, 0, 0 );
	} else {
		move_dir = Vector( 0, -move_dir.y, 0 );
	}
	setDir( move_dir );
}