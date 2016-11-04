#include "Application.h"
#include "DxLib.h"

#pragma warning(disable:4099)

const int COLOR_BIT = 32;
const int COLOR_BIT_DEPTH = 32;
const int FPS = 60;
const char* WINDOW_NAME = "Pac-Man";

ApplicationPtr Application::_instance;

Application::Application( ):
START_TIME( GetNowCount( ) ) {
	int sx = GetSystemMetrics( SM_CXSCREEN );
	int sy = GetSystemMetrics( SM_CYSCREEN );
#if FULLSCREEN
	ChangeWindowMode( FALSE );
	SetGraphMode( sx, sy, COLOR_BIT, FPS );
	_screen_width = sx;
	_screen_height = sy;
#else
	sx = sx * 3 / 4;
	sy = sy * 3 / 4;
	ChangeWindowMode( TRUE );
	SetGraphMode( sx, sy, COLOR_BIT_DEPTH, FPS );
	_screen_width = sx;
	_screen_height = sy;
#endif
#if _DEBUG
	SetDoubleStartValidFlag( TRUE ); // 多重起動
#endif
	SetWindowText( WINDOW_NAME );

	if ( DxLib_Init( ) == -1 ) {
		return;
	}

	SetUseLighting( FALSE );
	SetLightEnable( FALSE );
	SetUseZBuffer3D( TRUE );
	SetWriteZBuffer3D( TRUE );
	SetDrawScreen( DX_SCREEN_BACK );
	SetupCamera_Perspective( 12.0f * DX_PI_F / 180.0f );
	SetCameraNearFar( 10.0f, 10000.0f );
	SetAlwaysRunFlag( TRUE ) ;
	SetUseBackCulling( TRUE ) ;
    SetTextureAddressModeUV( DX_TEXADDRESS_WRAP, DX_TEXADDRESS_WRAP );

	_terminating = false;
}

Application::~Application( ) {
	DxLib_End( );
}

void Application::initialize( ) {
	if ( !_instance ) {
		_instance = ApplicationPtr( new Application );
	}
}

void Application::finalize( ) {
	if ( _instance ) {
		_instance.reset( );
	}
}

ApplicationPtr Application::getInstance( ) {
	return _instance;
}

void Application::run( ) {
	// 初期化
	{
		std::map< std::string, TaskPtr >::iterator ite = _task_list.begin( );
		while ( ite != _task_list.end( ) ) {
			TaskPtr task = ite->second;
			task->initialize( );
			ite++;
		}
	}

	// メインループ
	while ( true ) {
		if ( _terminating ) {
			break;
		}
		if ( ProcessMessage( ) != 0 ) {
			break;
		}
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
			break;
		}

		std::map< std::string, TaskPtr >::iterator ite = _task_list.begin( );
		while ( ite != _task_list.end( ) ) {
			TaskPtr task = ite->second;
			task->update( );
			ite++;
		}
	}

	// 終了処理
	{
		std::map< std::string, TaskPtr >::iterator ite = _task_list.begin( );
		while ( ite != _task_list.end( ) ) {
			TaskPtr task = ite->second;
			task->finalize( );
			ite++;
		}
	}
}

void Application::addTask( std::string tag, TaskPtr task ) {
	if ( task ) {
		_task_list[ tag ] = task;
	}
}

TaskPtr Application::getTask( std::string tag ) {
	if( _task_list.find( tag ) == _task_list.end( ) ) {
		return TaskPtr( );
	}
	return _task_list[ tag ];
}

int Application::getWindowWidth( ) const  {
	return _screen_width;
}

int Application::getWindowHeight( ) const  {
	return _screen_height;
}

void Application::terminate( ) {
	_terminating = true;
}

void Application::setWindowSize( int width, int height ) {

	SetGraphMode( width, height, COLOR_BIT_DEPTH, FPS );
	_screen_width = width;
	_screen_height = height;
}

int Application::getRunTime( ) {
	return GetNowCount( ) - START_TIME;
}
