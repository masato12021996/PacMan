#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

const unsigned char KEY = 0xFF;

void main( ) {
	char name[ 1024 ];
	while ( scanf_s( "%s", name, 1024 ) != EOF ) {
		FILE *rfp;
		errno_t err = fopen_s( &rfp, name, "rb" );
		if ( err == 0 ) {
			unsigned char a;
			fread( &a,  sizeof( unsigned char ), 1, rfp );
			fclose( rfp );
			a = a ^ KEY;//•ÏŠ·
			FILE *wfp;
			fopen_s( &wfp, name, "r+b" );
			fwrite( &a, sizeof( unsigned char ), 1, wfp );
			fclose( wfp );
			printf( "SUCCESS!!\n" );
		} else {
			printf( "ERROR!!\n" );
		}
	}
}

