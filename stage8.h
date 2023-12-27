#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage8_initPos() {

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

	shoe.posX = -100;
	shoe.posY = -100;
	shoe.arrX = -1;
	shoe.arrY = -1;

	shield.posX = -100;
	shield.posY = -100;
	shield.arrX = -1;
	shield.arrY = -1;

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
	pc.posX = 500;
	pc.posY = 460;
	pc.arrX = 2;
	pc.arrY = 6;


	// ����
	rocks[0].posX = pc.posX + CELL_WIDTH * 2;
	rocks[0].posY = pc.posY - CELL_WIDTH * 4;
	rocks[0].arrX = pc.arrX + 2;
	rocks[0].arrY = pc.arrY - 4;


	rocks[1].posX = pc.posX + CELL_WIDTH * 4;
	rocks[1].posY = pc.posY - CELL_WIDTH * 4;
	rocks[1].arrX = pc.arrX + 4;
	rocks[1].arrY = pc.arrY - 4;

	rocks[2].posX = pc.posX + CELL_WIDTH * 0;
	rocks[2].posY = pc.posY - CELL_WIDTH * 3;
	rocks[2].arrX = pc.arrX + 0;
	rocks[2].arrY = pc.arrY - 3;


	rocks[3].posX = pc.posX + CELL_WIDTH * 2;
	rocks[3].posY = pc.posY - CELL_WIDTH * 3;
	rocks[3].arrX = pc.arrX + 2;
	rocks[3].arrY = pc.arrY - 3;


	/*rocks[4].posX = pc.posX - CELL_WIDTH * 1;
	rocks[4].posY = pc.posY - CELL_WIDTH * 2;
	rocks[4].arrX = pc.arrX - 1;
	rocks[4].arrY = pc.arrY - 2;*/

	rocks[5].posX = pc.posX + CELL_WIDTH * 2;
	rocks[5].posY = pc.posY - CELL_WIDTH * 2;
	rocks[5].arrX = pc.arrX + 2;
	rocks[5].arrY = pc.arrY - 2;

	rocks[6].posX = pc.posX + CELL_WIDTH * 3;
	rocks[6].posY = pc.posY - CELL_WIDTH * 2;
	rocks[6].arrX = pc.arrX + 3;
	rocks[6].arrY = pc.arrY - 2;

	rocks[7].posX = pc.posX + CELL_WIDTH * 4;
	rocks[7].posY = pc.posY - CELL_WIDTH * 2;
	rocks[7].arrX = pc.arrX + 4;
	rocks[7].arrY = pc.arrY - 2;

	rocks[8].posX = pc.posX + CELL_WIDTH * 0;
	rocks[8].posY = pc.posY - CELL_WIDTH * 1;
	rocks[8].arrX = pc.arrX + 0;
	rocks[8].arrY = pc.arrY - 1;

	rocks[9].posX = pc.posX + CELL_WIDTH * 1;
	rocks[9].posY = pc.posY - CELL_WIDTH * 1;
	rocks[9].arrX = pc.arrX + 1;
	rocks[9].arrY = pc.arrY - 1;

	rocks[10].posX = pc.posX + CELL_WIDTH * 2;
	rocks[10].posY = pc.posY - CELL_WIDTH * 1;
	rocks[10].arrX = pc.arrX + 2;
	rocks[10].arrY = pc.arrY - 1;

	rocks[11].posX = pc.posX + CELL_WIDTH * 5;
	rocks[11].posY = pc.posY - CELL_WIDTH * 1;
	rocks[11].arrX = pc.arrX + 5;
	rocks[11].arrY = pc.arrY - 1;

	rocks[12].posX = pc.posX + CELL_WIDTH * 6;
	rocks[12].posY = pc.posY - CELL_WIDTH * 1;
	rocks[12].arrX = pc.arrX + 6;
	rocks[12].arrY = pc.arrY - 1;

	rocks[13].posX = pc.posX + CELL_WIDTH * 2;
	rocks[13].posY = pc.posY + CELL_WIDTH * 0;
	rocks[13].arrX = pc.arrX + 2;
	rocks[13].arrY = pc.arrY + 0;

	rocks[14].posX = pc.posX + CELL_WIDTH * 5;
	rocks[14].posY = pc.posY + CELL_WIDTH * 0;
	rocks[14].arrX = pc.arrX + 5;
	rocks[14].arrY = pc.arrY + 0;

	/*rocks[15].posX = pc.posX + CELL_WIDTH * 3;
	rocks[15].posY = pc.posY - CELL_WIDTH * 3;
	rocks[15].arrX = pc.arrX + 3;
	rocks[15].arrY = pc.arrY - 3;*/

	/*������ ��ġ ���� ����*/
	/*crabs[0].posX = pc.posX + CELL_WIDTH * 8;
	crabs[0].posY = pc.posY - CELL_WIDTH * 5;
	crabs[0].arrX = pc.arrX + 8;
	crabs[0].arrY = pc.arrY - 5;*/

	gildongs[0].posX = pc.posX + CELL_WIDTH * 7;
	gildongs[0].posY = pc.posY - CELL_WIDTH * 2;
	gildongs[0].arrX = pc.arrX + 7;
	gildongs[0].arrY = pc.arrY - 2;

	gildongs[1].posX = pc.posX + CELL_WIDTH * 10;
	gildongs[1].posY = pc.posY - CELL_WIDTH * 3;
	gildongs[1].arrX = pc.arrX + 10;
	gildongs[1].arrY = pc.arrY - 3;

	gildongs[2].posX = pc.posX + CELL_WIDTH * 9;
	gildongs[2].posY = pc.posY - CELL_WIDTH * 5;
	gildongs[2].arrX = pc.arrX + 9;
	gildongs[2].arrY = pc.arrY - 5;

	bulkup.posX = pc.posX - CELL_WIDTH * 1;
	bulkup.posY = pc.posY - CELL_WIDTH * 2;
	bulkup.arrX = pc.arrX - 1;
	bulkup.arrY = pc.arrY - 2;
	/*������ ��ġ ���� ��*/

	// �����
	refrigerator.posX = pc.posX + CELL_WIDTH * 3;
	refrigerator.posY = pc.posY - CELL_WIDTH * 5;
	refrigerator.arrX = pc.arrX + 3;
	refrigerator.arrY = pc.arrY - 5;



	// �ڹ���
	lock.posX = pc.posX + CELL_WIDTH * 3;
	lock.posY = pc.posY - CELL_WIDTH * 4;
	lock.arrX = pc.arrX + 3;
	lock.arrY = pc.arrY - 4;


	// Ű
	key.posX = pc.posX + CELL_WIDTH * 6;
	key.posY = pc.posY - CELL_WIDTH * 5;
	key.arrX = pc.arrX + 6;
	key.arrY = pc.arrY - 5;




	walkCnt = 63; //34
	walkForcrab = 0;
	key_flag = 0;
	shield_flag = 0;
	poison_flag = 0;
	poison_cnt = 0;
	bulkup_flag = 0;
	bulkup_cnt = 0;

	startTime = clock();

}

void stage8() {

	curStage = 8;
	stage8_initPos();
	crabUpDown();

	while (1) {
		SDL_RenderClear(renderer);


		if (processKeyInput() == -1) { // RŰ ������ �����
			stage8_initPos();
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
			stage8_initPos();
		}
	}
}