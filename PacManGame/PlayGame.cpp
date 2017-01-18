#include "PlayGame.h"
#include "Stage.h"
#include "PlayStage.h"

const std::string STAGE_PASS[ PlayGame::STAGE_NUM ] {
	"../Resource/StageData/Stage_01.stg",
	"../Resource/StageData/Stage_02.stg",
	"../Resource/StageData/Stage_03.stg",
	"../Resource/StageData/Stage_04.stg",
	"../Resource/StageData/Stage_05.stg",
	"../Resource/StageData/Stage_06.stg",
	"../Resource/StageData/Stage_07.stg",
	"../Resource/StageData/Stage_08.stg",
	"../Resource/StageData/Stage_09.stg",
	"../Resource/StageData/Stage_10.stg",
	"../Resource/StageData/Stage_11.stg",
	"../Resource/StageData/Stage_12.stg",
	"../Resource/StageData/Stage_13.stg",
	"../Resource/StageData/Stage_14.stg",
	"../Resource/StageData/Stage_15.stg",
	"../Resource/StageData/Stage_16.stg",
	"../Resource/StageData/Stage_17.stg",
	"../Resource/StageData/Stage_18.stg",
	"../Resource/StageData/Stage_19.stg",
	"../Resource/StageData/Stage_20.stg",
	"../Resource/StageData/Stage_21.stg",
	"../Resource/StageData/Stage_22.stg",
	"../Resource/StageData/Stage_23.stg",
	"../Resource/StageData/Stage_24.stg",
	"../Resource/StageData/Stage_25.stg",
	"../Resource/StageData/Stage_26.stg",
	"../Resource/StageData/Stage_27.stg",
	"../Resource/StageData/Stage_28.stg",
	"../Resource/StageData/Stage_29.stg",
	"../Resource/StageData/Stage_30.stg"
};

PlayGame::PlayGame( ) {
	_play_stage = PlayStagePtr( new PlayStage( ) );

	_state = PLAY_STATE_READY;
	_clear_stage_num = 0;
	_stage_index = 0;
	_is_clear = false;

	//�X�e�[�W�̓ǂݍ���
	for( int i = 0; i < STAGE_NUM; i++ ) {
		FILE *fp;
		errno_t err;
		err = fopen_s( &fp, STAGE_PASS[ i ].c_str( ), "rb" );
		if ( err == 0 ) {
			Stage stage;
			fread( &stage, sizeof( Stage ), 1, fp );
			fclose( fp );
			_stage_list[ i ] = StagePtr( new Stage( stage ) );
		} else {
			_stage_list[ i ] = NULL;
		}
	}
}

PlayGame::~PlayGame( ) {
}

void PlayGame::update( ) {
	switch ( _state ) {
		case PLAY_STATE_READY:
		//��������
			//���y�Đ��J�n
			//������
			_play_stage->create( _stage_list[ _stage_index ] );
		//���y�Đ���
			//�N���A�����\��
		//�Đ��I��
			_state = PLAY_STATE_PLAY;//�X�e�[�g�؂�ւ�
		break;
		case PLAY_STATE_PLAY:
		//�Q�[�������X�V
		_play_stage->update( );
		//�Q�[���I������
		if ( _play_stage->isClearStage( ) || _play_stage->isDeadStage( ) ) {
			_state = PLAY_STATE_RESULT;//�X�e�[�g�X�V
		}
		break;
		case PLAY_STATE_RESULT:
		//���U���g�\��
			//�Q�[����ʕ\��
			//���U���g�����\��
		//���U���g�I����
			//�N���A�����ꍇ
			if ( _play_stage->isClearStage( ) ) {
				changeStage( );//�X�e�[�W�؂�ւ�
				_state = PLAY_STATE_READY;//�X�e�[�g�؂�ւ�
			}
			//�Q�[���I�[�o�[
			if ( _play_stage->isDeadStage( ) ) {
			}
		break;
	}
}

void PlayGame::changeStage( ) {
	_stage_index++;
	while ( _stage_index < STAGE_NUM && _stage_list[ _stage_index ] == NULL ) {
		_stage_index++;
	}
	_clear_stage_num++;
}

PlayGame::PLAY_STATE PlayGame::getState( ) const {
	return _state;
}

PlayStagePtr PlayGame::getPlayStage( ) const {
	return _play_stage;
}

int PlayGame::getClearStageNum( ) const {
	return _clear_stage_num;
}