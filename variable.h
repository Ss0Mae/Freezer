#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define CELL_WIDTH 70 // 게임판 한 칸의 너비
#define MAX_NUM_NPC 30 // NPC 최대 개수

// 현재 몇 스테이지인지 저장할 변수
int curStage;

// 걸음 여부에 따른 게 이미지 변화를 위한 변수
int walkForcrab;

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

typedef struct Crab {
	int posX;
	int posY;

	int arrX;
	int arrY;
}Crab;

typedef struct Key{
	int posX;
	int posY;

	int arrX;
	int arrY;
}Key;

typedef struct Door {
	int posX;
	int posY;

	int arrX;
	int arrY;
}Door;

typedef struct Shoe {
	int posX;
	int posY;

	int arrX;
	int arrY;
}Shoe;

//남은 걸음수
int walkCnt=23;

// 창의 크기
static const int width = 1440;
static const int height = 730;

Pc pc;
Refrigerator refrigerator;
Rock rocks[MAX_NUM_NPC];
Gildong gildongs[MAX_NUM_NPC];
Crab crabs[MAX_NUM_NPC];
Key key;
Door door; 
Shoe shoe; 

int maps[10][15][15] = {
	{{0}},

	// 스테이지 1
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 1, 1, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	},


	// 스테이지 2
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	},


	// 스테이지 3
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	},


	// 스테이지 4  
	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
	},


	// 스테이지 5
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	}


};

