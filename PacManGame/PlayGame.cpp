#include "PlayGame.h"
#include "Stage.h"

const std::string STAGE_PASS[ PlayGame::STAGE_NUM ] {
	"../Resource/StageData/Enemyeat���.stg",//00
	"../Resource/StageData/Enemyeat���.stg",//01
	"../Resource/StageData/Enemyeat���.stg",//02
	"../Resource/StageData/Enemyeat���.stg",//03
	"../Resource/StageData/Enemyeat���.stg",//04
	"../Resource/StageData/Enemyeat���.stg",//05
	"../Resource/StageData/Enemyeat���.stg",//06
	"../Resource/StageData/Enemyeat���.stg",//07
	"../Resource/StageData/Enemyeat���.stg",//08
	"../Resource/StageData/Enemyeat���.stg",//09
	"../Resource/StageData/Enemyeat���.stg",//10
	"../Resource/StageData/Enemyeat���.stg",//11
	"../Resource/StageData/Enemyeat���.stg",//12
	"../Resource/StageData/Enemyeat���.stg",//13
	"../Resource/StageData/Enemyeat���.stg",//14
	"../Resource/StageData/Enemyeat���.stg",//15
	"../Resource/StageData/Enemyeat���.stg",//16
	"../Resource/StageData/Enemyeat���.stg",//17
	"../Resource/StageData/Enemyeat���.stg",//18
	"../Resource/StageData/Enemyeat���.stg" //20
	"../Resource/StageData/Enemyeat���.stg" //21
	"../Resource/StageData/Enemyeat���.stg" //22
	"../Resource/StageData/Enemyeat���.stg" //23
	"../Resource/StageData/Enemyeat���.stg" //24
	"../Resource/StageData/Enemyeat���.stg" //25
	"../Resource/StageData/Enemyeat���.stg" //26
	"../Resource/StageData/Enemyeat���.stg" //27
	"../Resource/StageData/Enemyeat���.stg" //28
	"../Resource/StageData/Enemyeat���.stg" //29
};

PlayGame::PlayGame( ) {
	_state = PLAY_STATE_READY;
	_clear_stage_num = 0;
	_is_clear = false;

	//�X�e�[�W�̓ǂݍ���
	for( int i = 0; i < STAGE_NUM; i++ ) {
		FILE *fp;
		errno_t err;
		err = fopen_s( &fp, STAGE_PASS[ i ].c_str( ), "rb" );
		if ( err == 0 ) {
			StagePtr stage;
			fwrite( stage.get( ), sizeof( Stage ), 1, fp );
			fclose( fp );
			_stage_list[ i ] = stage;
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
		//���y�Đ���
			//�N���A�����\��
		//�Đ��I��
			_state = PLAY_STATE_PLAY;//�X�e�[�g�؂�ւ�
		break;
		case PLAY_STATE_PLAY:
		//�Q�[�������X�V
		//�Q�[���I������
			_state = PLAY_STATE_RESULT;//�X�e�[�g�X�V
		break;
		case PLAY_STATE_RESULT:
		//���U���g�\��
			//�Q�[����ʕ\��
			//���U���g�����\��
		//���U���g�I����
			changeStage( );//�X�e�[�W�؂�ւ�
			_state = PLAY_STATE_READY;//�X�e�[�g�؂�ւ�
		break;
	}
}

void PlayGame::changeStage( ) {
	_clear_stage_num++;
	while ( _stage_list[ _clear_stage_num ] == NULL ) {
		_clear_stage_num++;
	}
}

StagePtr PlayGame::getPlayStage( ) const {
	return _stage_list[ _clear_stage_num ];
}

PlayGame::PLAY_STATE PlayGame::getState( ) const {
	return _state;
}