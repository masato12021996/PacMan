#include "PlayStage.h"
#include "Field.h"
#include "Stage.h"
#include "Player.h"
#include "MapDefine.h"
#include <time.h>

const int CLEAR_TIME = 10;

PlayStage::PlayStage( ) {
	_field = FieldPtr( new Field( ) );
	_player = PlayerPtr( new Player( _field ) );
}

PlayStage::~PlayStage( ) {
}

void PlayStage::update( ) {
	//�N���A���ĂȂ�������X�V
	_player->update( );
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
				break;
				case Stage::OBJECT_NAME_ENEMY_ORANGE:
				break;
				case Stage::OBJECT_NAME_ENEMY_PINC:
				break;
				case Stage::OBJECT_NAME_ENEMY_RED:
				break;
			}
		}
	}
}

bool PlayStage::isEndStage( ) const {
	bool is_end = false;
	switch( _trems ) {
	case Stage::CLEAR_TREMS_ENEMY_EAT:
		break;
	case Stage::CLEAR_TREMS_FOOD_EAT:
		if( _field->isNotBate( ) ) {
			is_end = true;
		}
		break;
	case Stage::CLEAR_TREMS_OUTRUN:
		if ( _stage_time > CLEAR_TIME ) {
			is_end = true;
		}
		break;
	}
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