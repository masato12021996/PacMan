#pragma once
#include "smart_ptr.h"
#include <array>

PTR( PlayGame );
PTR( PlayStage );
PTR( Stage );

class PlayGame {
public:
	static const int STAGE_NUM = 30;//�ۑ�����X�e�[�W�̐�
	enum PLAY_STATE {
		PLAY_STATE_READY,
		PLAY_STATE_PLAY,
		PLAY_STATE_RESULT
	};
public:
	PlayGame( );
	~PlayGame( );
public:
	void update( );
	PLAY_STATE getState( ) const;
	PlayStagePtr getPlayStage( ) const;
	int getClearStageNum( ) const;
	bool isEndGame( ) const;
	void reset( );
private:
	void changeStage( );
private:
	PLAY_STATE _state;		//�Q�[���̌��݂̏��
	bool _is_clear;			//�X�e�[�W�̃N���A����
	int _stage_index;		//���݂̃X�e�[�W�̔ԍ�
	int _clear_stage_num;	//�N���A�����X�e�[�W���̊Ǘ�
	std::array< StagePtr, STAGE_NUM > _stage_list;//�ۑ����Ă�X�e�[�W
	bool _is_end_game;
	int _redy_time;
	int _result_time;

	PlayStagePtr _play_stage;
};