#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define CELL_WIDTH 70 // 게임판 한 칸의 너비

// 현재 몇 스테이지인지 저장할 변수
int curStage;

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

typedef struct Crap {
	int posX;
	int posY;

	int arrX;
	int arrY;
}Crap;
//남은 걸음수
int walkCnt;

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

/* 스테이지2 변수들 */

Rock stage2_rocks[3];
Gildong stage2_gildong[3];
Refrigerator stage2_refrigerator;
Crap stage2_crap[6];

int stage2_map[8][9] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1}
};




/* 스테이지3 변수들 */

Gildong stage3_gildong[2];
Refrigerator stage3_refrigerator;
Crap stage3_crap[8];

int stage3_map[9][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};