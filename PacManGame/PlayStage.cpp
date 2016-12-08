#include "PlayStage.h"
#include "Field.h"
#include "Stage.h"
#include "MapDefine.h"

PlayStage::PlayStage( ) {
	_field = FieldPtr( new Field( ) );

}

PlayStage::~PlayStage( ) {
}

void PlayStage::update( ) {
	//クリアしてなかったら更新
}

//ステージの制作,初期化
void PlayStage::create( StagePtr stage ) {
	//リセット
	if ( !_enemies.empty( ) ) {
		_enemies.clear( );
	}
	//更新
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
	return is_end;
}

FieldPtr PlayStage::getField( ) const {
	return _field;
}
