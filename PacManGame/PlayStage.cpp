#include "PlayStage.h"


PlayStage::PlayStage( ) {
}

PlayStage::~PlayStage( ) {
}

void PlayStage::update( ) {
	//�N���A���ĂȂ�������X�V
}

//�X�e�[�W�̐���,������
void PlayStage::create( StagePtr stage ) {
	_stage = stage;
}

bool PlayStage::isEndStage( ) const {
	bool is_end = false;
	return is_end;
}
