#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"
#include "display.h"
#include "stage1.h"


// 메인 함수
int main(int argc, char** argv) {

	initAll();  // SDL 초기화 함수 호출
	loadImg();
	SDL_Event event;

	while (!quit) {
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_KEYDOWN) 
				switch (event.key.keysym.sym) {
				case 1073741903: // right
					pcPosX += 70;
					break;
				case 1073741904: // left
					pcPosX -= 70;
					break;
				case 1073741905: // down
					pcPosY += 70;
					break;
				case 1073741906: // up
					pcPosY -= 70;
					break;
				case 27: // ESC
					quit = true;
					break;
				}
		}
	stage1();
	}


	closeAll();  // 메모리 해제
	return 0;
}
