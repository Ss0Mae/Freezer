#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"
#include "display.h"
#include "stage1.h"
#include "util.h"


// 메인 함수
int main(int argc, char** argv) {

	initAll();  // SDL 초기화 함수 호출
	loadImg();

	while (!quit) {
		
	processKeyInput();
	stage1();
	}


	closeAll();  // 메모리 해제
	return 0;
}
