#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "stage2.h"


void stage1_initPos() {

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

	// --------------------- 좌표찍기 ------------------------

	// pc
	pc.posX = 830;
	pc.posY = 110;
	pc.arrX = 6;
	pc.arrY = 1;

	// 길동
	gildongs[0].posX = pc.posX + CELL_WIDTH * -1;
	gildongs[0].posY = pc.posY + CELL_WIDTH * 2;
	gildongs[0].arrX = pc.arrX + -1;
	gildongs[0].arrY = pc.arrY + 2;

	gildongs[1].posX = pc.posX + CELL_WIDTH * -2;
	gildongs[1].posY = pc.posY + CELL_WIDTH * 1;
	gildongs[1].arrX = pc.arrX + -2;
	gildongs[1].arrY = pc.arrY + 1;


	gildongs[2].posX = pc.posX + CELL_WIDTH * -3;
	gildongs[2].posY = pc.posY + CELL_WIDTH * 2;
	gildongs[2].arrX = pc.arrX + -3;
	gildongs[2].arrY = pc.arrY + 2;


	// 바위
	rocks[0].posX = pc.posX + CELL_WIDTH * -1;
	rocks[0].posY = pc.posY + CELL_WIDTH * 4;
	rocks[0].arrX = pc.arrX + -1;
	rocks[0].arrY = pc.arrY + 4;


	rocks[1].posX = pc.posX + CELL_WIDTH * -4;
	rocks[1].posY = pc.posY + CELL_WIDTH * 4;
	rocks[1].arrX = pc.arrX + -4;
	rocks[1].arrY = pc.arrY + 4;


	rocks[2].posX = pc.posX + CELL_WIDTH * -2;
	rocks[2].posY = pc.posY + CELL_WIDTH * 5;
	rocks[2].arrX = pc.arrX + -2;
	rocks[2].arrY = pc.arrY + 5;

	rocks[3].posX = pc.posX + CELL_WIDTH * -4;
	rocks[3].posY = pc.posY + CELL_WIDTH * 5;
	rocks[3].arrX = pc.arrX + -4;
	rocks[3].arrY = pc.arrY + 5;

	// 냉장고
	refrigerator.posX = pc.posX + CELL_WIDTH * 1;
	refrigerator.posY = pc.posY + CELL_WIDTH * 5;
	refrigerator.arrX = pc.arrX + 1;
	refrigerator.arrY = pc.arrY + 5;

	walkCnt = 24;
}

void stage1() {

	curStage = 1;
	stage1_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput() == -1)  // R키 누르면 재시작
			stage1_initPos();

		drawStage(0, -1);
		SDL_RenderPresent(renderer);

		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}

		if (walkCnt <= 0) {
			pc_melting();
			gameOver();
			stage1_initPos();
		}
	}
}