#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"



void stage1_initPos() {

	// pc
	pc.posX = 820;
	pc.posY = 120;
	pc.arrX = 6;
	pc.arrY = 1;

	// 길동
	stage1_gildong[0].posX = 680;
	stage1_gildong[0].posY = 200;
	stage1_gildong[0].arrX = 4;
	stage1_gildong[0].arrY = 2;

	stage1_gildong[1].posX = 610;
	stage1_gildong[1].posY = 270;
	stage1_gildong[1].arrX = 3;
	stage1_gildong[1].arrY = 3;


	stage1_gildong[2].posX = 750;
	stage1_gildong[2].posY = 270;
	stage1_gildong[2].arrX = 5;
	stage1_gildong[2].arrY = 3;

	// 바위
	stage1_rocks[0].posX = 540;
	stage1_rocks[0].posY = 446;
	stage1_rocks[0].arrX = 2;
	stage1_rocks[0].arrY = 5;


	stage1_rocks[1].posX = 540;
	stage1_rocks[1].posY = 516;
	stage1_rocks[1].arrX = 2;
	stage1_rocks[1].arrY = 6;


	stage1_rocks[2].posX = 680;
	stage1_rocks[2].posY = 516;
	stage1_rocks[2].arrX = 4;
	stage1_rocks[2].arrY = 6;

	stage1_rocks[3].posX = 750;
	stage1_rocks[3].posY = 446;
	stage1_rocks[3].arrX = 5;
	stage1_rocks[3].arrY = 5;

	

	walkCnt = 23;
}

void stage1() {

	stage1_initPos();

	while (!quit) {

		SDL_RenderClear(renderer);
		drawStage1(0, -1);
		SDL_RenderPresent(renderer);

		if (processKeyInput() == -1) { //R키 누르면 재시작
			stage1();
		}

		if (collision_pc_refrigerator()) quit = true;
		if (walkCnt == 0) {
			pc_melting();
			gameOver();
			stage1();
		}
	}
}