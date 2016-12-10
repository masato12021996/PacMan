#include "Player.h"
#include "Animation.h"
#include "Keyboard.h"
#include "MapDefine.h"

const Vector DIR_LEFT	= Vector( -1,  0, 0 );
const Vector DIR_RIGHT	= Vector(  1,  0, 0 );
const Vector DIR_UP		= Vector(  0, -1, 0 );
const Vector DIR_DOWN	= Vector(  0,  1, 0 );

Player::Player( ) {
	_is_dead = true;
	_animation;
}

Player::~Player( ) {
}

void Player::update( ) {
	InputControlDir( );//向きが変更される。
	//移動処理
	move( );
	//アニメーションアップデート
	//_animation->update( );
}

void Player::create( const Vector& pos ) {
	_pos = pos;
	_dir = DIR_LEFT;
	_is_dead = false;
}

bool Player::isDead( ) const {
	return _is_dead;
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
	_pos += _dir.normalize( );
	posNormalize( );
}

void Player::posNormalize( ) {
	const int MAP_TOP_BORDER = MapParameter::CHIP_SIZE;
	const int MAP_BOTTOM_BORDER = MAP_TOP_BORDER + MapParameter::MAP_SIZE_Y * MapParameter::CHIP_SIZE;
	const int MAP_LEFT_BORDER = 0;
	const int MAP_RIGHT_BORDER = MAP_LEFT_BORDER + MapParameter::MAP_SIZE_X * MapParameter::CHIP_SIZE;
	int x = ( int )_pos.x;
	int y = ( int )_pos.y;
	if ( x < MAP_LEFT_BORDER ) {
		x = MAP_RIGHT_BORDER;
	}
	if ( y < MAP_TOP_BORDER ) {
		y = MAP_BOTTOM_BORDER;
	}
	if ( x > MAP_RIGHT_BORDER ) {
		x = MAP_LEFT_BORDER;
	}
	if ( y > MAP_BOTTOM_BORDER ) {
		y = MAP_TOP_BORDER;
	}
	_pos = Vector( x, y );
}