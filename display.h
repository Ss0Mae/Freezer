#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "variable.h"
#include "sdl.h"

SDL_Texture* pc_img;
SDL_Texture* map1_img;
SDL_Texture* map2_img;
SDL_Texture* map3_img;
SDL_Texture* map4_img;
SDL_Texture* map5_img;
SDL_Texture* map6_img;
SDL_Texture* map7_img;
SDL_Texture* map8_img;
SDL_Texture* refrigerator_img;
SDL_Texture* gildong_img;
SDL_Texture* gildong_run_img;
SDL_Texture* rock_img;
SDL_Texture* walkCnt_imgs[100];
SDL_Texture* roundCnt_img[20];
SDL_Texture* game_clear_img;
SDL_Texture* game_over_img;
SDL_Texture* crab_img;
SDL_Texture* key_img;
SDL_Texture* door_img;
SDL_Texture* shoe_img;
SDL_Texture* bulkup_img;
SDL_Texture* poison_img;
SDL_Texture* shield_img;
SDL_Texture* timegage_img;
SDL_Texture* timerBody_img;
SDL_Texture* title_img;

void loadImg() {

	game_clear_img = loadTexture("./assets/game_clear.png");
	game_over_img = loadTexture("./assets/game_over.png");
	pc_img = loadTexture("./assets/pc_left.png");
	refrigerator_img = loadTexture("./assets/refrigerator.png");
	gildong_img = loadTexture("./assets/gildong.png");
	gildong_run_img = loadTexture("./assets/gildong_run_1.png");
	crab_img = loadTexture("./assets/crab_up.png");
	rock_img = loadTexture("./assets/rock.png");
	key_img = loadTexture("./assets/key.png");
	door_img = loadTexture("./assets/treasurebox.png");
	shoe_img = loadTexture("./assets/shoe.png");
	poison_img = loadTexture("./assets/poison.png");
	shield_img = loadTexture("./assets/shield.png");
	bulkup_img = loadTexture("./assets/bulkup.png");
	timegage_img = loadTexture("./assets/timegage.png");
	timerBody_img = loadTexture("./assets/timerBody.png");
	map1_img = loadTexture("./assets/map1.png");
	map2_img = loadTexture("./assets/map2.png");
	map3_img = loadTexture("./assets/map3.png");
	map4_img = loadTexture("./assets/map4.png");
	map5_img = loadTexture("./assets/map5.png");
	map6_img = loadTexture("./assets/map6.png");
	map7_img = loadTexture("./assets/map7.png");
	map8_img = loadTexture("./assets/map8.png");
	title_img = loadTexture("./assets/titleScreen.jpg");



	for (int i = 0; i <= 70; i++) {
		char path[70];
		sprintf(path, "./assets/walkCnt_%d.png", i);
		walkCnt_imgs[i] = loadTexture(path);
	}


	for (int i = 1; i <= 9; i++) {
		char path[50];
		sprintf(path, "./assets/roundCnt_%d.png", i);
		roundCnt_img[i] = loadTexture(path);
	}

}

void gameClear() {
	drawTexture(game_clear_img, 0, 0);
	SDL_RenderPresent(renderer);
	Sleep(1500);
	for (int i = 0; i < 20000; i++) SDL_PollEvent(&trashEvent);

}

void gameOver() {
	PlaySound((TEXT("./assets/gameOver.wav")), NULL, SND_ASYNC);
	drawTexture(game_over_img, 0, 0);
	SDL_RenderPresent(renderer);
	Sleep(1500);
	for (int i = 0; i < 20000; i++) SDL_PollEvent(&trashEvent);

}
