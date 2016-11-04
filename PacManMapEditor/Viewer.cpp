#include "Viewer.h"
#include "Application.h"
#include "MapEditor.h"
#include "TremsManager.h"
#include "SelectObjectManager.h"
#include "Button.h"
#include "Drawer.h"

enum GRAPH_ID {
	GRAPH_ID_PACMAN,
	GRAPH_ID_ENEMY,
	GRAPH_ID_TARGET,
	GRAPH_ID_BACK_GROUND,
};

const int OBJECT_BUTTON_LIST[ 9 ] {
	GRAPH_ID_PACMAN,
	-1,
	GRAPH_ID_ENEMY,
	GRAPH_ID_ENEMY,
	GRAPH_ID_ENEMY,
	GRAPH_ID_ENEMY,
	GRAPH_ID_TARGET,
	GRAPH_ID_TARGET,
	GRAPH_ID_BACK_GROUND
};

const int OBJECT_BUTTON_SIZE = 32;
const int OBJECT_GRAPH_OFFSET = 4;

const int OBJECT_GRAPH_X[ 9 ] = {
	OBJECT_GRAPH_OFFSET,//PACMAN
	OBJECT_GRAPH_OFFSET,
	OBJECT_GRAPH_OFFSET,//ENEMY
	OBJECT_GRAPH_OFFSET,//ENEMY
	OBJECT_GRAPH_OFFSET,//ENEMY
	OBJECT_GRAPH_OFFSET,//ENEMY
	( OBJECT_BUTTON_SIZE + OBJECT_GRAPH_OFFSET ) * 8,//エサ
	( OBJECT_BUTTON_SIZE + OBJECT_GRAPH_OFFSET ) * 9,//パワーエサ
	0
};

const int OBJECT_GRAPH_Y[ 9 ] = {
	OBJECT_GRAPH_OFFSET,//PACMAN
	0,
	OBJECT_BUTTON_SIZE * 0,//ENEMY
	( OBJECT_BUTTON_SIZE + OBJECT_GRAPH_OFFSET ) * 1,//ENEMY
	( OBJECT_BUTTON_SIZE + OBJECT_GRAPH_OFFSET ) * 2,//ENEMY
	( OBJECT_BUTTON_SIZE + OBJECT_GRAPH_OFFSET ) * 3,//ENEMY
	OBJECT_GRAPH_OFFSET,
	OBJECT_GRAPH_OFFSET,
	0
};


ViewerPtr Viewer::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast< Viewer >( application->getTask( getTag( ) ) );
}

Viewer::Viewer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_ID_PACMAN, "../Resource/Graph/Player.png" );
	drawer->loadGraph( GRAPH_ID_ENEMY, "../Resource/Graph/Enemy.png" );
	drawer->loadGraph( GRAPH_ID_TARGET, "../Resource/Graph/Target.png" );
	drawer->loadGraph( GRAPH_ID_BACK_GROUND, "../Resource/Graph/BackGround.png" );
}

Viewer::~Viewer( ) {
}

void Viewer::update( ) {
	drawTremsButton( );
	drawObjectButton( );
	drawMatrix( );
}

void Viewer::drawMatrix( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	for ( int i = 0; i < 24; i++ ) {
		for ( int j = 0; j < 30; j++ ) {
			bool flag = map_editor->getMeshMap( j, i ) == 1;
			drawer->drawBox( j * 32, i * 32, 32, flag );
		}
	}
}

void Viewer::drawTremsButton( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	TremsManagerPtr trems_manager = map_editor->getTremsManager( );
	for ( int i = 0; i < trems_manager->getButtonNum( ); i++ ) {
		ButtonPtr button = trems_manager->getButton( i );
		int px = button->getButtonPosX( );
		int py = button->getButtonPosY( );
		int width = button->getButtonWidth( );
		int height = button->getButtonHeight( );
		bool fill_flag = button->getFillFlag( );
		drawer->drawBox( px, py, width, height, fill_flag );
		drawer->drawString( px + 5, py + 5, trems_manager->getButtonName( i ).c_str( ), fill_flag );
	}
}

void Viewer::drawObjectButton( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	SelectObjectManagerPtr select_manager = map_editor->getSelectObjectManager( );
	for ( int i = 0; i < select_manager->getButtonNum( ); i++ ) {
		ButtonPtr button = select_manager->getButton( i );
		int px = button->getButtonPosX( );
		int py = button->getButtonPosY( );
		int width = button->getButtonWidth( );
		int height = button->getButtonHeight( );
		bool fill_flag = button->getFillFlag( );
		int image = OBJECT_BUTTON_LIST[ i ];
		if ( image != -1 ) {
			Drawer::Sprite sprite;
			if ( image == GRAPH_ID_BACK_GROUND ) {
				for ( int i = 0; i < 4; i++ ) {
					sprite.x = px + OBJECT_BUTTON_SIZE * ( i % 2 );
					sprite.y = py + OBJECT_BUTTON_SIZE * ( i / 2 );
					sprite.tx = OBJECT_BUTTON_SIZE * ( 4 - 1 - i );
					sprite.ty = 0;
					sprite.width = OBJECT_BUTTON_SIZE;
					sprite.height = OBJECT_BUTTON_SIZE;
					sprite.image = image;
					sprite.trans_flag = true;
					drawer->setSprite( sprite );
				}
			} else {
				sprite.x = px;
				sprite.y = py;
				sprite.tx = OBJECT_GRAPH_X[ i ];
				sprite.ty = OBJECT_GRAPH_Y[ i ];
				sprite.width = width;
				sprite.height = height;
				sprite.image = image;
				sprite.trans_flag = true;
				drawer->setSprite( sprite );
			}
		}
		drawer->drawBox( px, py, width, height, fill_flag );
	}
}