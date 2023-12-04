#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage5_initPos() {

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
	key.posX = -100;
	key.posY = -100;
	key.arrX = -1;
	key.arrY = -1;

	door.posX = -100;
	door.posY = -100;
	door.arrX = -1;
	door.arrY = -1;

	shoe.posX = -100;
	shoe.posY = -100;
	shoe.arrX = -1;
	shoe.arrY = -1;

	poison.posX = -100;
	poison.posY = -100;
	poison.arrX = -1;
	poison.arrY = -1;

	walkForcrab = 45;

	// --------------------- 좌표찍기 ------------------------

	// pc
	pc.posX = 650;
	pc.posY = 40;
	pc.arrX = 3;
	pc.arrY = 1;

	// 길동
	gildongs[0].posX = pc.posX - CELL_WIDTH * 1;
	gildongs[0].posY = pc.posY + CELL_WIDTH * 4;
	gildongs[0].arrX = pc.arrX - 1;
	gildongs[0].arrY = pc.arrY + 4;

	gildongs[1].posX = pc.posX + CELL_WIDTH * 3;
	gildongs[1].posY = pc.posY + CELL_WIDTH * 5;
	gildongs[1].arrX = pc.arrX + 3;
	gildongs[1].arrY = pc.arrY + 5;


	// 바위
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


	// 냉장고
	refrigerator.posX = pc.posX + CELL_WIDTH * 3;
	refrigerator.posY = pc.posY + CELL_WIDTH * 7;
	refrigerator.arrX = pc.arrX + 3;
	refrigerator.arrY = pc.arrY + 7;


	// 게
	crabs[0].posX = pc.posX + CELL_WIDTH * 0;
	crabs[0].posY = pc.posY + CELL_WIDTH * 3;
	crabs[0].arrX = pc.arrX + 0;
	crabs[0].arrY = pc.arrY + 3;

	crabs[1].posX = pc.posX - CELL_WIDTH * 1;
	crabs[1].posY = pc.posY + CELL_WIDTH * 3;
	crabs[1].arrX = pc.arrX - 1;
	crabs[1].arrY = pc.arrY + 3;


	// 자물쇠
	door.posX = pc.posX + CELL_WIDTH * 2;
	door.posY = pc.posY + CELL_WIDTH * 6;
	door.arrX = pc.arrX + 2;
	door.arrY = pc.arrY + 6;


	// 키
	key.posX = pc.posX + CELL_WIDTH * 1;
	key.posY = pc.posY + CELL_WIDTH * 2;
	key.arrX = pc.arrX + 1;
	key.arrY = pc.arrY + 2;


	// 신발
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
}

void stage5() {
	
	curStage = 5;
	stage5_initPos();
	crabUpDown();

	while (1) {
		SDL_RenderClear(renderer);


		if (processKeyInput() == -1) { // R키 누르면 재시작
			stage5_initPos();
			crabUpDown();
		}

		drawStage(0, -1);

		SDL_RenderPresent(renderer);


		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}

		if (walkCnt <= 0) {
			pc_melting();
			gameOver();
			crabUpDown();
			stage5_initPos();

		}
	}
}