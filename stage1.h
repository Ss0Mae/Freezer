#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"



void stage1() {

	while (!quit) {


		processKeyInput();
		SDL_RenderClear(renderer);

		drawTexture(map1_img, 0, 0);
		drawTexture(player_img, pc.posX, pc.posY);
		drawTexture(refrigerator_img, 890, 446);
		drawTexture(roundCnt_img, 1062, 485);
		if (walkCnt == 23) drawTexture(walkCnt_23_img, 136, 485);
		if (walkCnt == 22) drawTexture(walkCnt_22_img, 136, 485);
		if (walkCnt == 21) drawTexture(walkCnt_21_img, 136, 485);
		if (walkCnt == 20) drawTexture(walkCnt_20_img, 136, 485);
		if (walkCnt == 19) drawTexture(walkCnt_19_img, 136, 485);
		if (walkCnt == 18) drawTexture(walkCnt_18_img, 136, 485);
		if (walkCnt == 17) drawTexture(walkCnt_17_img, 136, 485);
		if (walkCnt == 16) drawTexture(walkCnt_16_img, 136, 485);
		if (walkCnt == 15) drawTexture(walkCnt_15_img, 136, 485);
		if (walkCnt == 14) drawTexture(walkCnt_14_img, 136, 485);
		if (walkCnt == 13) drawTexture(walkCnt_13_img, 136, 485);
		if (walkCnt == 12) drawTexture(walkCnt_12_img, 136, 485);
		if (walkCnt == 11) drawTexture(walkCnt_11_img, 136, 485);
		if (walkCnt == 10) drawTexture(walkCnt_10_img, 136, 485);
		if (walkCnt == 9) drawTexture(walkCnt_9_img, 136, 485);
		if (walkCnt == 8) drawTexture(walkCnt_8_img, 136, 485);
		if (walkCnt == 7) drawTexture(walkCnt_7_img, 136, 485);
		if (walkCnt == 6) drawTexture(walkCnt_6_img, 136, 485);
		if (walkCnt == 5) drawTexture(walkCnt_5_img, 136, 485);
		if (walkCnt == 4) drawTexture(walkCnt_4_img, 136, 485);
		if (walkCnt == 3) drawTexture(walkCnt_3_img, 136, 485);
		if (walkCnt == 2) drawTexture(walkCnt_2_img, 136, 485);
		if (walkCnt == 1) drawTexture(walkCnt_1_img, 136, 485);
		if (walkCnt == 0) drawTexture(walkCnt_0_img, 136, 485);

		for (int i = 0; i < 3; i++) {
			drawTexture(gildong_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
		}
		
		for (int i = 0; i < 4; i++) {
			drawTexture(rock_img, stage1_rocks[i].posX, stage1_rocks[i].posY);
		}

		SDL_RenderPresent(renderer);

	}
}