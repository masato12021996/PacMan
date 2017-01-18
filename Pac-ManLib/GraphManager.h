#pragma once
#include "Drawer.h"
#include "smart_ptr.h"

PTR( GraphManager );

class GraphManager {
public:
	enum CHIP_ID {
		//パックマンはアニメーション
		CHIP_ID_PACMAN_1_LEFT,
		CHIP_ID_PACMAN_2_LEFT,
		CHIP_ID_PACMAN_3_LEFT,
		CHIP_ID_PACMAN_1_RIGHT,
		CHIP_ID_PACMAN_2_RIGHT,
		CHIP_ID_PACMAN_3_RIGHT,
		CHIP_ID_PACMAN_1_DOWN,
		CHIP_ID_PACMAN_2_DOWN,
		CHIP_ID_PACMAN_3_DOWN,
		CHIP_ID_PACMAN_1_UP,
		CHIP_ID_PACMAN_2_UP,
		CHIP_ID_PACMAN_3_UP,
		CHIP_ID_PACMAN_LD,
		CHIP_ID_PACMAN_LU,
		CHIP_ID_PACMAN_RD,
		CHIP_ID_PACMAN_RU,
		CHIP_ID_PACMAN_DEAD_01,
		CHIP_ID_PACMAN_DEAD_02,
		CHIP_ID_PACMAN_DEAD_03,
		CHIP_ID_PACMAN_DEAD_04,
		CHIP_ID_PACMAN_DEAD_05,
		CHIP_ID_PACMAN_DEAD_06,
		CHIP_ID_PACMAN_DEAD_07,
		CHIP_ID_PACMAN_DEAD_08,
		CHIP_ID_PACMAN_DEAD_09,
		CHIP_ID_PACMAN_DEAD_10,
		CHIP_ID_PACMAN_DEAD_11,
		//敵は色と向きとアニメーション番号
		CHIP_ID_ENEMY_RED_RIGHT_0,
		CHIP_ID_ENEMY_RED_RIGHT_1,
		CHIP_ID_ENEMY_RED_DOWN_0,
		CHIP_ID_ENEMY_RED_DOWN_1,
		CHIP_ID_ENEMY_RED_LEFT_0,
		CHIP_ID_ENEMY_RED_LEFT_1,
		CHIP_ID_ENEMY_RED_UP_0,
		CHIP_ID_ENEMY_RED_UP_1,
		CHIP_ID_ENEMY_PINC_RIGHT_0,
		CHIP_ID_ENEMY_PINC_RIGHT_1,
		CHIP_ID_ENEMY_PINC_DOWN_0,
		CHIP_ID_ENEMY_PINC_DOWN_1,
		CHIP_ID_ENEMY_PINC_LEFT_0,
		CHIP_ID_ENEMY_PINC_LEFT_1,
		CHIP_ID_ENEMY_PINC_UP_0,
		CHIP_ID_ENEMY_PINC_UP_1,
		CHIP_ID_ENEMY_BLUE_RIGHT_0,
		CHIP_ID_ENEMY_BLUE_RIGHT_1,
		CHIP_ID_ENEMY_BLUE_DOWN_0,
		CHIP_ID_ENEMY_BLUE_DOWN_1,
		CHIP_ID_ENEMY_BLUE_LEFT_0,
		CHIP_ID_ENEMY_BLUE_LEFT_1,
		CHIP_ID_ENEMY_BLUE_UP_0,
		CHIP_ID_ENEMY_BLUE_UP_1,
		CHIP_ID_ENEMY_ORANGE_RIGHT_0,
		CHIP_ID_ENEMY_ORANGE_RIGHT_1,
		CHIP_ID_ENEMY_ORANGE_DOWN_0,
		CHIP_ID_ENEMY_ORANGE_DOWN_1,
		CHIP_ID_ENEMY_ORANGE_LEFT_0,
		CHIP_ID_ENEMY_ORANGE_LEFT_1,
		CHIP_ID_ENEMY_ORANGE_UP_0,
		CHIP_ID_ENEMY_ORANGE_UP_1,
		//バックグラウンドは線の向き四文字と線の位置、角の大きさを1文字の5文字で表現している
		CHIP_ID_BACK_GROUND_000010000,
		CHIP_ID_BACK_GROUND_010010000,
		CHIP_ID_BACK_GROUND_000010010,
		CHIP_ID_BACK_GROUND_000110000,
		CHIP_ID_BACK_GROUND_000011000,
		CHIP_ID_BACK_GROUND_010010010,
		CHIP_ID_BACK_GROUND_000111000,
		CHIP_ID_BACK_GROUND_010110000,
		CHIP_ID_BACK_GROUND_010011000,
		CHIP_ID_BACK_GROUND_000110010,
		CHIP_ID_BACK_GROUND_000011010,
		CHIP_ID_BACK_GROUND_010110010,
		CHIP_ID_BACK_GROUND_010011010,
		CHIP_ID_BACK_GROUND_010111000,
		CHIP_ID_BACK_GROUND_000111010,
		CHIP_ID_BACK_GROUND_010111010,
		CHIP_ID_BACK_GROUND_011111000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//CHIP_ID_BACK_GROUND_000010000,
		//ターゲットは名前で
		CHIP_ID_TARGET_CHERRY,
		CHIP_ID_TARGET_STRAWBERRY,
		CHIP_ID_TARGET_ORANGE,
		CHIP_ID_TARGET_APPLE,
		CHIP_ID_TARGET_MELON,
		CHIP_ID_TARGET_GS,
		CHIP_ID_TARGET_BELL,
		CHIP_ID_TARGET_KEY,
		CHIP_ID_TARGET_BATE,
		CHIP_ID_TARGET_POWER_BATE,
		CHIP_ID_MAX,
	};
private:
	enum GRAPH_ID {
		GRAPH_ID_PACMAN_LEFT,
		GRAPH_ID_PACMAN_RIGHT,
		GRAPH_ID_PACMAN_DOWN,
		GRAPH_ID_PACMAN_UP,
		GRAPH_ID_PACMAN_LD,
		GRAPH_ID_PACMAN_LU,
		GRAPH_ID_PACMAN_RD,
		GRAPH_ID_PACMAN_RU,
		GRAPH_ID_PACMAN_DEAD,
		GRAPH_ID_ENEMY,
		GRAPH_ID_TARGET,
		GRAPH_ID_BACK_GROUND,
	};
public:
	GraphManager( );
	virtual ~GraphManager( );
public:
	void drawChip( int x, int y, CHIP_ID id );
private:
	Drawer::Sprite getSprite( int x, int y, CHIP_ID id );
};

