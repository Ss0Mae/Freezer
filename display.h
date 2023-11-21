#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"


SDL_Texture* player_img;
SDL_Texture* map1_img;
SDL_Texture* refrigerator_img;
SDL_Texture* gildong_img;
SDL_Texture* rock_img;
SDL_Texture* walkCnt_0_img;
SDL_Texture* walkCnt_1_img;
SDL_Texture* walkCnt_2_img;
SDL_Texture* walkCnt_3_img;
SDL_Texture* walkCnt_4_img;
SDL_Texture* walkCnt_5_img;
SDL_Texture* walkCnt_6_img;
SDL_Texture* walkCnt_7_img;
SDL_Texture* walkCnt_8_img;
SDL_Texture* walkCnt_9_img;
SDL_Texture* walkCnt_10_img;
SDL_Texture* walkCnt_11_img;
SDL_Texture* walkCnt_12_img;
SDL_Texture* walkCnt_13_img;
SDL_Texture* walkCnt_14_img;
SDL_Texture* walkCnt_15_img;
SDL_Texture* walkCnt_16_img;
SDL_Texture* walkCnt_17_img;
SDL_Texture* walkCnt_18_img;
SDL_Texture* walkCnt_19_img;
SDL_Texture* walkCnt_20_img;
SDL_Texture* walkCnt_21_img;
SDL_Texture* walkCnt_22_img;
SDL_Texture* walkCnt_23_img;
SDL_Texture* roundCnt_img;

void loadImg(){

player_img = loadTexture("./assets/player.png");
map1_img = loadTexture("./assets/map1.png");
refrigerator_img = loadTexture("./assets/refrigerator.png");
gildong_img = loadTexture("./assets/gildong.png");
rock_img = loadTexture("./assets/rock.png");
walkCnt_0_img = loadTexture("./assets/walkCnt_0.png");
walkCnt_1_img = loadTexture("./assets/walkCnt_1.png");
walkCnt_2_img = loadTexture("./assets/walkCnt_2.png");
walkCnt_3_img = loadTexture("./assets/walkCnt_3.png");
walkCnt_4_img = loadTexture("./assets/walkCnt_4.png");
walkCnt_5_img = loadTexture("./assets/walkCnt_5.png");
walkCnt_6_img = loadTexture("./assets/walkCnt_6.png");
walkCnt_7_img = loadTexture("./assets/walkCnt_7.png");
walkCnt_8_img = loadTexture("./assets/walkCnt_8.png");
walkCnt_9_img = loadTexture("./assets/walkCnt_9.png");
walkCnt_10_img = loadTexture("./assets/walkCnt_10.png");
walkCnt_11_img = loadTexture("./assets/walkCnt_11.png");
walkCnt_12_img = loadTexture("./assets/walkCnt_12.png");
walkCnt_13_img = loadTexture("./assets/walkCnt_13.png");
walkCnt_14_img = loadTexture("./assets/walkCnt_14.png");
walkCnt_15_img = loadTexture("./assets/walkCnt_15.png");
walkCnt_16_img = loadTexture("./assets/walkCnt_16.png");
walkCnt_17_img = loadTexture("./assets/walkCnt_17.png");
walkCnt_18_img = loadTexture("./assets/walkCnt_18.png");
walkCnt_19_img = loadTexture("./assets/walkCnt_19.png");
walkCnt_20_img = loadTexture("./assets/walkCnt_20.png");
walkCnt_21_img = loadTexture("./assets/walkCnt_21.png");
walkCnt_22_img = loadTexture("./assets/walkCnt_22.png");
walkCnt_23_img = loadTexture("./assets/walkCnt_23.png");
roundCnt_img = loadTexture("./assets/roundCnt.png");
}


