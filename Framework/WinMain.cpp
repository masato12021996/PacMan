#include "DxLib.h"
#include "Application.h"
#include "Drawer.h"

void preAddTask( );
void main( );

int WINAPI WinMain( HINSTANCE hInstaece, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	Application::initialize( );
	preAddTask( );//��s���ă^�X�N�Ɋm��œo�^�������
	main( );
	Application::getInstance( )->run( );
	Application::finalize( );
	return 0;
}

void preAddTask( ) {
	ApplicationPtr application = Application::getInstance( );
	DrawerPtr drawer = DrawerPtr( new Drawer );

	application->addTask( Drawer::getTag( ), drawer );
}