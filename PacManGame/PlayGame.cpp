#include "PlayGame.h"
#include "Stage.h"
#include "PlayStage.h"
#include "Sound.h"

const int RESULT_TIME = 60 * 2;
const int READY_TIME = 60 * 4;

const std::string STAGE_PASS[ PlayGame::STAGE_NUM ] {
	"../Resource/StageData/Stage_01.stg",
	"../Resource/StageData/Stage_02.stg",
	"../Resource/StageData/Stage_03.stg",
	"../Resource/StageData/Stage_04.stg",
	"../Resource/StageData/Stage_05.stg",
	"../Resource/StageData/Stage_06.stg",
	"../Resource/StageData/Stage_07.stg",
	"../Resource/StageData/Stage_08.stg",
	"../Resource/StageData/Stage_09.stg",
	"../Resource/StageData/Stage_10.stg",
	"../Resource/StageData/Stage_11.stg",
	"../Resource/StageData/Stage_12.stg",
	"../Resource/StageData/Stage_13.stg",
	"../Resource/StageData/Stage_14.stg",
	"../Resource/StageData/Stage_15.stg",
	"../Resource/StageData/Stage_16.stg",
	"../Resource/StageData/Stage_17.stg",
	"../Resource/StageData/Stage_18.stg",
	"../Resource/StageData/Stage_19.stg",
	"../Resource/StageData/Stage_20.stg",
	"../Resource/StageData/Stage_21.stg",
	"../Resource/StageData/Stage_22.stg",
	"../Resource/StageData/Stage_23.stg",
	"../Resource/StageData/Stage_24.stg",
	"../Resource/StageData/Stage_25.stg",
	"../Resource/StageData/Stage_26.stg",
	"../Resource/StageData/Stage_27.stg",
	"../Resource/StageData/Stage_28.stg",
	"../Resource/StageData/Stage_29.stg",
	"../Resource/StageData/Stage_30.stg"
};

PlayGame::PlayGame( ) {
	reset( );	
}

PlayGame::~PlayGame( ) {
}

void PlayGame::update( ) {
	SoundPtr sound = Sound::getTask( );
	switch ( _state ) {
		case PLAY_STATE_READY:
		//入った時
			if ( _redy_time == 0 ) {
			//音楽再生開始
			sound->playSE( "game_start.wav" );
			}
		//音楽再生中
			_redy_time++;
		//再生終了
			if ( _redy_time > READY_TIME ) {
				//初期化
				_play_stage->create( _stage_list[ _stage_index ] );
				_state = PLAY_STATE_PLAY;//ステート切り替え
				_redy_time = 0;
			}
		break;
		case PLAY_STATE_PLAY:
		//ゲーム処理更新
		_play_stage->update( );
		//ゲーム終了判定
		if ( _play_stage->isClearStage( ) || _play_stage->isDeadStage( ) ) {
			_state = PLAY_STATE_RESULT;//ステート更新
			_result_time = 0;
		}
		break;
		case PLAY_STATE_RESULT:
		//リザルト表示
			sound->stopBGM( );
			//ゲーム画面表示
			//リザルト文字表示
		//リザルト終了時
			if ( _result_time > RESULT_TIME ) {
				//ゲームオーバー
				if ( _play_stage->isDeadStage( ) || _clear_stage_num == STAGE_NUM ) {
					_is_end_game = true;
				} else {
					//クリアした場合
					if ( _play_stage->isClearStage( ) ) {
						changeStage( );//ステージ切り替え
						_state = PLAY_STATE_READY;//ステート切り替え
					}
				}
			}
			_result_time++;
		break;
	}
}

void PlayGame::changeStage( ) {
	_stage_index++;
	while ( _stage_index < STAGE_NUM && _stage_list[ _stage_index ] == NULL ) {
		_stage_index++;
	}
	_clear_stage_num++;
}

PlayGame::PLAY_STATE PlayGame::getState( ) const {
	return _state;
}

PlayStagePtr PlayGame::getPlayStage( ) const {
	return _play_stage;
}

int PlayGame::getClearStageNum( ) const {
	return _clear_stage_num;
}

bool PlayGame::isEndGame( ) const {
	return _is_end_game;
}

void PlayGame::reset( ) {
	_play_stage = PlayStagePtr( new PlayStage( ) );
	_state = PLAY_STATE_READY;
	_clear_stage_num = 0;
	_stage_index = 0;
	_is_clear = false;
	_is_end_game = false;

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
	_result_time = 0;
	_redy_time = 0;
}