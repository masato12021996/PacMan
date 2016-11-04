#pragma once
#include "Task.h"
#include <string>

PTR( Game );
PTR( PlayGame );

class Game : public Task {
public:
	enum GAME_STATE {
		GAME_STATE_TITILE,
		GAME_STATE_PLAY,
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
private:
	GAME_STATE _game_state;
	PlayGamePtr _play_game;
};