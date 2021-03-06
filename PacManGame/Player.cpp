#include "Player.h"
#include "Animation.h"
#include "PlayerAnimationFactory.h"
#include "Keyboard.h"
#include "MapDefine.h"
#include "Field.h"
#include "Game.h"
#include "PlayGame.h"
#include "PlayStage.h"
#include "Enemy.h"
#include "Sound.h"

const int MAP_TOP_BORDER = 0;
const int MAP_BOTTOM_BORDER = MAP_TOP_BORDER + MapParameter::MAP_SIZE_Y * MapParameter::CHIP_SIZE;
const int MAP_LEFT_BORDER = 0;
const int MAP_RIGHT_BORDER = MAP_LEFT_BORDER + MapParameter::MAP_SIZE_X * MapParameter::CHIP_SIZE;
const int MAP_OUT_BORDER = 4;

const Vector DIR_LEFT	= Vector( -1,  0, 0 );
const Vector DIR_RIGHT	= Vector(  1,  0, 0 );
const Vector DIR_UP		= Vector(  0, -1, 0 );
const Vector DIR_DOWN	= Vector(  0,  1, 0 );
const double SPEED = 2;
const int PLAYER_RANGE = 16;

Player::Player( FieldPtr field ) {
	_field = field;
}

Player::~Player( ) {
}

void Player::update( ) {
	_get_power_bate = false;
	if ( _is_expired ) {
		InputControlDir( );//向きが変更される。
		//移動処理
		move( );
	}
	stateUpdate( );
	animator( );//アニメーション管理
}

void Player::create( const Vector& pos ) {
	_pos = pos;
	_dir = DIR_LEFT;
	_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_LEFT );
	_state = STATE::STATE_WAIT;
	_is_expired = true;
	_is_dead = false;
}

bool Player::isExpired( ) const {
	return _is_expired;
}

Vector Player::getPos( ) const {
	return _pos;
}

Vector Player::getDir( ) const {
	return _dir;
}

AnimationPtr Player::getAnimation( ) const {
	return _animation;
}

void Player::InputControlDir( ) {
	_befor_dir = _dir;
	KeyboardPtr keyboad = Keyboard::getTask( );
	if ( keyboad->isPushKey( "ARROW_LEFT" ) ) {
		_dir = DIR_LEFT;
	}
	if ( keyboad->isPushKey( "ARROW_RIGHT" ) ) {
		_dir = DIR_RIGHT;
	}
	if ( keyboad->isPushKey( "ARROW_UP" ) ) {
		_dir = DIR_UP;
	}
	if ( keyboad->isPushKey( "ARROW_DOWN" ) ) {
		_dir = DIR_DOWN;
	}
}

void Player::move( ) {
	_befor_pos = _pos;
	if ( canMove( _pos ) ) {
		_pos+= _dir * SPEED;
	}
	posNormalize( );

	//餌の取得
	int x = ( int )_pos.x / MapParameter::CHIP_SIZE;
	int y = ( int )_pos.y / MapParameter::CHIP_SIZE;
	int on_object = _field->getFieldTarget( x, y );
	SoundPtr sound = Sound::getTask( );
	if ( on_object == Field::OBJECT_BATE ) {
		_field->setFieldTarget( x, y, Field::OBJECT_NULL );
		sound->playSE( "eating_cokkie.wav" );
	}
	if ( on_object == Field::OBJECT_POWER_BATE ) {
		_field->setFieldTarget( x, y, Field::OBJECT_NULL );
		_get_power_bate = true;
		sound->playSE( "eating_cokkie.wav" );
	}
	//敵のあたり判定
	GamePtr game = Game::getTask( );
	PlayGamePtr play_game = game->getPlayGame( );
	PlayStagePtr stage = play_game->getPlayStage( );
	for ( int i = 0; i < stage->getEnemyNum( ); i++ ) {
		EnemyPtr enemy = stage->getEnemy( i );
		Vector vec = enemy->getPos( ) - getPos( );
		if ( vec.getLength( ) < MapParameter::CHIP_SIZE ) {
			//敵がやられじゃなかったら死ぬ
			if ( !enemy->isBad( ) ) {
				_is_expired = false;
				sound->stopBGM( );
				sound->playSE( "miss.wav" );
			}
			//敵がやられだったら倒す
			if ( enemy->isBad( ) && enemy->isExpired( ) ) {
				enemy->Dead( );
				sound->playSE( "eating_ghost.wav" );
			}
		}
	}
}

void Player::posNormalize( ) {
	int x = ( int )_pos.x;
	int y = ( int )_pos.y;

	if ( x < MAP_LEFT_BORDER - MAP_OUT_BORDER ) {
		x = MAP_RIGHT_BORDER + MAP_OUT_BORDER;
	}
	if ( x > MAP_RIGHT_BORDER + MAP_OUT_BORDER ) {
		x = MAP_LEFT_BORDER - MAP_OUT_BORDER;
	}
	if ( x % MapParameter::CHIP_SIZE != MapParameter::CHIP_SIZE / 2 && _dir.y != 0 ) {
		x = x / MapParameter::CHIP_SIZE * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2;
	}
	if ( y % MapParameter::CHIP_SIZE != MapParameter::CHIP_SIZE / 2 && _dir.x != 0 ) {
		y = y / MapParameter::CHIP_SIZE * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2;
	}
	_pos = Vector( x, y );
}

bool Player::onMap( Vector pos ) {
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

bool Player::canMove( Vector pos ) {
	bool result = true;
	//まず自分のいる1こさきマスを取得する
	int x = ( int )( pos.x / MapParameter::CHIP_SIZE + _dir.normalize( ).x );
	int y = ( int )( pos.y / MapParameter::CHIP_SIZE + _dir.normalize( ).y );
	if ( onMap( Vector( x * MapParameter::CHIP_SIZE, y * MapParameter::CHIP_SIZE ) ) ) {
		//各マスが壁か判断する。
		if ( y == 12 && x == 30 ) {
			return result;
		}
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
			if ( length < box_length + PLAYER_RANGE ) {
				result = false;
			}
		}
	}
	return result;
}

void Player::stateUpdate( ) {
	_befor_state = _state;
	_state = STATE_WAIT;
	bool movement = ( _befor_pos - _pos ).getLength( ) > 0;
	if ( movement ) {
		_state = STATE_WALK;
	}
	if ( !_is_expired ) {
		_state = STATE_DEAD;
	}
	if ( _befor_state == STATE_DEAD && _animation->getAnimTime( ) > 60 ) {
		_is_dead = true;
	}
}

void Player::animator( ) {
	if ( _state == STATE_WAIT || _state != _befor_state || _dir != _befor_dir ) {
		//アニメーション更新
		switch ( _state ) {
			case STATE_WAIT:
				break;
			case STATE_WALK:
				if ( _dir == DIR_LEFT ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_LEFT );
				}
				if ( _dir == DIR_RIGHT ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_RIGHT );
				}
				if ( _dir == DIR_DOWN ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_DOWN );
				}
				if ( _dir == DIR_UP ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_UP );
				}
				break;
			case STATE_DEAD:
				_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_DEAD );
				break;
		}
	} else {
		//アニメーションアップデート
		_animation->update( );
	}
}

bool Player::isGetPowerBate( ) const {
	return _get_power_bate;
}

bool Player::isDead( ) const {
	return _is_dead;
}