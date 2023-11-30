#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "sdl.h"

SDL_Texture* pc_img;
SDL_Texture* map1_img;
SDL_Texture* map2_img;
SDL_Texture* map3_img;
SDL_Texture* map4_img;
SDL_Texture* map5_img;
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
void loadImg() {

	pc_img = loadTexture("./assets/pc_left.png");
	refrigerator_img = loadTexture("./assets/refrigerator.png");
	gildong_img = loadTexture("./assets/gildong.png");
	gildong_run_img = loadTexture("./assets/gildong_run_1.png");
	crab_img = loadTexture("./assets/crab_up.png");
	rock_img = loadTexture("./assets/rock.png");
	key_img = loadTexture("./assets/key.png");
	door_img = loadTexture("./assets/treasurebox.png");
	map1_img = loadTexture("./assets/map1.png");
	map2_img = loadTexture("./assets/map2.png");
	map3_img = loadTexture("./assets/map3.png");
	map4_img = loadTexture("./assets/map4.png");
	map5_img = loadTexture("./assets/map5.png");

	for (int i = 0; i <= 50; i++) {
		char path[50];
		sprintf(path, "./assets/walkCnt_%d.png", i);
		walkCnt_imgs[i] = loadTexture(path);
	}


	for (int i = 1; i <= 5; i++) {
		char path[50];
		sprintf(path, "./assets/roundCnt_%d.png", i);
		roundCnt_img[i] = loadTexture(path);
	}

}

void gameClear() {
	game_clear_img = loadTexture("./assets/game_clear.png");
	drawTexture(game_clear_img, 0, 0);
	SDL_RenderPresent(renderer);
	Sleep(3000);
}

void gameOver() {
	game_over_img = loadTexture("./assets/game_over.png");
	drawTexture(game_over_img, 0, 0);
	SDL_RenderPresent(renderer);
	Sleep(3000);
}
