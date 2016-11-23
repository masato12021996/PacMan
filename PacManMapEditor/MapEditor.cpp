#include "MapEditor.h"
#include "Application.h"
#include "Stage.h"
#include "Mouse.h"
#include "TremsManager.h"
#include "SelectObjectManager.h"
#include "MessageBoxMaker.h"
#include "Button.h"

const int SAVE_BUTTON_POS_X  = 1000;
const int SAVE_BUTTON_POS_Y  = 600;
const int SAVE_BUTTON_WIDTH  = 100;
const int SAVE_BUTTON_HEIGHT = 32;


MapEditorPtr MapEditor::getTask( ) {
	ApplicationPtr application = Application::getInstance( );
	return std::dynamic_pointer_cast< MapEditor >( application->getTask( getTag( ) ) );
}

MapEditor::MapEditor( ) {
	_trems_manager = TremsManagerPtr( new TremsManager );
	_select_manager = SelectObjectManagerPtr( new SelectObjectManager );
	_save_button = ButtonPtr( new Button( SAVE_BUTTON_POS_X, SAVE_BUTTON_POS_Y, SAVE_BUTTON_WIDTH, SAVE_BUTTON_HEIGHT ) );
	for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
		for ( int j = 0; j < MAP_SIZE_X; j++ ) {
			_mesh_map[ i ][ j ] = 0;
			//初期配置
			if ( ( i == MAP_SIZE_Y / 2 - 1 || i == MAP_SIZE_Y / 2 ) && ( j == 0 || j == MAP_SIZE_X - 1 ) ) {
				_object_map[ i ][ j ] = 0;
			} else if ( i == 0 || i == MAP_SIZE_Y -1 || j == 0 || j == MAP_SIZE_X -1 ) {
				_object_map[ i ][ j ] = Stage::OBJECT_NAME_WALL;
			} else {
				_object_map[ i ][ j ] = 0;
			}
		}
	}
}

MapEditor::~MapEditor( ) {
}

void MapEditor::update( ) {
	_trems_manager->update( );
	_select_manager->update( );
	meshMapUpdate( );
	putObjectUpdate( );
	if ( _save_button->onClick( ) ) {
		_save_button->setFillFlag( true );
		save( );
	} else {
		_save_button->setFillFlag( false );
	}
}

void MapEditor::meshMapUpdate( ) {
	for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
		for ( int j = 0; j < MAP_SIZE_X; j++ ) {
			_mesh_map[ i ][ j ] = 0;
		}
	}
	MousePtr mouse = Mouse::getTask( );
	Vector mpos = mouse->getPoint( );
	if ( 0 < mpos.x && mpos.x < MAP_SIZE_X * CHIP_SIZE && 0 < mpos.y && mpos.y < MAP_SIZE_Y * CHIP_SIZE ) {
		int x = ( int )mpos.x / CHIP_SIZE;
		int y = ( int )mpos.y / CHIP_SIZE;
		_mesh_map[ y ][ x ] = 1;
	}
}

void MapEditor::putObjectUpdate( ) {
	_select_object =  _select_manager->getSelectObject( );
	MousePtr mouse = Mouse::getTask( );
	if ( mouse->isInputButton( Mouse::INPUT_ON_LEFT ) ) {
		Vector mpos = mouse->getPoint( );
		if ( 0 < mpos.x && mpos.x < MAP_SIZE_X * CHIP_SIZE && 0 < mpos.y && mpos.y < MAP_SIZE_Y * CHIP_SIZE ) {
			int x = ( int )mpos.x / CHIP_SIZE;
			int y = ( int )mpos.y / CHIP_SIZE;
			bool is_outwall = x == 0 || x == MAP_SIZE_X - 1 || y == 0 || y == MAP_SIZE_Y - 1;
			if ( !is_outwall ) {
				//ここで置くかどうかの判断
				_object_map[ y ][ x ] = _select_object;
			}
		}
	}
}

int MapEditor::getMeshMap( int x, int y ) const {
	return _mesh_map[ y ][ x ];
}

int MapEditor::getObjectMap( int x, int y ) const {
	return _object_map[ y ][ x ];
}

Stage::CLEAR_TREMS MapEditor::getClearTrems( ) const{
	return _trems_manager->getClearTrems( );
}

TremsManagerPtr MapEditor::getTremsManager( ) const {
	return _trems_manager;
}

SelectObjectManagerPtr MapEditor::getSelectObjectManager( ) const {
	return _select_manager;
}

ButtonPtr MapEditor::getSaveButton( ) const {
	return _save_button;
}

void MapEditor::save( ) {
	//クリア条件の確認
	Stage::CLEAR_TREMS temp_trems = getClearTrems( );
	//マップを見てクリア条件に最低限必要なものがあるか確認
	std::string message_str = "ERROR_POINT:\n";
	bool can_save = false;
	if ( temp_trems == Stage::CLEAR_TREMS_FOOD_EAT ) {
		bool put_player = false;
		bool put_bate = false;
		int player_num = 0;
		for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
			for ( int j = 0; j < MAP_SIZE_X; j++ ) {
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_BATE || _object_map[ i ][ j ] == Stage::OBJECT_NAME_POWER_BATE ) {
					put_bate = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_PLAYER ) {
					player_num++;
				}
			}
		}
		if ( player_num == 1 ) {
			put_player = true;
		} else {
			//ERROR処理
			message_str += "〇プレイヤーが居ないか多すぎます\n";
		}
		if ( !put_bate ) {
			//ERROR処理
			message_str += "〇餌が置いてないです\n";
		}
		can_save = put_player && put_bate;
	}

	if ( temp_trems == Stage::CLEAR_TREMS_ENEMY_EAT ) {
		bool put_player = false;
		bool put_bate = false;
		bool put_enemy = false;
		int player_num = 0;
		for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
			for ( int j = 0; j < MAP_SIZE_X; j++ ) {
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_POWER_BATE ) {
					put_bate = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_BLUE ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_ORANGE ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_PINC ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_RED ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_PLAYER ) {
					player_num++;
				}
			}
		}
		if ( player_num == 1 ) {
			put_player = true;
		} else {
			//ERROR処理
			message_str += "〇プレイヤーが居ないか多すぎます\n";
		}
		if ( !put_bate ) {
			//ERROR処理
			message_str += "〇パワー餌が置いてないです\n";
		}
		if ( !put_enemy ) {
			//ERROR処理
			message_str += "〇敵がいません\n";
		}
		can_save = put_player && put_bate && put_enemy;
	}

	if ( temp_trems == Stage::CLEAR_TREMS_OUTRUN ) {
		bool put_player = false;
		bool put_enemy = false;
		int player_num = 0;
		for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
			for ( int j = 0; j < MAP_SIZE_X; j++ ) {
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_BLUE ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_ORANGE ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_PINC ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_ENEMY_RED ) {
					put_enemy = true;
				}
				if ( _object_map[ i ][ j ] == Stage::OBJECT_NAME_PLAYER ) {
					player_num++;
				}
			}
		}
		if ( player_num == 1 ) {
			put_player = true;
		} else {
			//ERROR処理
			message_str += "〇プレイヤーが居ないか多すぎます\n";
		}
		if ( !put_enemy ) {
			//ERROR処理
			message_str += "〇敵がいません\n";
		}
		can_save = put_player && put_enemy;
	}

	MessageBoxMakerPtr message = MessageBoxMakerPtr( new MessageBoxMaker( ) );
	//StageSave
	if ( can_save ) {
		Stage stage;
		stage.setTrems( getClearTrems( ) );
		for ( int i = 0 ; i < MAP_SIZE_Y; i++ ) {
			for ( int j = 0; j < MAP_SIZE_X; j++ ) {
				stage.setTargetCell( j, i, ( Stage::OBJECT_NAME )_object_map[ j ][ i ] );
			}
		}
		FILE *fp;
		errno_t err = fopen_s( &fp, "stage.stg", "wb" );
		fwrite( &stage, sizeof( Stage ), 1, fp );
		fclose( fp );
	} else {
		message->create( "ERROR", message_str.c_str( ) );
	}
}

void MapEditor::load( ) {

}