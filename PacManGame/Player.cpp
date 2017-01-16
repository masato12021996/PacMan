#include "Player.h"
#include "Animation.h"
#include "PlayerAnimationFactory.h"
#include "Keyboard.h"
#include "MapDefine.h"
#include "Field.h"

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
const int PLAYER_RANGE = 10;

Player::Player( FieldPtr field ) {
	_field = field;
	_is_expired = true;
	_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WAIT );
	_state = STATE::STATE_WAIT;
}

Player::~Player( ) {
}

void Player::update( ) {
	InputControlDir( );//向きが変更される。
	//移動処理
	move( );
	stateUpdate( );
	animator( );//アニメーション管理
}

void Player::create( const Vector& pos ) {
	_pos = pos;
	_dir = DIR_LEFT;
	_is_expired = false;
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
	int x = _pos.x / MapParameter::CHIP_SIZE;
	int y = _pos.y / MapParameter::CHIP_SIZE;
	int on_object = _field->getFieldTarget( x, y );
	if ( on_object == Field::OBJECT_BATE ) {
		_field->setFieldTarget( x, y, Field::OBJECT_NULL );
	}
	if ( on_object == Field::OBJECT_POWER_BATE ) {
		_field->setFieldTarget( x, y, Field::OBJECT_NULL );
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
	//まず自分のいるマスを取得する
	int px = ( int )pos.x / MapParameter::CHIP_SIZE + _dir.x;
	int py = ( int )pos.y / MapParameter::CHIP_SIZE + _dir.y;
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
				if ( length < box_length + PLAYER_RANGE ) {
					result = false;
				}
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
}

void Player::animator( ) {
	if ( _state != _befor_state ) {
		//アニメーション更新
		switch ( _state ) {
			case STATE_WAIT:
				_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WAIT );
				break;
			case STATE_WALK:
				_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK );
				break;
		}
	} else {
		//アニメーションアップデート
		_animation->update( );
	}
}