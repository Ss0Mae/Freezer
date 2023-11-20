#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "variable.h"



// SDL 관련함수들 넣으세요


// 초기화 함수
static int initAll()
{
	if (SDL_Init(SDL_INIT_EVENTS) != 0)  // SDL 초기화
	{
		fprintf(stderr, "%s\n", (SDL_GetError()));
		return (0);
	}

	// SDL 창 생성
	window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	if (window == 0)
	{
		fprintf(stderr, "%s\n", (SDL_GetError()));
		return (0);
	}

	// 렌더러 생성 (가속화 및 디스플레이 주사율과 동기화)
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == 0)
	{
		fprintf(stderr, "%s\n", (SDL_GetError()));
		return (0);
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))  // SDL_image 초기화
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return (0);
	}

	return (1);
}





// SDL 종료 함수
static void closeAll()
{
	// 사용한 이미지 메모리 모두 해제하세요
	SDL_DestroyTexture(dora);  // 텍스처 해제


	SDL_DestroyRenderer(renderer);  // 렌더러 해제
	SDL_DestroyWindow(window);      // 창 해제
	IMG_Quit();                     // SDL_image 종료
	SDL_Quit();                     // SDL 종료
}

// 텍스처 로딩 함수
SDL_Texture* loadTexture(const char* file) {
	SDL_Surface* surface;
	SDL_Texture* texture;

	surface = IMG_Load(file);
	if (surface == NULL) {
		printf("fail to read %s\n", file);
		return NULL;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
		printf("unable to create texture.\n");
	}

	SDL_FreeSurface(surface);

	return texture;
}


// 텍스처 그리기 함수
void drawTexture(SDL_Texture* texture, int x, int y) {
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, texture, &src, &dst);
}
