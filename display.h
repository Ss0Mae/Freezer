#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"

SDL_Texture* pc_img;
SDL_Texture* map1_img;
SDL_Texture* refrigerator_img;
SDL_Texture* gildong_img;
SDL_Texture* gildong_run_img;
SDL_Texture* rock_img;

SDL_Texture* walkCnt_imgs[24];

SDL_Texture* roundCnt_img;

void loadImg(){

pc_img = loadTexture("./assets/pc.png");
map1_img = loadTexture("./assets/map1.png");
refrigerator_img = loadTexture("./assets/refrigerator.png");
gildong_img = loadTexture("./assets/gildong.png");
gildong_run_img = loadTexture("./assets/gildong_run_1.png");
rock_img = loadTexture("./assets/rock.png");


for (int i = 0; i <= 23; i++) {
  char path[50]; 
  sprintf(path, "./assets/walkCnt_%d.png", i);
  walkCnt_imgs[i] = loadTexture(path);
}

roundCnt_img = loadTexture("./assets/roundCnt.png");
}


