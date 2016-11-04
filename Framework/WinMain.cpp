#include "DxLib.h"
#include "Application.h"
#include "Drawer.h"

void preAddTask( );
void main( );

int WINAPI WinMain( HINSTANCE hInstaece, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	Application::initialize( );
	preAddTask( );//先行してタスクに確定で登録するもの
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