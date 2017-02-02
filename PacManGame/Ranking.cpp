#include "Ranking.h"
#include <algorithm>
#include <functional>

const int RANKING_NUM = 5;

Ranking::Ranking( ) {
	_new_clear_num = 0;
	_ranking.push_back( 29 );
	_ranking.push_back( 25 );
	_ranking.push_back( 20 );
	_ranking.push_back( 18 );
	_ranking.push_back( 15 );
}

Ranking::~Ranking( ) {
}

void Ranking::setClearNum( int clear_num ) {
	_new_clear_num = clear_num;
	_ranking.push_back( clear_num );
	std::sort(_ranking.begin(),_ranking.end(),std::greater<int>());//~‡ƒ\[ƒg
	_ranking.erase( _ranking.begin()  + RANKING_NUM );
}

int Ranking::getClearNum( int id ) const {
	return _ranking[ id ];
}

int Ranking::getNewClearNum( ) const {
	return _new_clear_num;
}