#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage2_initPos() {

	// 게임에 쓰이는 NPC를 제외하고는 게임 화면의 바깥쪽에 그려줌
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

	// pc
	pc.posX = 480;
	pc.posY = 390;
	pc.arrX = 1;
	pc.arrY = 5;
	pc.posX = 490;
	pc.posY = 400;

	// 길동
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


	// 바위
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

	// 냉장고
	refrigerator.posX = pc.posX + CELL_WIDTH * 4; 
	refrigerator.posY = pc.posY + CELL_WIDTH * 1; 
	refrigerator.arrX = pc.arrX + 4;
	refrigerator.arrY = pc.arrY + 1;

	// 게
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
}

void stage2() {

	curStage = 2;

	stage2_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput() == -1) { // R키 누르면 재시작
			stage2();
		}
		drawStage(0, -1);
		SDL_RenderPresent(renderer);

		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}


		if (walkCnt == 0) {
			pc_melting();
			gameOver();
			stage2();
		}
	}
}