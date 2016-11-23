#include "MessageBoxMaker.h"
#include <Windows.h>

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