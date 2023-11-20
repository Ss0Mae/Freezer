#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"


void stage1() {

	SDL_RenderClear(renderer);   // 렌더러 클리어

	drawTexture(map1, 0, 0);
	drawTexture(player, pcPosX, pcPosY);
	drawTexture(refrigerator, 890, 446);
	drawTexture(gogildong1, 680, 236);
	drawTexture(gogildong2, 610, 306);
	drawTexture(gogildong3, 750, 306);
	drawTexture(rock1, 540, 446);
	drawTexture(rock2, 540, 516);
	drawTexture(rock3, 680, 516);
	drawTexture(rock4, 750, 446);

	SDL_RenderPresent(renderer);

}