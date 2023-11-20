#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"


// 메인 함수
int main(int argc, char** argv) {

	initAll();  // SDL 초기화 함수 호출

	player = loadTexture("player.png");  // 텍스처 로딩
	bg1 = loadTexture("bg1.png");

	bool quit = false;
	SDL_Event event;

	while (!quit) {
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case 1073741903: // right
					doraPosX += 10;
					break;
				case 1073741904: // left
					doraPosX -= 10;
					break;
				case 1073741905: // down
					doraPosY += 10;
					break;
				case 1073741906: // up
					doraPosY -= 10;
					break;
				case 27: // ESC
					quit = true;
					break;
				}
			}
		}
		drawTexture(bg1, 0, 0);  // 텍스처 그리기
		drawTexture(player, doraPosX, doraPosY);  // 텍스처 그리기
		SDL_RenderPresent(renderer);  // 렌더러 업데이트
	}


	closeAll();  // 메모리 해제
	return 0;
}
