#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage6_initPos() {

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


	// --------------------- 좌표찍기 ------------------------

	// pc
	pc.posX = 500;
	pc.posY = 180;
	pc.arrX = 1;
	pc.arrY = 1;


	// 바위
	rocks[0].posX = pc.posX + CELL_WIDTH * 4;
	rocks[0].posY = pc.posY;
	rocks[0].arrX = pc.arrX + 4;
	rocks[0].arrY = pc.arrY;


	rocks[1].posX = pc.posX + CELL_WIDTH * 1;
	rocks[1].posY = pc.posY + CELL_WIDTH * 1;
	rocks[1].arrX = pc.arrX + 1;
	rocks[1].arrY = pc.arrY + 1;

	rocks[2].posX = pc.posX + CELL_WIDTH * 3;
	rocks[2].posY = pc.posY + CELL_WIDTH * 1;
	rocks[2].arrX = pc.arrX + 3;
	rocks[2].arrY = pc.arrY + 1;


	rocks[3].posX = pc.posX + CELL_WIDTH * 0;
	rocks[3].posY = pc.posY + CELL_WIDTH * 2;
	rocks[3].arrX = pc.arrX;
	rocks[3].arrY = pc.arrY + 2;


	rocks[4].posX = pc.posX + CELL_WIDTH * 2;
	rocks[4].posY = pc.posY + CELL_WIDTH * 2;
	rocks[4].arrX = pc.arrX + 2;
	rocks[4].arrY = pc.arrY + 2;


	rocks[5].posX = pc.posX + CELL_WIDTH * 4;
	rocks[5].posY = pc.posY + CELL_WIDTH * 2;
	rocks[5].arrX = pc.arrX + 4;
	rocks[5].arrY = pc.arrY + 2;


	rocks[6].posX = pc.posX + CELL_WIDTH * 5;
	rocks[6].posY = pc.posY + CELL_WIDTH * 2;
	rocks[6].arrX = pc.arrX + 5;
	rocks[6].arrY = pc.arrY + 2;

	rocks[7].posX = pc.posX + CELL_WIDTH * 1;
	rocks[7].posY = pc.posY + CELL_WIDTH * 3;
	rocks[7].arrX = pc.arrX + 1;
	rocks[7].arrY = pc.arrY + 3;

	rocks[8].posX = pc.posX + CELL_WIDTH * 3;
	rocks[8].posY = pc.posY + CELL_WIDTH * 3;
	rocks[8].arrX = pc.arrX + 3;
	rocks[8].arrY = pc.arrY + 3;

	rocks[9].posX = pc.posX + CELL_WIDTH * 5;
	rocks[9].posY = pc.posY + CELL_WIDTH * 3;
	rocks[9].arrX = pc.arrX + 5;
	rocks[9].arrY = pc.arrY + 3;

	rocks[10].posX = pc.posX + CELL_WIDTH * 6;
	rocks[10].posY = pc.posY + CELL_WIDTH * 3;
	rocks[10].arrX = pc.arrX + 6;
	rocks[10].arrY = pc.arrY + 3;

	rocks[11].posX = pc.posX + CELL_WIDTH * 2;
	rocks[11].posY = pc.posY + CELL_WIDTH * 4;
	rocks[11].arrX = pc.arrX + 2;
	rocks[11].arrY = pc.arrY + 4;

	rocks[12].posX = pc.posX + CELL_WIDTH * 4;
	rocks[12].posY = pc.posY + CELL_WIDTH * 4;
	rocks[12].arrX = pc.arrX + 4;
	rocks[12].arrY = pc.arrY + 4;


	// 냉장고
	refrigerator.posX = pc.posX + CELL_WIDTH * 7;
	refrigerator.posY = pc.posY + CELL_WIDTH * 2;
	refrigerator.arrX = pc.arrX + 7;
	refrigerator.arrY = pc.arrY + 2;


	// 게
	crabs[0].posX = pc.posX + CELL_WIDTH * 2;
	crabs[0].posY = pc.posY + CELL_WIDTH * 1;
	crabs[0].arrX = pc.arrX + 2;
	crabs[0].arrY = pc.arrY + 1;

	crabs[1].posX = pc.posX + CELL_WIDTH * 3;
	crabs[1].posY = pc.posY + CELL_WIDTH * 1;
	crabs[1].arrX = pc.arrX + 3;
	crabs[1].arrY = pc.arrY + 1;


	// 자물쇠
	door.posX = pc.posX + CELL_WIDTH * 5;
	door.posY = pc.posY + CELL_WIDTH * 1;
	door.arrX = pc.arrX + 5;
	door.arrY = pc.arrY + 1;


	// 키
	key.posX = pc.posX + CELL_WIDTH * 2;
	key.posY = pc.posY + CELL_WIDTH * 0;
	key.arrX = pc.arrX + 2;
	key.arrY = pc.arrY + 0;




	walkCnt = 24;
	walkForcrab = 0;
	key_flag = 0;
	shield_flag = 0;
}

void stage6() {

	curStage = 6;
	stage6_initPos();
	crabUpDown();

	while (1) {
		SDL_RenderClear(renderer);


		if (processKeyInput() == -1) { // R키 누르면 재시작
			stage6_initPos();
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
			stage6_initPos();

		}
	}
}