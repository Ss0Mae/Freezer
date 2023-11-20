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


		for (int i = 0; i < 3; i++) {
			drawTexture(gildong_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
		}
		
		for (int i = 0; i < 4; i++) {
			drawTexture(rock_img, stage1_rocks[i].posX, stage1_rocks[i].posY);
		}

		SDL_RenderPresent(renderer);

	}
}