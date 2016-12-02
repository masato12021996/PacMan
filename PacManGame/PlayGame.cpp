#include "PlayGame.h"
#include "Stage.h"

const std::string STAGE_PASS[ PlayGame::STAGE_NUM ] {
	"../Resource/StageData/Enemyeat浅野.stg",//00
	"../Resource/StageData/Enemyeat浅野.stg",//01
	"../Resource/StageData/Enemyeat浅野.stg",//02
	"../Resource/StageData/Enemyeat浅野.stg",//03
	"../Resource/StageData/Enemyeat浅野.stg",//04
	"../Resource/StageData/Enemyeat浅野.stg",//05
	"../Resource/StageData/Enemyeat浅野.stg",//06
	"../Resource/StageData/Enemyeat浅野.stg",//07
	"../Resource/StageData/Enemyeat浅野.stg",//08
	"../Resource/StageData/Enemyeat浅野.stg",//09
	"../Resource/StageData/Enemyeat浅野.stg",//10
	"../Resource/StageData/Enemyeat浅野.stg",//11
	"../Resource/StageData/Enemyeat浅野.stg",//12
	"../Resource/StageData/Enemyeat浅野.stg",//13
	"../Resource/StageData/Enemyeat浅野.stg",//14
	"../Resource/StageData/Enemyeat浅野.stg",//15
	"../Resource/StageData/Enemyeat浅野.stg",//16
	"../Resource/StageData/Enemyeat浅野.stg",//17
	"../Resource/StageData/Enemyeat浅野.stg",//18
	"../Resource/StageData/Enemyeat浅野.stg" //20
	"../Resource/StageData/Enemyeat浅野.stg" //21
	"../Resource/StageData/Enemyeat浅野.stg" //22
	"../Resource/StageData/Enemyeat浅野.stg" //23
	"../Resource/StageData/Enemyeat浅野.stg" //24
	"../Resource/StageData/Enemyeat浅野.stg" //25
	"../Resource/StageData/Enemyeat浅野.stg" //26
	"../Resource/StageData/Enemyeat浅野.stg" //27
	"../Resource/StageData/Enemyeat浅野.stg" //28
	"../Resource/StageData/Enemyeat浅野.stg" //29
};

PlayGame::PlayGame( ) {
	_state = PLAY_STATE_READY;
	_clear_stage_num = 0;
	_is_clear = false;

	//ステージの読み込み
	for( int i = 0; i < STAGE_NUM; i++ ) {
		FILE *fp;
		errno_t err;
		err = fopen_s( &fp, STAGE_PASS[ i ].c_str( ), "rb" );
		if ( err == 0 ) {
			StagePtr stage;
			fwrite( stage.get( ), sizeof( Stage ), 1, fp );
			fclose( fp );
			_stage_list[ i ] = stage;
		} else {
			_stage_list[ i ] = NULL;
		}
	}
}

PlayGame::~PlayGame( ) {
}

void PlayGame::update( ) {
	switch ( _state ) {
		case PLAY_STATE_READY:
		//入った時
			//音楽再生開始
			//初期化
		//音楽再生中
			//クリア条件表示
		//再生終了
			_state = PLAY_STATE_PLAY;//ステート切り替え
		break;
		case PLAY_STATE_PLAY:
		//ゲーム処理更新
		//ゲーム終了判定
			_state = PLAY_STATE_RESULT;//ステート更新
		break;
		case PLAY_STATE_RESULT:
		//リザルト表示
			//ゲーム画面表示
			//リザルト文字表示
		//リザルト終了時
			changeStage( );//ステージ切り替え
			_state = PLAY_STATE_READY;//ステート切り替え
		break;
	}
}

void PlayGame::changeStage( ) {
	_clear_stage_num++;
	while ( _stage_list[ _clear_stage_num ] == NULL ) {
		_clear_stage_num++;
	}
}

StagePtr PlayGame::getPlayStage( ) const {
	return _stage_list[ _clear_stage_num ];
}

PlayGame::PLAY_STATE PlayGame::getState( ) const {
	return _state;
}