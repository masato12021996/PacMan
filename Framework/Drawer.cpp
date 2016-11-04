#include "Drawer.h"
#include "Application.h"
#include "DxLib.h"
#include <assert.h>

DrawerPtr Drawer::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast< Drawer >( application->getTask( getTag( ) ) );
}

Drawer::Drawer( ) {
	for ( int i = 0; i< MAX_GRAPH_ID_NUM; i++ ) {
		_graph_id[ i ] = -1;
	}
}

Drawer::~Drawer( ) {
}

void Drawer::update( ) {
	drawSprite( );
	flip( );
}

void Drawer::loadGraph( const int number, std::string filename ) {
	int graph_id = LoadGraph( filename.c_str( ) );
	if ( graph_id < 0 ) {
		assert( "ERROR_LOAD_GRAPH" );
	}
	_graph_id[ number ] = graph_id;
}

//Spriteデータのセット
void Drawer::setSprite( Sprite sprite ) {
	_sprite.push_back( sprite );
}

//画面更新
void Drawer::flip( ) {
	ScreenFlip( );
	ClearDrawScreen( );
}

//画像の描画
void Drawer::drawSprite( ) {
	int num = _sprite.size( );
	std::list< Sprite >::iterator it = _sprite.begin( );
	while( it != _sprite.end( ) ) {
		Sprite sprite = *it;

		int image = _graph_id[ sprite.image ];
		//画像が読み込まれていなかった時
		if ( image < 0 ) {
			assert( "NOT_LOADED_GRAPH" );
		}

		DrawGraph( sprite.x, sprite.y, image, sprite.trans_flag );
		it++;
	}
	if ( !_sprite.empty( ) ) {
		_sprite.clear( );
	}
}

void Drawer::drawBox( int x, int y, int size, bool fill_flag ) {
	DrawBox( x, y, x + size, y + size, GetColor( 255, 255, 255 ), fill_flag  );
}

void Drawer::drawBox( int x, int y, int width, int height, bool fill_flag ) {
	DrawBox( x, y, x + width, y + height, GetColor( 255, 255, 255 ), fill_flag  );
}

void Drawer::drawString( int x, int y, const char* string, bool fill_flag ) {
	int color = 0xFFFFFF;
	if ( fill_flag ) {
		color = 0x000000;
	}
	DrawString( x, y, string, color );
}