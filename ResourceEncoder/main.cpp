#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

const std::string LOAD_DIRECTORY = "resource/input/";
const std::string SAVE_DIRECTORY = "resource/output/";
const int EXTENSION_SIZE = 4;

void main( ) {
	char name[ 1024 ];
	while ( scanf_s( "%s", name, 1024 ) != EOF ) {
		//ì«Ç›çûÇ›
		std::string load_filename = LOAD_DIRECTORY + name;
		std::ifstream ifs( load_filename );
		if ( ifs.fail( ) ) {
			std::cerr << "EORROR!!" << std::endl;
			continue;
		}
		std::istreambuf_iterator<char> it(ifs);
		std::istreambuf_iterator<char> last;
		std::string str(it, last);
		//èëÇ´çûÇ›
		std::string save_filename = SAVE_DIRECTORY + name;
		std::string key = save_filename.substr( save_filename.size( ) - EXTENSION_SIZE, EXTENSION_SIZE );
		if ( key == ".png" ) {
			key = ".grp";
		} else if ( key == ".wav" ) {
				key = ".snd";
		}
		save_filename.replace( save_filename.size( ) - EXTENSION_SIZE, EXTENSION_SIZE, key );
		std::ofstream ofs( save_filename, std::ios::out | std::ios::binary | std::ios::trunc );
		ofs.write( str.c_str( ), str.size( ) );
		std::cout << "SUCCESS!!" << std::endl;
	}
}

