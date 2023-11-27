#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"

void stage2_initPos() {
	pc.arrX = 1;
	pc.arrY = 5;

	stage2_gildong[0].arrX = 2;
	stage2_gildong[0].arrY = 2;

	stage2_gildong[1].arrX = 6;
	stage2_gildong[1].arrY = 5;

	stage2_gildong[2].arrX = 7;
	stage2_gildong[2].arrY = 6;

	stage2_rocks[0].arrX = 5;
	stage2_rocks[0].arrY = 3;

	stage2_rocks[1].arrX = 6;
	stage2_rocks[1].arrY = 3;

	stage2_rocks[2].arrX = 7;
	stage2_rocks[2].arrY = 3;

	stage2_crap[0].arrX = 2;
	stage2_crap[0].arrY = 3;

	stage2_crap[1].arrX = 5;
	stage2_crap[1].arrY = 2;

	stage2_crap[2].arrX = 6;
	stage2_crap[2].arrY = 2;

	stage2_crap[3].arrX = 6;
	stage2_crap[3].arrY = 3;

	stage2_crap[4].arrX = 7;
	stage2_crap[4].arrY = 3;

	stage2_crap[5].arrX = 7;
	stage2_crap[5].arrY = 4;

	stage2_refrigerator.arrX = 5;
	stage2_refrigerator.arrY = 6;

	walkCnt = 24;
}