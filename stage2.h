#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util2.h"
#include "sdl.h"
#include "util.h"

void stage2_initPos() {

	//pc초기 이미지 바꾸고 생성
	pc_img = loadTexture("assets/pc_right.png");
	pc.arrX = 1;
	pc.arrY = 5;
	pc.posX = 500;
	pc.posY = 390;

	//길동
	stage2_gildong[0].arrX = 2;
	stage2_gildong[0].arrY = 2;
	stage2_gildong[0].posX = 550;
	stage2_gildong[0].posY = 180;


	stage2_gildong[1].arrX = 6;
	stage2_gildong[1].arrY = 5;
	stage2_gildong[1].posX = 830;
	stage2_gildong[1].posY = 390;


	stage2_gildong[2].arrX = 7;
	stage2_gildong[2].arrY = 6;
	stage2_gildong[2].posX = 900;
	stage2_gildong[2].posY = 440;


	// 바위
	stage2_rocks[0].arrX = 5;
	stage2_rocks[0].arrY = 3;
	stage2_rocks[0].posX = 760;
	stage2_rocks[0].posY = 320;

	stage2_rocks[1].arrX = 6;
	stage2_rocks[1].arrY = 3;
	stage2_rocks[1].posX = 830;
	stage2_rocks[1].posY = 320;

	stage2_rocks[2].arrX = 7;
	stage2_rocks[2].arrY = 3;
	stage2_rocks[2].posX = 900;
	stage2_rocks[2].posY = 320;

	// 게
	stage2_crab[0].arrX = 2;
	stage2_crab[0].arrY = 3;
	stage2_crab[0].posX = 550;
	stage2_crab[0].posY = 250;

	stage2_crab[1].arrX = 4;
	stage2_crab[1].arrY = 2;
	stage2_crab[1].posX = 690;
	stage2_crab[1].posY = 180;

	stage2_crab[2].arrX = 5;
	stage2_crab[2].arrY = 2;
	stage2_crab[2].posX = 760;
	stage2_crab[2].posY = 180;
	
	stage2_crab[3].arrX = 5;
	stage2_crab[3].arrY = 3;
	stage2_crab[3].posX = 760;
	stage2_crab[3].posY = 250;

	stage2_crab[4].arrX = 6;
	stage2_crab[4].arrY = 3;
	stage2_crab[4].posX = 830;
	stage2_crab[4].posY = 250;

	stage2_crab[5].arrX = 6;
	stage2_crab[5].arrY = 4;
	stage2_crab[5].posX = 830;
	stage2_crab[5].posY = 320;
	// 냉장고
	stage2_refrigerator.arrX = 5;
	stage2_refrigerator.arrY = 6;
	stage2_refrigerator.posX = 780;
	stage2_refrigerator.posY = 440;


	walkCnt = 24;
}

void stage2() {

	stage2_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput_stage2() == -1) { // R키 누르면 재시작
			stage2();
		}
		drawStage2(0, -1);
		SDL_RenderPresent(renderer);

		if (collision_pc_refrigerator_stage2()) {
			return;
		}


		if (walkCnt <= 0) {
			pc_melting_stage2();
			gameOver();
			stage2();
		}
	}
}