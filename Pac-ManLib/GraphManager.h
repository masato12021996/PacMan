#pragma once
#include "Drawer.h"
#include "smart_ptr.h"

PTR( GraphManager );

class GraphManager {
public:
	enum CHIP_ID {
		//�p�b�N�}���̓A�j���[�V����
		CHIP_ID_PACMAN_1,
		CHIP_ID_PACMAN_2,
		CHIP_ID_PACMAN_3,
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
		//�G�͐F�ƌ����ƃA�j���[�V�����ԍ�
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
		//�o�b�N�O���E���h�͐��̌����l�����Ɛ��̈ʒu�A�p�̑傫����1������5�����ŕ\�����Ă���
		CHIP_ID_BACK_GROUND_U_L_S,
		CHIP_ID_BACK_GROUND_U__RS,
		CHIP_ID_BACK_GROUND__DL_S,
		CHIP_ID_BACK_GROUND__D_RS,
		CHIP_ID_BACK_GROUND___LRD,
		CHIP_ID_BACK_GROUND___LRU,
		CHIP_ID_BACK_GROUND_UD__L,
		CHIP_ID_BACK_GROUND_UD__R,
		CHIP_ID_BACK_GROUND_U_L_B,
		CHIP_ID_BACK_GROUND_U__RB,
		CHIP_ID_BACK_GROUND__DL_B,
		CHIP_ID_BACK_GROUND__D_RB,
		//�^�[�Q�b�g�͖��O��
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
		GRAPH_ID_PACMAN,
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
