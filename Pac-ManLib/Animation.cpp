#include "Animation.h"

const int FPS = 60;

Animation::Animation( int anim_frame, double anim_max_time ) {
	_animation_fream = anim_frame;
	_animation_max_time = anim_max_time * FPS;
}

Animation::~Animation( ) {
}

void Animation::update( ) {
	_animation_time++;
	if ( _animation_max_time < _animation_time ) {
		_animation_time = 0;
	}
}

int Animation::getAnimGraph( ) const {
	int ratio = ( int )_animation_max_time / _animation_fream;
	int index = ( int )_animation_time / ratio;
	if ( index >= _animation_fream ) {
		index = _animation_fream - 1;
	}
	return index;
}

void Animation::setAnimationGraph( int id ) {
	_animation_graph.push_back( id );
}
