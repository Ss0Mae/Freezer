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
SDL_Texture* refrigerator_img;
SDL_Texture* gildong_img;
SDL_Texture* gildong_run_img;
SDL_Texture* rock_img;
SDL_Texture* walkCnt_imgs[100];
SDL_Texture* roundCnt_img;
SDL_Texture* game_clear_img;
SDL_Texture* game_over_img;
SDL_Texture* crab_img;

void loadImg(){

pc_img = loadTexture("./assets/pc_left.png");
map1_img = loadTexture("./assets/map1.png");
refrigerator_img = loadTexture("./assets/refrigerator.png");
gildong_img = loadTexture("./assets/gildong.png");
gildong_run_img = loadTexture("./assets/gildong_run_1.png");
rock_img = loadTexture("./assets/rock.png");
map2_img = loadTexture("./assets/map2.png");
crab_img = loadTexture("./assets/crab_up.png");

for (int i = 0; i <= 24; i++) {
  char path[50]; 
  sprintf(path, "./assets/walkCnt_%d.png", i);
  walkCnt_imgs[i] = loadTexture(path);
}

roundCnt_img = loadTexture("./assets/roundCnt.png");
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
