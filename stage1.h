#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"



void stage1() {


	while (!quit) {

	SDL_RenderClear(renderer);
		drawStage1(0, -1);
	SDL_RenderPresent(renderer);

		processKeyInput();

		if (collision_pc_refrigerator()) quit = true;
		
	}
}