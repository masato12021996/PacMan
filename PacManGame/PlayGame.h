#pragma once
#include "smart_ptr.h"
#include <array>

PTR( PlayGame );
PTR( Stage )

class PlayGame {
public:
	static const int STAGE_NUM = 30;//保存するステージの数
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
	StagePtr getPlayStage( ) const;
	PLAY_STATE getState( ) const;
private:
	void changeStage( );
private:
	PLAY_STATE _state;	 //ゲームの現在の状態
	bool _is_clear;		 //ステージのクリア判定
	int _clear_stage_num;//クリアしたステージ数の管理
	std::array< StagePtr, STAGE_NUM > _stage_list;	//保存してるステージ
};