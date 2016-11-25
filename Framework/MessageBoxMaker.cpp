#include "MessageBoxMaker.h"
#include <Windows.h>
#include "DxLib.h"

MessageBoxMaker::MessageBoxMaker( ) {
}

MessageBoxMaker::~MessageBoxMaker( ) {
}

void MessageBoxMaker::create( std::string title, std::string message ) {
	MessageBox(
        NULL,
        message.c_str( ),
        title.c_str( ), 
        MB_OK );
}

std::string MessageBoxMaker::keyInput( int x, int y ) {
	char filename[1024];
	KeyInputString( x, y, 1024, filename, false );
	return filename;
}