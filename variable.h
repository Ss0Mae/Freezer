#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>


SDL_Window* window;         // SDL 창을 나타내는 포인터 변수
SDL_Renderer* renderer;     // SDL 렌더러를 나타내는 포인터 변수



// 창의 크기
static const int width = 1200;
static const int height = 800;


SDL_Texture* dora;
int doraPosX, doraPosY;

