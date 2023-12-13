#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


int keyinputTitle() {
	
	SDL_Event event;
	while (1) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
					return 1;
					break;
			}
		}
	}
}

void title() {
	// 타이틀 화면
	SDL_RenderClear(renderer);
	drawTexture(title_img, 0, 0);
	SDL_RenderPresent(renderer);

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen1.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen2.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen3.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen4.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		return;
	}
}

