#pragma once
#include "smart_ptr.h"
#include <array>

PTR( PlayGame );
PTR( PlayStage );
PTR( Stage );

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
	PLAY_STATE getState( ) const;
	PlayStagePtr getPlayStage( ) const;
	int getClearStageNum( ) const;
	bool isEndGame( ) const;
	void reset( );
private:
	void changeStage( );
private:
	PLAY_STATE _state;		//ゲームの現在の状態
	bool _is_clear;			//ステージのクリア判定
	int _stage_index;		//現在のステージの番号
	int _clear_stage_num;	//クリアしたステージ数の管理
	std::array< StagePtr, STAGE_NUM > _stage_list;//保存してるステージ
	bool _is_end_game;
	int _redy_time;
	int _result_time;

	PlayStagePtr _play_stage;
};