#pragma once

#include "smart_ptr.h"
#include "Task.h"
#include <string>
#include <map>

PTR( Application );

class Application {
public:
	Application( );
	virtual ~Application( );
public:
	static void initialize( );
	static void finalize( );
	static ApplicationPtr getInstance( );
public:
	void run( );
	void addTask( std::string tag, TaskPtr task );
	TaskPtr getTask( std::string tag );
	int getWindowWidth( ) const;
	int getWindowHeight( ) const;
	void terminate( );
	void setWindowSize( int width, int height );
	int getRunTime( );
private:
	const int START_TIME;
	static ApplicationPtr _instance;
	int _screen_width;
	int _screen_height;
	std::map< std::string, TaskPtr > _task_list;
	bool _terminating;
};

