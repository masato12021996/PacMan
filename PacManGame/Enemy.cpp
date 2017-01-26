#include "Enemy.h"
#include "Animation.h"
#include "MapDefine.h"
#include "Game.h"
#include "PlayGame.h"
#include "PlayStage.h"
#include "Player.h"
#include "Field.h"
#include "EnemyAnimationFoctory.h"

const int MAP_TOP_BORDER = 0;
const int MAP_BOTTOM_BORDER = MAP_TOP_BORDER + MapParameter::MAP_SIZE_Y * MapParameter::CHIP_SIZE;
const int MAP_LEFT_BORDER = 0;
const int MAP_RIGHT_BORDER = MAP_LEFT_BORDER + MapParameter::MAP_SIZE_X * MapParameter::CHIP_SIZE;
const int MAP_OUT_BORDER = 4;
const double ENEMY_RANGE = 10;

const Vector DIR_LEFT	= Vector( -1,  0, 0 );
const Vector DIR_RIGHT	= Vector(  1,  0, 0 );
const Vector DIR_UP		= Vector(  0, -1, 0 );
const Vector DIR_DOWN	= Vector(  0,  1, 0 );
const double SPEED = 2;

const int BAD_END_TIME = 180;
const int BAD_LIMIT_TIME = BAD_END_TIME + 60;

Enemy::Enemy( const Vector& pos,Enemy::COLOR color  ) {
	_pos = pos;
	_dir = Vector( 1, 0, 0 );
	_is_expired = true;
	_is_bad = false;
	_bad_timer = 0;
	_state = STATE_BAD;
	//_state = STATE_WALK;

	GamePtr game = Game::getTask( );
	PlayGamePtr play_game = game->getPlayGame( );
	PlayStagePtr play_stage = play_game->getPlayStage( );
	_field = play_stage->getField( );
	_player = play_stage->getPlayer( );

	switch ( color ) {
		case COLOR_RED:
			_anim_factory = EnemyAnimationFoctoryPtr( new EnemyAnimationFoctory( EnemyAnimationFoctory::ENEMY_COLOR_RED ) );
			break;
		case COLOR_BLUE:
			_anim_factory = EnemyAnimationFoctoryPtr( new EnemyAnimationFoctory( EnemyAnimationFoctory::ENEMY_COLOR_BLUE ) );
			break;
		case COLOR_PINC:
			_anim_factory = EnemyAnimationFoctoryPtr( new EnemyAnimationFoctory( EnemyAnimationFoctory::ENEMY_COLOR_PINC ) );
			break;
		case COLOR_ORANGE:
			_anim_factory = EnemyAnimationFoctoryPtr( new EnemyAnimationFoctory( EnemyAnimationFoctory::ENEMY_COLOR_ORANGE ) );
			break;
	}
	_animation = _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_BAD );
}

Enemy::~Enemy( ) {
}

void Enemy::update( ) {
	//向き変更
	bool on_center = ( int )_pos.x % MapParameter::CHIP_SIZE == MapParameter::CHIP_SIZE / 2 && ( int )_pos.y % MapParameter::CHIP_SIZE == MapParameter::CHIP_SIZE / 2;
	if ( on_center ) {
		if ( _state == STATE_BAD || _state == STATE_BAD_END ) {
			badRun( );//逃げる
		} else {
			actor( );
		}
	}
	//移動処理
	move( );
	stateUpdate( );
	animator( );
}

void Enemy::stateUpdate( ) {
	_before_state = _state;
	_state = STATE_WALK;

	if ( _before_state != STATE_BAD && _before_state != STATE_BAD_END && _is_bad ) {
		_bad_timer = 0;
		_state = STATE_BAD;
	}
	if ( _before_state == STATE_BAD ) {
		//_bad_timer++;
		_state = STATE_BAD;
	}
	if ( _before_state == STATE_BAD_END ) {
		_bad_timer++;
		_state = STATE_BAD_END;
	}
	if ( _bad_timer > BAD_END_TIME ) {
		_state = STATE_BAD_END;
	}
	if ( _bad_timer > BAD_LIMIT_TIME ) {
		_state = STATE_WALK;
	}
	_is_bad = false;
}

void Enemy::animator( ) {
	if ( _state != _before_state || _dir != _before_dir ) {
		//アニメーション更新
		switch ( _state ) {
			case STATE_WALK:
				if ( _dir == DIR_LEFT ) {
					_animation = _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_WALK_LEFT );
				}
				if ( _dir == DIR_RIGHT ) {
					_animation = _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_WALK_RIGHT );
				}
				if ( _dir == DIR_DOWN ) {
					_animation = _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_WALK_DOWN );
				}
				if ( _dir == DIR_UP ) {
					_animation = _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_WALK_UP );
				}
				break;
			case STATE_BAD:
				_animation = _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_BAD );
				break;
			case STATE_BAD_END:
				_animation = _anim_factory->createAnimation( EnemyAnimationFoctory::STATE_BAD_END );
				break;
		}
	} else {
		//アニメーションアップデート
		_animation->update( );
	}
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
	Vector target = _player->getPos( );
	const Vector DIR[ 4 ] = {
		DIR_LEFT, 
		DIR_RIGHT,
		DIR_UP,
		DIR_DOWN
	};
	int min_root = 100000;
	int key = -1;
	for ( int i = 0; i < 4; i++ ) {
		Vector next_pos = _pos + DIR[ i ];
		int root_num = _field->getRootNum( target.x / MapParameter::CHIP_SIZE, target.y / MapParameter::CHIP_SIZE, next_pos.x / MapParameter::CHIP_SIZE, next_pos.y  / MapParameter::CHIP_SIZE );
		if ( min_root > root_num && root_num > 0 ) {
			key = i;
			min_root = root_num;
		}
	}
	if ( key >= 0 ) {
		Vector move_dir = DIR[ key ];
		setDir( move_dir.normalize( ) );
	}
}

Vector Enemy::getPlayerPos( ) const {
	return _player->getPos( );
}

Vector Enemy::getPlayerDir( ) const {
	return _player->getDir( );
}

FieldPtr Enemy::getField( ) const {
	return _field;
}