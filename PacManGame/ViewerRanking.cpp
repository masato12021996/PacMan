#include "ViewerRanking.h"
#include "GraphManager.h"
#include "Game.h"
#include "Ranking.h"

const int RANKING_NUM = 5;

const int NUMBER_HEIGHT = 96;
const int RANKING_STRAT_POS_X = 200;
const int RANKING_STRAT_POS_Y = 200;

ViewerRanking::ViewerRanking( GraphManagerPtr graph_manager ) {
	_graph_manager = graph_manager;
}

ViewerRanking::~ViewerRanking( ) {
}

void ViewerRanking::update( ) {
	GamePtr game = Game::getTask( );
	RankingPtr ranking = game->getRanking( );
	_graph_manager->drawChip( 0, 0, GraphManager::CHIP_ID_RANKIG );
	for ( int i = 0; i < RANKING_NUM; i++ ) {
		int sx = RANKING_STRAT_POS_X;
		int sy = RANKING_STRAT_POS_Y + NUMBER_HEIGHT * i;
		GraphManager::CHIP_ID id = GraphManager::CHIP_ID_NUMBER_0;
		if ( ranking->getClearNum( i ) == ranking->getNewClearNum( ) ) {
			id = GraphManager::CHIP_ID_NUMBER_RED_0;
		}
		//ƒ‰ƒ“ƒN
		_graph_manager->drawChip( sx, sy, ( GraphManager::CHIP_ID )( id + 1 + i ) );
		//”Žš
		sx += 200;
		int first_num = ranking->getClearNum( i ) / 10;
		_graph_manager->drawChip( sx, sy, ( GraphManager::CHIP_ID )( id + first_num ) );
		sx += 64;
		int second_num = ranking->getClearNum( i ) % 10;
		_graph_manager->drawChip( sx, sy, ( GraphManager::CHIP_ID )( id + second_num ) );
	}
}
