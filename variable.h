#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define CELL_WIDTH 70 // 게임판 한 칸의 너비

typedef struct Pc {

	// 화면에서 pc위치
	int posX;
	int posY;

	// 게임판 배열에서 pc위치
	int arrX;
	int arrY;
}Pc;

typedef struct Rock {

	// 화면에서 바위 위치
	int posX;
	int posY;

	// 게임판 배열에서 바위 위치
	int arrX;
	int arrY;
}Rock;

typedef struct Gildong {


	// 화면에서 길동의 위치
	int posX;
	int posY;

	// 게임판 배열에서 길동의 위치
	int arrX;
	int arrY;
}Gildong;

typedef struct Refrigerator {

	//화면에서 냉장고의 위치
	int posX;
	int posY;

	// 게임판 배열에서 냉장고의 위치
	int arrX;
	int arrY;
}Refrigerator;

//걸음수
int walkCnt=23;

// 창의 크기
static const int width = 1440;
static const int height = 730;

Pc pc;
Rock stage1_rocks[4];
Gildong stage1_gildong[3];
Refrigerator stage1_refrigerator;

int stage1_map[8][9] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 1, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
};

