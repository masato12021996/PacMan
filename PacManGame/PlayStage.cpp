#include "PlayStage.h"
#include "Field.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyRed.h"
#include "EnemyPinc.h"
#include "EnemyOrange.h"
#include "MapDefine.h"
#include <time.h>

const int CLEAR_TIME = 10;
const int GAMEOVER_TIME = 180;

PlayStage::PlayStage( ) {
	_field = FieldPtr( new Field( ) );
	_player = PlayerPtr( new Player( _field ) );
}

PlayStage::~PlayStage( ) {
}

void PlayStage::update( ) {
	//�N���A���ĂȂ�������X�V
	_player->update( );
	if ( !_enemies.empty( ) ) {
		for ( int i = 0; i < ( int )_enemies.size( ); i++ ) {
			if ( _enemies[ i ]->isExpired( ) ) {
				if ( _player->isGetPowerBate( ) ) {
					_enemies[ i ]->setBad( );
				}
				_enemies[ i ]->update( );
			}
		}
	}
	_stage_time = ( clock( ) - _start_time );
}

//�X�e�[�W�̐���,������
void PlayStage::create( StagePtr stage ) {
	_trems = stage->getTrems( );
	_start_time = clock( );
	_stage_time = 0;
	//���Z�b�g
	if ( !_enemies.empty( ) ) {
		_enemies.clear( );
	}
	_field->initialize( );
	//�}�b�v�N���G�C�g
	for ( int i = 0; i < MapParameter::MAP_SIZE_X; i++ ) {
		for ( int j = 0; j < MapParameter::MAP_SIZE_Y; j++ ) {
			int object = stage->getTargetCell( i, j );
			switch( object ) {
				case Stage::OBJECT_NAME_NONE:
				_field->setFieldTarget( i, j, Field::OBJECT_NULL );
				break;
				case Stage::OBJECT_NAME_WALL:
				_field->setFieldTarget( i, j, Field::OBJECT_WALL );
				break;
				case Stage::OBJECT_NAME_BATE:
				_field->setFieldTarget( i, j, Field::OBJECT_BATE ); 
				break;
				case Stage::OBJECT_NAME_POWER_BATE:
				_field->setFieldTarget( i, j, Field::OBJECT_POWER_BATE );
				break;
				case Stage::OBJECT_NAME_PLAYER:
				_player->create( Vector( i * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2, j * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2 ) );
				break;
				case Stage::OBJECT_NAME_ENEMY_BLUE:
					_enemies.push_back( EnemyRedPtr( new EnemyRed( Vector( i * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2, j * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2 ) ) ) );
				break;
				case Stage::OBJECT_NAME_ENEMY_ORANGE:
					_enemies.push_back( EnemyOrangePtr( new EnemyOrange( Vector( i * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2, j * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2 ) ) ) );
				break;
				case Stage::OBJECT_NAME_ENEMY_PINC:
					_enemies.push_back( EnemyPincPtr( new EnemyPinc( Vector( i * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2, j * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2 ) ) ) );
				break;
				case Stage::OBJECT_NAME_ENEMY_RED:
					_enemies.push_back( EnemyRedPtr( new EnemyRed( Vector( i * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2, j * MapParameter::CHIP_SIZE + MapParameter::CHIP_SIZE / 2 ) ) ) );
				break;
			}
		}
	}
}

bool PlayStage::isClearStage( ) const {
	bool is_end = false;
	switch( _trems ) {
	case Stage::CLEAR_TREMS_ENEMY_EAT:
		is_end = true;
		for ( int i = 0; i < _enemies.size( ); i++ ) {
			if ( _enemies[ i ]->isExpired( ) ) {
				is_end = false;
			}
		}
		break;
	case Stage::CLEAR_TREMS_FOOD_EAT:
		if( _field->isNotBate( ) ) {
			is_end = true;
		}
		break;
	case Stage::CLEAR_TREMS_OUTRUN:
		if ( getTime( ) > CLEAR_TIME ) {
			is_end = true;
		}
		break;
	}
	return is_end;
}

bool PlayStage::isDeadStage( ) const {
	bool is_end = false;
	switch( _trems ) {
	case Stage::CLEAR_TREMS_ENEMY_EAT:
	case Stage::CLEAR_TREMS_FOOD_EAT:
		if ( getTime( ) > GAMEOVER_TIME ) {
			is_end = true;
		}
		break;
	case Stage::CLEAR_TREMS_OUTRUN:
		break;
	}
	//�G�ɓ���������
	return is_end;
}

FieldPtr PlayStage::getField( ) const {
	return _field;
}

PlayerPtr PlayStage::getPlayer( ) const {
	return _player;
}

double PlayStage::getTime( ) const {
	return _stage_time / 1000.0;
}

int PlayStage::getTrems( ) const {
	return _trems;
}

int PlayStage::getEnemyNum( ) const {
	return _enemies.size( );
}

EnemyPtr PlayStage::getEnemy( int index ) const {
	return _enemies[ index ];
}