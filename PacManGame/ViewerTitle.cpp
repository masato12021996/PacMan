#include "ViewerTitle.h"
#include "GraphManager.h"

ViewerTitle::ViewerTitle( GraphManagerPtr graph_manager ) {
	_graph_manager = graph_manager;
}

ViewerTitle::~ViewerTitle( ) {
}

void ViewerTitle::update( ) {
	_graph_manager->drawChip( 0, 0, GraphManager::CHIP_ID_TITLE );
}