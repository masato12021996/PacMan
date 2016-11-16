#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

const char KEY = 0xFF;
const int EXTENSION_SIZE = 4;

void main( ) {
	char name[ 1024 ];
	while ( scanf_s( "%s", name, 1024 ) != EOF ) {
		FILE *rfp;
		errno_t err = fopen_s( &rfp, name, "r" );
		if ( err == 0 ) {
			char a;
			fscanf_s( rfp, "%c", &a );
			fclose( rfp );
			a = a ^ KEY;//•ÏŠ·
			FILE *wfp;
			fopen_s( &wfp, name, "r+b" );
			fwrite( &a, sizeof( char ), 1, wfp );
			fclose( wfp );
			printf( "SUCCESS!!\n" );
		} else {
			printf( "ERROR!!\n" );
		}
	}
}

