#pragma once
#include "Task.h"
#include <string>

PTR( Game );
PTR( Title );
PTR( PlayGame );
PTR( Result );

class Game : public Task {
public:
	enum GAME_STATE {
		GAME_STATE_TITLE,
		GAME_STATE_PLAY,
		GAME_STATE_RESULT,
		GAME_STATE_MAX
	};
public:
	static GamePtr getTask( );
	static std::string getTag( ) { return "GAME"; };
public:
	Game( );
	virtual ~Game( );
public:
	void initialize( );
	void update( );
	GAME_STATE getGameState( ) const;
	TitlePtr getTitle( ) const;
	PlayGamePtr getPlayGame( ) const;
private:
	GAME_STATE _game_state;
	PlayGamePtr _play_game;
	TitlePtr _title;
	bool _reset_flag;
};