#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage5_initPos() {

	// NPC, ������ ��ġ �ʱ�ȭ
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		gildongs[i].posX = -100;
		gildongs[i].posY = -100;
		gildongs[i].arrX = -1;
		gildongs[i].arrY = -1;

		rocks[i].posX = -100;
		rocks[i].posY = -100;
		rocks[i].arrX = -1;
		rocks[i].arrY = -1;

		crabs[i].posX = -100;
		crabs[i].posY = -100;
		crabs[i].arrX = -1;
		crabs[i].arrY = -1;
	}
	key.posX = -100;
	key.posY = -100;
	key.arrX = -1;
	key.arrY = -1;

	lock.posX = -100;
	lock.posY = -100;
	lock.arrX = -1;
	lock.arrY = -1;

	shoe.posX = -100;
	shoe.posY = -100;
	shoe.arrX = -1;
	shoe.arrY = -1;

	poison.posX = -100;
	poison.posY = -100;
	poison.arrX = -1;
	poison.arrY = -1;

	bulkup.posX = -100;
	bulkup.posY = -100;
	bulkup.arrX = -1;
	bulkup.arrY = -1;

	shield.posX = -100;
	shield.posY = -100;
	shield.arrX = -1;
	shield.arrY = -1;

	// --------------------- ��ǥ��� ------------------------

	// pc
	pc.posX = 650;
	pc.posY = 40;
	pc.arrX = 3;
	pc.arrY = 1;

	// �浿
	gildongs[0].posX = pc.posX - CELL_WIDTH * 1;
	gildongs[0].posY = pc.posY + CELL_WIDTH * 4;
	gildongs[0].arrX = pc.arrX - 1;
	gildongs[0].arrY = pc.arrY + 4;

	gildongs[1].posX = pc.posX + CELL_WIDTH * 3;
	gildongs[1].posY = pc.posY + CELL_WIDTH * 5;
	gildongs[1].arrX = pc.arrX + 3;
	gildongs[1].arrY = pc.arrY + 5;


	// ����
	rocks[0].posX = pc.posX - CELL_WIDTH * 1;
	rocks[0].posY = pc.posY + CELL_WIDTH * 1;
	rocks[0].arrX = pc.arrX - 1;
	rocks[0].arrY = pc.arrY + 1;


	rocks[1].posX = pc.posX + CELL_WIDTH * 1;
	rocks[1].posY = pc.posY + CELL_WIDTH * 1;
	rocks[1].arrX = pc.arrX + 1;
	rocks[1].arrY = pc.arrY + 1;

	rocks[2].posX = pc.posX + CELL_WIDTH * 0;
	rocks[2].posY = pc.posY + CELL_WIDTH * 1;
	rocks[2].arrX = pc.arrX + 0;
	rocks[2].arrY = pc.arrY + 1;


	rocks[3].posX = pc.posX + CELL_WIDTH * 1;
	rocks[3].posY = pc.posY + CELL_WIDTH * 4;
	rocks[3].arrX = pc.arrX + 1;
	rocks[3].arrY = pc.arrY + 4;


	rocks[4].posX = pc.posX + CELL_WIDTH * 2;
	rocks[4].posY = pc.posY + CELL_WIDTH * 4;
	rocks[4].arrX = pc.arrX + 2;
	rocks[4].arrY = pc.arrY + 4;


	rocks[5].posX = pc.posX + CELL_WIDTH * 1;
	rocks[5].posY = pc.posY + CELL_WIDTH * 5;
	rocks[5].arrX = pc.arrX + 1;
	rocks[5].arrY = pc.arrY + 5;


	rocks[6].posX = pc.posX + CELL_WIDTH * 3;
	rocks[6].posY = pc.posY + CELL_WIDTH * 6;
	rocks[6].arrX = pc.arrX + 3;
	rocks[6].arrY = pc.arrY + 6;

	rocks[7].posX = pc.posX + CELL_WIDTH * 0;
	rocks[7].posY = pc.posY + CELL_WIDTH * 3;
	rocks[7].arrX = pc.arrX + 0;
	rocks[7].arrY = pc.arrY + 3;


	// �����
	refrigerator.posX = pc.posX + CELL_WIDTH * 3;
	refrigerator.posY = pc.posY + CELL_WIDTH * 7;
	refrigerator.arrX = pc.arrX + 3;
	refrigerator.arrY = pc.arrY + 7;


	// ��
	crabs[0].posX = pc.posX + CELL_WIDTH * 0;
	crabs[0].posY = pc.posY + CELL_WIDTH * 3;
	crabs[0].arrX = pc.arrX + 0;
	crabs[0].arrY = pc.arrY + 3;

	crabs[1].posX = pc.posX - CELL_WIDTH * 1;
	crabs[1].posY = pc.posY + CELL_WIDTH * 3;
	crabs[1].arrX = pc.arrX - 1;
	crabs[1].arrY = pc.arrY + 3;


	// �ڹ���
	lock.posX = pc.posX + CELL_WIDTH * 2;
	lock.posY = pc.posY + CELL_WIDTH * 6;
	lock.arrX = pc.arrX + 2;
	lock.arrY = pc.arrY + 6;


	// Ű
	key.posX = pc.posX + CELL_WIDTH * 1;
	key.posY = pc.posY + CELL_WIDTH * 2;
	key.arrX = pc.arrX + 1;
	key.arrY = pc.arrY + 2;


	// �Ź�
	shoe.posX = pc.posX + CELL_WIDTH * 2;
	shoe.posY = pc.posY + CELL_WIDTH * 4;
	shoe.arrX = pc.arrX + 2;
	shoe.arrY = pc.arrY + 4;


	walkCnt = 42;
	walkForcrab = 0;
	key_flag = 0;
	shield_flag = 0;
	poison_flag = 0;
	poison_cnt = 0;
	bulkup_flag = 0;
	bulkup_cnt = 0;
	startTime = clock();

}

void stage5() {
	
	curStage = 5;
	stage5_initPos();
	crabUpDown();

	while (1) {
		SDL_RenderClear(renderer);


		if (processKeyInput() == -1) { // RŰ ������ �����
			stage5_initPos();
			crabUpDown();
		}

		drawStage(0, -1);

		SDL_RenderPresent(renderer);


		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}

		if (walkCnt <= 0 || curTime > stageTime) {
			pc_melting();
			gameOver();
			crabUpDown();
			stage5_initPos();

		}
	}
}