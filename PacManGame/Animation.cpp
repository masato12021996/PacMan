#include "Animation.h"


Animation::Animation( int anim_frame, int anim_max_time ) {
	_animation_fream = anim_frame;
	_animation_max_time = anim_max_time;
}

Animation::~Animation( ) {
}

bool Animation::isEndAnimation( ) {
	bool result = false;
	if ( _animation_time > _animation_max_time ) {
		result = true;
	}
	return result;
}

void Animation::update( ) {
	_animation_time++;
}

int Animation::getAnimGraph( ) const {
	int ratio = _animation_max_time / _animation_fream;
	int index = _animation_time / ratio;
	if ( index > _animation_fream ) {
		index = _animation_fream;
	}
	return index;
}

void Animation::setAnimationGraph( int id ) {
	_animation_graph.push_back( id );
}
