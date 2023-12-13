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

	// 오디오 랙 제거용 더미사운드
	for (int i = 0; i < 5; i++) {
		PlaySound((TEXT("./assets/emptySound.wav")), NULL, SND_ASYNC | SND_LOOP);
		PlaySound((TEXT("./assets/emptySound2.wav")), NULL, SND_ASYNC | SND_LOOP);
		PlaySound((TEXT("./assets/emptySound3.wav")), NULL, SND_ASYNC | SND_LOOP);
	}


	// 타이틀 화면
	SDL_RenderClear(renderer);
	drawTexture(title_img, 0, 0);
	SDL_RenderPresent(renderer);

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen1.png");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen2.png");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen3.png");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/guideScreen4.png");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		return;
	}
}



void ending() {
	PlaySound((TEXT("./assets/endingSound.wav")), NULL, SND_ASYNC);
	SDL_RenderClear(renderer);
	drawTexture(end_img, 0, 0);
	SDL_RenderPresent(renderer);
	Sleep(3000);
	for (int i = 0; i < 30000; i++) SDL_PollEvent(&trashEvent);

	if (keyinputTitle() == 1) {
		return;
	}
}