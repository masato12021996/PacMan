#include "Object.h"

Object::Object( Object::TAG tag ) {
	_tag = tag;
}

Object::~Object( ) {
}

Object::TAG Object::getTag( ) const {
	return _tag;
}