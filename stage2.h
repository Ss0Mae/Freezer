#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage2_initPos() {

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

	// --------------------- ��ǥ��� ------------------------

	// pc
	pc.posX = 480;
	pc.posY = 390;
	pc.arrX = 1;
	pc.arrY = 5;

	// �浿
	gildongs[0].posX = pc.posX + CELL_WIDTH * 1;
	gildongs[0].posY = pc.posY - CELL_WIDTH * 3;
	gildongs[0].arrX = pc.arrX + 1;
	gildongs[0].arrY = pc.arrY - 3;

	gildongs[1].posX = pc.posX + CELL_WIDTH * 5;
	gildongs[1].posY = pc.posY + CELL_WIDTH * 0;
	gildongs[1].arrX = pc.arrX + 5;
	gildongs[1].arrY = pc.arrY + 0;


	gildongs[2].posX = pc.posX + CELL_WIDTH * 6;
	gildongs[2].posY = pc.posY + CELL_WIDTH * 1;
	gildongs[2].arrX = pc.arrX + 6;
	gildongs[2].arrY = pc.arrY + 1;


	// ����
	rocks[0].posX = pc.posX + CELL_WIDTH * 4;
	rocks[0].posY = pc.posY - CELL_WIDTH * 2;
	rocks[0].arrX = pc.arrX + 4;
	rocks[0].arrY = pc.arrY - 2;


	rocks[1].posX = pc.posX + CELL_WIDTH * 5;
	rocks[1].posY = pc.posY - CELL_WIDTH * 2;
	rocks[1].arrX = pc.arrX + 5;
	rocks[1].arrY = pc.arrY - 2;


	rocks[2].posX = pc.posX + CELL_WIDTH * 6;
	rocks[2].posY = pc.posY - CELL_WIDTH * 2;
	rocks[2].arrX = pc.arrX + 6;
	rocks[2].arrY = pc.arrY - 2;

	// �����
	refrigerator.posX = pc.posX + CELL_WIDTH * 4; 
	refrigerator.posY = pc.posY + CELL_WIDTH * 1; 
	refrigerator.arrX = pc.arrX + 4;
	refrigerator.arrY = pc.arrY + 1;

	// ��
	crabs[0].posX = pc.posX + CELL_WIDTH * 1;
	crabs[0].posY = pc.posY - CELL_WIDTH * 2;
	crabs[0].arrX = pc.arrX + 1;
	crabs[0].arrY = pc.arrY - 2;

	crabs[1].posX = pc.posX + CELL_WIDTH * 3;
	crabs[1].posY = pc.posY - CELL_WIDTH * 3;
	crabs[1].arrX = pc.arrX + 3;
	crabs[1].arrY = pc.arrY - 3;

	crabs[2].posX = pc.posX + CELL_WIDTH * 4;
	crabs[2].posY = pc.posY - CELL_WIDTH * 3;
	crabs[2].arrX = pc.arrX + 4;
	crabs[2].arrY = pc.arrY - 3;

	crabs[3].posX = pc.posX + CELL_WIDTH * 4;
	crabs[3].posY = pc.posY - CELL_WIDTH * 2;
	crabs[3].arrX = pc.arrX + 4;
	crabs[3].arrY = pc.arrY - 2;

	crabs[4].posX = pc.posX + CELL_WIDTH * 5;
	crabs[4].posY = pc.posY - CELL_WIDTH * 2;
	crabs[4].arrX = pc.arrX + 5;
	crabs[4].arrY = pc.arrY - 2;

	crabs[5].posX = pc.posX + CELL_WIDTH * 5;
	crabs[5].posY = pc.posY - CELL_WIDTH * 1;
	crabs[5].arrX = pc.arrX + 5;
	crabs[5].arrY = pc.arrY - 1;
	walkCnt = 26;
	bulkup_flag = 0;
	bulkup_cnt = 0;
	startTime = clock();

}

void stage2() {

	curStage = 2;

	stage2_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput() == -1)  // RŰ ������ �����
			stage2_initPos();

		drawStage(0, -1);
		SDL_RenderPresent(renderer);

		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}


		if (walkCnt <= 0 || curTime > stageTime) {

			pc_melting();
			gameOver();
			stage2_initPos();
		}
	}
}