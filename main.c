#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"
#include "display.h"
#include "stage1.h"
#include "util.h"


int main(int argc, char** argv) {

	initAll(); // SDL 초기화
	loadImg();
		
	stage1();

	closeAll(); // SDL 메모리 해제
	return 0;
}
