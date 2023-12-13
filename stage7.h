#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage7_initPos() {

	// NPC, 아이템 위치 초기화
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
	// --------------------- 좌표찍기 ------------------------

	// pc
	pc.posX = 880;
	pc.posY = 340;
	pc.arrX = 6;
	pc.arrY = 5;

	// 길동
	gildongs[0].posX = pc.posX - CELL_WIDTH * 5;
	gildongs[0].posY = pc.posY - CELL_WIDTH * 1;
	gildongs[0].arrX = pc.arrX - 5;
	gildongs[0].arrY = pc.arrY - 1;

	gildongs[1].posX = pc.posX - CELL_WIDTH * 2;
	gildongs[1].posY = pc.posY - CELL_WIDTH * 1;
	gildongs[1].arrX = pc.arrX - 2;
	gildongs[1].arrY = pc.arrY - 1;

	/*gildongs[2].posX = pc.posX - CELL_WIDTH * 3;
	gildongs[2].posY = pc.posY + CELL_WIDTH * 0;
	gildongs[2].arrX = pc.arrX - 3;
	gildongs[2].arrY = pc.arrY + 0;*/

	/*gildongs[3].posX = pc.posX - CELL_WIDTH * 1;
	gildongs[3].posY = pc.posY - CELL_WIDTH * 2;
	gildongs[3].arrX = pc.arrX - 1;
	gildongs[3].arrY = pc.arrY - 2;*/

	// 바위
	rocks[0].posX = pc.posX - CELL_WIDTH * 2;
	rocks[0].posY = pc.posY - CELL_WIDTH * 2;
	rocks[0].arrX = pc.arrX - 2;
	rocks[0].arrY = pc.arrY - 2;


	rocks[1].posX = pc.posX - CELL_WIDTH * 1;
	rocks[1].posY = pc.posY - CELL_WIDTH * 2;
	rocks[1].arrX = pc.arrX - 1;
	rocks[1].arrY = pc.arrY - 2;

	rocks[2].posX = pc.posX + CELL_WIDTH * 0;
	rocks[2].posY = pc.posY - CELL_WIDTH * 2;
	rocks[2].arrX = pc.arrX + 0;
	rocks[2].arrY = pc.arrY - 2;


	rocks[3].posX = pc.posX - CELL_WIDTH * 4;
	rocks[3].posY = pc.posY - CELL_WIDTH * 1;
	rocks[3].arrX = pc.arrX - 4;
	rocks[3].arrY = pc.arrY - 1;


	rocks[4].posX = pc.posX - CELL_WIDTH * 1;
	rocks[4].posY = pc.posY - CELL_WIDTH * 1;
	rocks[4].arrX = pc.arrX - 1;
	rocks[4].arrY = pc.arrY - 1;


	// 냉장고
	refrigerator.posX = pc.posX - CELL_WIDTH * 2;
	refrigerator.posY = pc.posY - CELL_WIDTH * 4;
	refrigerator.arrX = pc.arrX - 2;
	refrigerator.arrY = pc.arrY - 4;


	// 게
	crabs[0].posX = pc.posX - CELL_WIDTH * 5;
	crabs[0].posY = pc.posY + CELL_WIDTH * 1;
	crabs[0].arrX = pc.arrX - 5;
	crabs[0].arrY = pc.arrY + 1;

	crabs[1].posX = pc.posX - CELL_WIDTH * 2;
	crabs[1].posY = pc.posY + CELL_WIDTH * 1;
	crabs[1].arrX = pc.arrX - 2;
	crabs[1].arrY = pc.arrY + 1;

	crabs[2].posX = pc.posX - CELL_WIDTH * 5;
	crabs[2].posY = pc.posY + CELL_WIDTH * 2;
	crabs[2].arrX = pc.arrX - 5;
	crabs[2].arrY = pc.arrY + 2;

	/*crabs[3].posX = pc.posX - CELL_WIDTH * 4;
	crabs[3].posY = pc.posY + CELL_WIDTH * 2;
	crabs[3].arrX = pc.arrX - 4;
	crabs[3].arrY = pc.arrY + 2;*/

	crabs[4].posX = pc.posX - CELL_WIDTH * 3;
	crabs[4].posY = pc.posY + CELL_WIDTH * 2;
	crabs[4].arrX = pc.arrX - 3;
	crabs[4].arrY = pc.arrY + 2;

	//crabs[5].posX = pc.posX - CELL_WIDTH * 2;
	//crabs[5].posY = pc.posY + CELL_WIDTH * 2;
	//crabs[5].arrX = pc.arrX - 2;
	//crabs[5].arrY = pc.arrY + 2;


	// 자물쇠
	door.posX = pc.posX - CELL_WIDTH * 1;
	door.posY = pc.posY - CELL_WIDTH * 3;
	door.arrX = pc.arrX - 1;
	door.arrY = pc.arrY - 3;


	// 키
	key.posX = pc.posX - CELL_WIDTH * 4;
	key.posY = pc.posY - CELL_WIDTH * 2;
	key.arrX = pc.arrX - 4;
	key.arrY = pc.arrY - 2;

	shield.posX = pc.posX - CELL_WIDTH * 3;
	shield.posY = pc.posY - CELL_WIDTH * 1;
	shield.arrX = pc.arrX - 3;
	shield.arrY = pc.arrY - 1;

	shoe.posX = pc.posX - CELL_WIDTH * 3;
	shoe.posY = pc.posY - CELL_WIDTH * 0;
	shoe.arrX = pc.arrX - 3;
	shoe.arrY = pc.arrY - 0;


	walkCnt = 33;
	walkForcrab = 0;
	key_flag = 0;
	shield_flag = 0;
	poison_flag = 0;
	poison_cnt = 0;
	bulkup_flag = 0;
	bulkup_cnt = 0;
	startTime = clock();

}

void stage7() {

	curStage = 7;
	stage7_initPos();
	crabUpDown();

	while (1) {
		SDL_RenderClear(renderer);


		if (processKeyInput() == -1) { // R키 누르면 재시작
			stage7_initPos();
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
			stage7_initPos();

		}
	}
}