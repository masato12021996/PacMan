#pragma once
#include "Task.h"
#include <string>
#include <list>
#include <array>

PTR( Drawer );

class Drawer : public Task {
public:
	static DrawerPtr getTask( );
	static std::string getTag(  ) { return "DRAWER"; }
public:
	struct Sprite {
		int x;
		int y;
		int tx;
		int ty;
		int width;
		int height;
		int image;
		bool trans_flag;
		Sprite( ) {
			x = 0;
			y = 0;
			tx = 0;
			ty = 0;
			width = 0;
			height = 0;
			image = 0;
			trans_flag = true;
		};
		//‰æ‘œ‚Ì•`‰æİ’è
		Sprite( int _x, int _y, int _tx, int _ty, int _width, int _height, int _image, bool _trans_flag = true ) {
			x = _x;
			y = _y;
			tx = _tx;
			ty = _ty;
			width = _width;
			height = _height;
			image = _image;
			trans_flag = _trans_flag;
		};
	};
public:
	Drawer( );
	virtual ~Drawer( );
public:
	void update( );
	void loadGraph( const int number, std::string filename );
	void setSprite( Sprite sprite );
	void drawBox( int x, int y, int size, bool fill_flag, int color = 0xffffff );
	void drawBox( int x, int y, int width, int height, bool fill_flag );
	void drawString( int x, int y, const char* string, bool fill_flag );
private:
	void flip( );
	void drawSprite( );
private:
	static const int MAX_GRAPH_ID_NUM = 1000;
	std::array< int, MAX_GRAPH_ID_NUM > _graph_id;
	std::list< Sprite > _sprite;
};