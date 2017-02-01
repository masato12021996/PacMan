#pragma once
#include <vector>

class Ranking {
public:
	Ranking( );
	virtual ~Ranking( );
public:
	void setClearNum( int clear_num );
	int getClearNum( int id ) const;
private:
	std::vector< int > _ranking;
	int _new_clear_num;
};

