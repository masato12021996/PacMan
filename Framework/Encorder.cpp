#include "Encorder.h"
#include <assert.h>

const unsigned char KEY = 0xFF;

Encorder::Encorder( ) {
}

Encorder::~Encorder( ) {
}

void Encorder::encode( std::string filename ) {
	FILE *rfp;
	errno_t err = fopen_s( &rfp, filename.c_str( ), "rb" );
	if ( err == 0 ) {
		unsigned char a;
		fread( &a,  sizeof( unsigned char ), 1, rfp );
		fclose( rfp );
		a = a ^ KEY;//�ϊ�
		FILE *wfp;
		fopen_s( &wfp, filename.c_str( ), "r+b" );
		fwrite( &a, sizeof( unsigned char ), 1, wfp );
		fclose( wfp );
	} else {
		fclose( rfp );
		assert( "ERROR!!" );
	}
}