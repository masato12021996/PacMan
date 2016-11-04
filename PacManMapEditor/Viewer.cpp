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

const int OBJECT_BUTTON_LIST[ 8 ] {
	GRAPH_ID_PACMAN,
	GRAPH_ID_ENEMY,
	GRAPH_ID_ENEMY,
	GRAPH_ID_ENEMY,
	GRAPH_ID_ENEMY,
	GRAPH_ID_TARGET,
	GRAPH_ID_TARGET,
	GRAPH_ID_BACK_GROUND
};

const int OBJECT_SIZE = 32;
const int OBJECT_GRAPH_OFFSET = 4;

const int OBJECT_GRAPH_X[ 8 ] = {
	OBJECT_GRAPH_OFFSET,//PACMAN
	OBJECT_GRAPH_OFFSET,//ENEMY
	OBJECT_GRAPH_OFFSET,//ENEMY
	OBJECT_GRAPH_OFFSET,//ENEMY
	OBJECT_GRAPH_OFFSET,//ENEMY
	( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 8,//エサ
	( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 9,//パワーエサ
	0
};

const int OBJECT_GRAPH_Y[ 8 ] = {
	OBJECT_GRAPH_OFFSET,//PACMAN
	OBJECT_SIZE * 0,//ENEMY
	( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 1,//ENEMY
	( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 2,//ENEMY
	( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 3,//ENEMY
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
	drawObject( );
}

void Viewer::drawMatrix( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	bool first = true;
	for ( int i = 0; i < 24; i++ ) {
		for ( int j = 0; j < 30; j++ ) {
			bool flag = map_editor->getMeshMap( j, i ) == 1;
			if ( flag && first ) {

			}
			drawer->drawBox( j * OBJECT_SIZE, i * OBJECT_SIZE, OBJECT_SIZE, flag );
		}
	}
}

void Viewer::drawObject( ) {
	DrawerPtr drawer = Drawer::getTask( );
	MapEditorPtr map_editor = MapEditor::getTask( );
	for ( int i = 0; i < 24; i++ ) {
		for ( int j = 0; j < 30; j++ ) {
			int id = map_editor->getObjectMap( j, i );
			Drawer::Sprite sprite;
			sprite.x = j * OBJECT_SIZE;
			sprite.y = i * OBJECT_SIZE;
			sprite.width = OBJECT_SIZE;
			sprite.height = OBJECT_SIZE;
			sprite.trans_flag = true;
			bool can_draw = true;
			switch ( id ) {
			case Stage::OBJECT_NAME_PLAYER:
				sprite.image = GRAPH_ID_PACMAN;
				sprite.tx = 0;
				sprite.ty = 0;
				break;
			case Stage::OBJECT_NAME_ENEMY_RED:
				sprite.image = GRAPH_ID_ENEMY;
				sprite.tx = 0;
				sprite.ty = 0;
				break;
			case Stage::OBJECT_NAME_ENEMY_PINC:
				sprite.image = GRAPH_ID_ENEMY;
				sprite.tx = 0;
				sprite.ty = ( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 1;
				break;
			case Stage::OBJECT_NAME_ENEMY_BLUE:
				sprite.image = GRAPH_ID_ENEMY;
				sprite.tx = 0;
				sprite.ty = ( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 2;
				break;
			case Stage::OBJECT_NAME_ENEMY_ORANGE:
				sprite.image = GRAPH_ID_ENEMY;
				sprite.tx = 0;
				sprite.ty = ( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 3;
				break;
			case Stage::OBJECT_NAME_BATE:
				sprite.image = GRAPH_ID_TARGET;
				sprite.tx = ( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 8;
				sprite.ty = OBJECT_GRAPH_OFFSET;
				break;
			case Stage::OBJECT_NAME_POWER_BATE:
				sprite.image = GRAPH_ID_TARGET;
				sprite.tx = ( OBJECT_SIZE + OBJECT_GRAPH_OFFSET ) * 9;
				sprite.ty = OBJECT_GRAPH_OFFSET;
				break;
			default:
				can_draw = false;
				break;
			}
			if ( can_draw ) {
				drawer->setSprite( sprite );
			}
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
		
		Drawer::Sprite sprite;
		if ( image == GRAPH_ID_BACK_GROUND ) {
			for ( int i = 0; i < 4; i++ ) {
				sprite.x = px + OBJECT_SIZE * ( i % 2 );
				sprite.y = py + OBJECT_SIZE * ( i / 2 );
				sprite.tx = OBJECT_SIZE * ( 4 - 1 - i );
				sprite.ty = 0;
				sprite.width = OBJECT_SIZE;
				sprite.height = OBJECT_SIZE;
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
		drawer->drawBox( px, py, width, height, fill_flag );
	}
}