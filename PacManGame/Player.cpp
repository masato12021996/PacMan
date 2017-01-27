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
}

Player::~Player( ) {
}

void Player::update( ) {
	_get_power_bate = false;
	InputControlDir( );//�������ύX�����B
	//�ړ�����
	move( );
	stateUpdate( );
	animator( );//�A�j���[�V�����Ǘ�
}

void Player::create( const Vector& pos ) {
	_pos = pos;
	_dir = DIR_LEFT;
	_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_LEFT );
	_state = STATE::STATE_WAIT;
	_is_expired = true;
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

	//�a�̎擾
	int x = ( int )_pos.x / MapParameter::CHIP_SIZE;
	int y = ( int )_pos.y / MapParameter::CHIP_SIZE;
	int on_object = _field->getFieldTarget( x, y );
	if ( on_object == Field::OBJECT_BATE ) {
		_field->setFieldTarget( x, y, Field::OBJECT_NULL );
	}
	if ( on_object == Field::OBJECT_POWER_BATE ) {
		_field->setFieldTarget( x, y, Field::OBJECT_NULL );
		_get_power_bate = true;
	}
	//�G�̂����蔻��
	GamePtr game = Game::getTask( );
	PlayGamePtr play_game = game->getPlayGame( );
	PlayStagePtr stage = play_game->getPlayStage( );
	for ( int i = 0; i < stage->getEnemyNum( ); i++ ) {
		EnemyPtr enemy = stage->getEnemy( i );
		Vector vec = enemy->getPos( ) - getPos( );
		if ( vec.getLength( ) < MapParameter::CHIP_SIZE ) {
			//�G�����ꂶ��Ȃ������玀��
			if ( !enemy->isBad( ) ) {
			}
			//�G�����ꂾ������|��
			if ( enemy->isBad( ) ) {
				enemy->Dead( );
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
	//�܂������̂���}�X���擾����
	int px = ( int )pos.x / MapParameter::CHIP_SIZE + ( int )_dir.x;
	int py = ( int )pos.y / MapParameter::CHIP_SIZE + ( int )_dir.y;
	//���̂��Ɛi�s�����̃}�X�Ƃ��̂������̃}�X�Ɖ����̃}�X���擾����
	for ( int i = 0; i < 3; i++ ) {
		int x = px;
		int y = py;
		if ( _dir.x > 0 ) {
			y += i - 1;
		} else {
			x += i - 1;
		}
		if ( onMap( Vector( x * MapParameter::CHIP_SIZE, y * MapParameter::CHIP_SIZE ) ) ) {
			//�e�}�X���ǂ����f����B
			int object_id = _field->getFieldTarget( x, y );
			if ( object_id == Field::OBJECT_WALL ){
				double bsx = x * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2;
				double bsy = y * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2;
				Vector bsp = Vector( bsx, bsy );
				Vector diff = bsp - pos;
				//���̌㐳���`�Ɖ~�̂����蔻�������
				double box_length = MapParameter::CHIP_SIZE / 2;
				//���@�Ƃ��Ă͐����`�Ɖ~�̃x�N�g������肻�̊p�x�𗘗p���ē����肻���Ȑ����`�̕ӂ̒��������ߔ��肷��B
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
	if ( _befor_dir != _dir || ( _befor_state == STATE_CHANGE_DIR && _animation->getAnimTime( ) < 5 ) ) {
		_state = STATE_CHANGE_DIR;
	}
}

void Player::animator( ) {
	if ( _state == STATE_WAIT || _state != _befor_state || _dir != _befor_dir ) {
		//�A�j���[�V�����X�V
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
			case STATE_CHANGE_DIR:
				//����
				if ( ( _dir == DIR_LEFT && _befor_dir == DIR_UP ) || ( _befor_dir == DIR_LEFT && _dir == DIR_UP ) ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_LEFT );
				}
				//����
				if ( ( _dir == DIR_LEFT && _befor_dir == DIR_DOWN ) || ( _befor_dir == DIR_LEFT && _dir == DIR_DOWN ) ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_RIGHT );
				}
				//�E��
				if ( ( _dir == DIR_RIGHT && _befor_dir == DIR_UP ) || ( _befor_dir == DIR_RIGHT && _dir == DIR_UP ) ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_DOWN );
				}
				//�E��
				if ( ( _dir == DIR_RIGHT && _befor_dir == DIR_DOWN ) || ( _befor_dir == DIR_RIGHT && _dir == DIR_DOWN ) ) {
					_animation = PlayerAnimationFactory::createAnimation( PlayerAnimationFactory::STATE_WALK_UP );
				}
				break;
		}
	} else {
		//�A�j���[�V�����A�b�v�f�[�g
		_animation->update( );
	}
}

bool Player::isGetPowerBate( ) const {
	return _get_power_bate;
}