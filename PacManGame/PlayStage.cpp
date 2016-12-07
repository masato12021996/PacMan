#include "PlayStage.h"


PlayStage::PlayStage( ) {
}

PlayStage::~PlayStage( ) {
}

void PlayStage::update( ) {
	//クリアしてなかったら更新
}

//ステージの制作,初期化
void PlayStage::create( StagePtr stage ) {
	_stage = stage;
}

bool PlayStage::isEndStage( ) const {
	bool is_end = false;
	return is_end;
}
