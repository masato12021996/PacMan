#pragma once
#include "smart_ptr.h"
#include <vector>

PTR( PlayGame );
PTR( Stage );
PTR( Field );

class PlayGame {
public:
	enum PLAY_STATE {
		PLAY_STATE_TITLE,
		PLAY_STATE_PLAY,
		PLAY_STATE_RESULT
	};
public:
	static const int MAX_STAGE_NUM = 10;
public:
	PlayGame( );
	virtual ~PlayGame( );
public:
	void initialize( );
	void update( );
	void addStage( StagePtr stage );
	PLAY_STATE getPlayState( ) const;
private:
	std::vector< StagePtr > _stage_list;
	StagePtr _stage;
	PLAY_STATE _play_state;
	int _clear_stage_num;
	FieldPtr _field;
};