#pragma once
#include <Windows.h>


// pc와 맵 충돌
int collision_pc_map(int dx, int dy) {
	if (stage1_map[pc.arrY + dy][pc.arrX + dx] == 1) return 1;
	return 0;
}

// pc와 바위 충돌
int collision_pc_rock(int dx, int dy) {
	for (int i = 0; i < 4; i++) { // 바위 4개를 순회하며 각각 pc와 충돌검사
		if (stage1_rocks[i].arrX == pc.arrX + dx && stage1_rocks[i].arrY == pc.arrY + dy) {
			if (stage1_map[stage1_rocks[i].arrY + dy][stage1_rocks[i].arrX + dx] == 1) { // 바위 뒤에 벽이 있는 경우
				return 1;
			}
			for (int j = 0; j < 4; j++) { // 바위 뒤에 다른 바위가 있는 경우
				if (stage1_rocks[j].arrX == stage1_rocks[i].arrX + dx && stage1_rocks[j].arrY == stage1_rocks[i].arrY + dy)
					return 1;
			}

			for (int j = 0; j < 3; j++) { // 바위 뒤에 길동이 있는 경우
				if (stage1_gildong[j].arrX == stage1_rocks[i].arrX + dx && stage1_gildong[j].arrY == stage1_rocks[i].arrY + dy)
					return 1;
			}

			// 충돌한 바위는 한칸 밀려야 함
			stage1_rocks[i].posX += dx * CELL_WIDTH;
			stage1_rocks[i].posY += dy * CELL_WIDTH;
			stage1_rocks[i].arrX += dx;
			stage1_rocks[i].arrY += dy;
		}
	}
	return 0;
}

int collision_pc_gogildong(int dx, int dy) { //pc와 길동 충돌
	for (int i = 0; i < 3; i++) {
		if ( stage1_gildong[i].arrX == pc.arrX + dx && stage1_gildong[i].arrY == pc.arrY + dy) {
			if (stage1_map[stage1_gildong[i].arrY + dy][stage1_gildong[i].arrX + dx] == 1) { // 길동 뒤에 벽 (사라짐)
				Sleep(250);
				Sleep(250);
				Sleep(250);
				Sleep(250);
				stage1_gildong[i].posX += dx * CELL_WIDTH*1000;
				stage1_gildong[i].posY += dy * CELL_WIDTH*1000;
				stage1_gildong[i].arrX += dx;
				stage1_gildong[i].arrY += dy;
				return 1;
			}
			for (int j = 0; j < 3; j++) { // 길동 뒤에 다른 길동가 있는 경우
				if (stage1_gildong[j].arrX == stage1_gildong[i].arrX + dx && stage1_gildong[j].arrY == stage1_gildong[i].arrY + dy) {
					stage1_gildong[i].posX += dx * CELL_WIDTH * 1000;
					stage1_gildong[i].posY += dy * CELL_WIDTH * 1000;
					stage1_gildong[i].arrX += dx*2;
					stage1_gildong[i].arrY += dy*2;
					return 1;
				}
			}

			for (int j = 0; j < 3; j++) { // 길동 뒤에 바위가 있는 경우
				if (stage1_gildong[j].arrX == stage1_rocks[i].arrX + dx && stage1_gildong[j].arrY == stage1_rocks[i].arrY + dy)
					return 1;
			}

			// 충돌한 길동은 한 칸 밀려야 함
			stage1_gildong[i].posX += dx * CELL_WIDTH;
			stage1_gildong[i].posY += dy * CELL_WIDTH;
			stage1_gildong[i].arrX += dx;
			stage1_gildong[i].arrY += dy;
		}
	}
	return 0;
}
SDL_Event event;
void processKeyInput() {
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
			case 1073741903: // right
				if (collision_pc_map(1, 0)) break;
				if (collision_pc_rock(1, 0)) break;
				walkCnt--;
				if (collision_pc_gogildong(1, 0) == 1 ) break;
				pc.posX += CELL_WIDTH;
				pc.arrX++;
				break;
			case 1073741904: // left
				if (collision_pc_map(-1, 0)) break;
				if (collision_pc_rock(-1, 0)) break;
				walkCnt--;
				if (collision_pc_gogildong(-1, 0)) break;
				pc.posX -= CELL_WIDTH;
				pc.arrX--;
				break;
			case 1073741905: // down
				if (collision_pc_map(0, 1)) break;
				if (collision_pc_rock(0, 1)) break;
				walkCnt--;
				if (collision_pc_gogildong(0, 1)) break;
				pc.posY += CELL_WIDTH;
				pc.arrY++;
				break;
			case 1073741906: // up
				if (collision_pc_map(0, -1)) break;
				if (collision_pc_rock(0, -1)) break;
				walkCnt--;
				if (collision_pc_gogildong(0, -1)) break;
				pc.posY -= CELL_WIDTH;
				pc.arrY--;
				break;
			case 27: // ESC
				quit = true;
				break;
			}

	}
}


