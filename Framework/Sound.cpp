#include "Sound.h"
#include "Application.h"
#include "Dxlib.h"
#include "Encorder.h"
#include <string>

SoundPtr Sound::getTask( ) {
	ApplicationPtr fw = Application::getInstance( );
	return std::dynamic_pointer_cast< Sound >( fw->getTask( Sound::getTag( ) ) );
}

Sound::Sound( const char * directory ) :
_directory( directory ){
}

void Sound::initialize( ) {
	//‚r‚d
}

void Sound::finalize( ) {
}

Sound::~Sound( ) {
	
}

void Sound::update( ) {
}

void Sound::playSE( std::string filename, bool loop ) {
	Encorder encorder;
	if ( _se.count( filename ) == 0 ) {
		// V‚µ‚¢SE‚ğÄ¶
		std::string path = _directory;
		path += "/";
		path +=  filename;
		encorder.encode( path );
		int id = LoadSoundMem( path.c_str( ) );
		encorder.encode( path );
		_se[ filename ] = id;
	}
	if ( loop ) {
		PlaySoundMem( _se[ filename ], DX_PLAYTYPE_LOOP );
	} else {
		PlaySoundMem( _se[ filename ], DX_PLAYTYPE_BACK );
	}
}

void Sound::stopSE( std::string filename ) {
	if ( _se.count( filename ) == 0 ) {
		return;
	}

	StopSoundMem( _se[ filename ] );
}

void Sound::playBGM( std::string filename, bool loop ) {
	// ‘O‰ñ‚Ì‚a‚f‚l‚ğíœ
	StopMusic( );

	int flg = DX_PLAYTYPE_BACK;
	if ( loop ) {
		flg = DX_PLAYTYPE_LOOP;
	}

	// V‚µ‚¢‚a‚f‚l‚ğÄ¶
	std::string path = _directory;
	path += "/";
	path +=  filename;
	Encorder encorder;
	encorder.encode( path );
	PlayMusic( path.c_str( ), flg );
	encorder.encode( path );
}

void Sound::stopBGM( ) {
	StopMusic( );
}

void Sound::stopAllSE( ) {
	std::map< std::string, int >::iterator it = _se.begin( );
	while ( it != _se.end( ) ) {
		StopSoundMem( (*it).second );
		it++;
	}
}