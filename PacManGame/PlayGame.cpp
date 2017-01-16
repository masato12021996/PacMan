#include "PlayGame.h"
#include "Stage.h"
#include "PlayStage.h"

const std::string STAGE_PASS[ PlayGame::STAGE_NUM ] {
	"../Resource/StageData/Stage_01.stg",//00
	"../Resource/StageData/Stage_01.stg",//01
	"../Resource/StageData/Stage_01.stg",//02
	"../Resource/StageData/Stage_01.stg",//03
	"../Resource/StageData/Stage_01.stg",//04
	"../Resource/StageData/Stage_01.stg",//05
	"../Resource/StageData/Stage_01.stg",//06
	"../Resource/StageData/Stage_01.stg",//07
	"../Resource/StageData/Stage_01.stg",//08
	"../Resource/StageData/Stage_01.stg",//09
	"../Resource/StageData/Stage_01.stg",//10
	"../Resource/StageData/Stage_01.stg",//11
	"../Resource/StageData/Stage_01.stg",//12
	"../Resource/StageData/Stage_01.stg",//13
	"../Resource/StageData/Stage_01.stg",//14
	"../Resource/StageData/Stage_01.stg",//15
	"../Resource/StageData/Stage_01.stg",//16
	"../Resource/StageData/Stage_01.stg",//17
	"../Resource/StageData/Stage_01.stg",//18
	"../Resource/StageData/Stage_01.stg" //20
	"../Resource/StageData/Stage_01.stg" //21
	"../Resource/StageData/Stage_01.stg" //22
	"../Resource/StageData/Stage_01.stg" //23
	"../Resource/StageData/Stage_01.stg" //24
	"../Resource/StageData/Stage_01.stg" //25
	"../Resource/StageData/Stage_01.stg" //26
	"../Resource/StageData/Stage_01.stg" //27
	"../Resource/StageData/Stage_01.stg" //28
	"../Resource/StageData/Stage_01.stg" //29
};

PlayGame::PlayGame( ) {
	_play_stage = PlayStagePtr( new PlayStage( ) );

	_state = PLAY_STATE_READY;
	_clear_stage_num = 0;
	_stage_index = 0;
	_is_clear = false;

	//ステージの読み込み
	for( int i = 0; i < STAGE_NUM; i++ ) {
		FILE *fp;
		errno_t err;
		err = fopen_s( &fp, STAGE_PASS[ i ].c_str( ), "rb" );
		if ( err == 0 ) {
			Stage stage;
			fread( &stage, sizeof( Stage ), 1, fp );
			fclose( fp );
			_stage_list[ i ] = StagePtr( new Stage( stage ) );
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
			_play_stage->create( _stage_list[ _stage_index ] );
		//音楽再生中
			//クリア条件表示
		//再生終了
			_state = PLAY_STATE_PLAY;//ステート切り替え
		break;
		case PLAY_STATE_PLAY:
		//ゲーム処理更新
		_play_stage->update( );
		//ゲーム終了判定
		if ( _play_stage->isEndStage( ) ) {
			_state = PLAY_STATE_RESULT;//ステート更新
		}
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
	_stage_index++;
	while ( _stage_index < STAGE_NUM && _stage_list[ _stage_index ] == NULL ) {
		_stage_index++;
	}

}

PlayGame::PLAY_STATE PlayGame::getState( ) const {
	return _state;
}

PlayStagePtr PlayGame::getPlayStage( ) const {
	return _play_stage;
}