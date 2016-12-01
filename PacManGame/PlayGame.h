#pragma once
#include "smart_ptr.h"
#include <array>

PTR( PlayGame );
PTR( Stage )

class PlayGame {
public:
	static const int STAGE_NUM = 20;				//�ۑ�����X�e�[�W�̐�
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
private:
	PLAY_STATE _state;		//�Q�[���̌��݂̏��
	bool _is_clear;			//�X�e�[�W�̃N���A����
	int _clear_stage_num;	//�N���A�����X�e�[�W���̊Ǘ�
	int _stage_index;		//���ݗV��ł���X�e�[�W�i���o�[
	std::array< StagePtr, STAGE_NUM > _stage_list;	//�ۑ����Ă�X�e�[�W
};