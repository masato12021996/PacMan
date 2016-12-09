#pragma once
#include "smart_ptr.h"
#include <vector>

PTR( Animation );

class Animation {
public:
	Animation( int anim_frame, int anim_max_time );
	virtual ~Animation( );
public:
	void update( );
	int getAnimGraph( ) const;
	bool isEndAnimation( );
protected:
	void setAnimationGraph( int id );
private:
	int _animation_fream;
	int _animation_max_time;
	int _animation_time;
	std::vector< int > _animation_graph;
};