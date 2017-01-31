#include "Title.h"
#include "Keyboard.h"

Title::Title( ) {
}

Title::~Title( ) {
}

void Title::update( ) {

}

bool Title::isEndTitle( ) {
	KeyboardPtr keyboad =Keyboard::getTask( );
	return keyboad->isAnyKey( );
}