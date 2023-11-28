#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage3_initPos() {

	// pc
	pc.posX = 920;
	pc.posY = 220;
	pc.arrX = 8;
	pc.arrY = 3;

	// 길동
	stage3_gildong[0].posX = 680;
	stage3_gildong[0].posY = 200;
	stage3_gildong[0].arrX = 4;
	stage3_gildong[0].arrY = 2;

	stage3_gildong[1].posX = 610;
	stage3_gildong[1].posY = 270;
	stage3_gildong[1].arrX = 3;
	stage3_gildong[1].arrY = 3;


	// 냉장고
	stage3_refrigerator.posX = 890;
	stage3_refrigerator.posY = 446;
	stage3_refrigerator.arrX = 7;
	stage3_refrigerator.arrY = 6;


	walkCnt = 32;
}

void stage3() {

	curStage = 3;

	stage3_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput() == -1) { // R키 누르면 재시작
			stage3();
		}
		drawStage3(0, -1);
		SDL_RenderPresent(renderer);

		if (collision_pc_refrigerator()) {
			stage3();
		}



		if (walkCnt == 0) {
			//pc_melting();
			gameOver();
			stage3();
		}
	}
}