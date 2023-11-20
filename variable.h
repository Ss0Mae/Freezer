#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>


// 창의 크기
static const int width = 1440;
static const int height = 730;


int pcPosX = 820;
int pcPosY = 170;


SDL_Texture* player;
SDL_Texture* map1;
SDL_Texture* refrigerator;
SDL_Texture* gogildong1;
SDL_Texture* gogildong2;
SDL_Texture* gogildong3;
SDL_Texture* rock1;
SDL_Texture* rock2;
SDL_Texture* rock3;
SDL_Texture* rock4;

bool quit = false;


