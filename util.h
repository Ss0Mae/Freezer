#pragma once
#include <Windows.h>




int collision_pc_map(int dx, int dy);
int collision_pc_rock(int dx, int dy);
int collision_pc_gogildong(int dx, int dy);
int collision_pc_refrigerator();
void drawStage1(int isGildongRun, int idx);
void pc_melting();
void gildong_run(int i);
int processKeyInput();


int direction_flag = 1;


// pc와 맵 충돌
int collision_pc_map( int dx, int dy) {

	switch (curStage) {
	case 1: // stage1
		if (stage1_map[pc.arrY + dy][pc.arrX + dx] == 1) return 1;
		break;

	case 2: // stage2
		if (stage2_map[pc.arrY + dy][pc.arrX + dx] == 1) return 1;
		break;

	case 3: // stage3
		if (stage3_map[pc.arrY + dy][pc.arrX + dx] == 1) return 1;
		break;

	}

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
			walkCnt--;
			return 1;
		}
	}
	return 0;
}

int collision_pc_gogildong(int dx, int dy) { //pc와 길동 충돌
	for (int i = 0; i < 3; i++) {
		if (stage1_gildong[i].arrX == pc.arrX + dx && stage1_gildong[i].arrY == pc.arrY + dy) {
			if (stage1_map[stage1_gildong[i].arrY + dy][stage1_gildong[i].arrX + dx] == 1) { // 길동 뒤에 벽 (사라짐)
				walkCnt--;
				gildong_run(i); // 길동이 도망가는 에니메이션
				stage1_gildong[i].posX += dx * CELL_WIDTH * 1000;
				stage1_gildong[i].posY += dy * CELL_WIDTH * 1000;
				stage1_gildong[i].arrX += dx;
				stage1_gildong[i].arrY += dy;
				return 1;
			}
			for (int j = 0; j < 3; j++) { // 길동 뒤에 다른 길동이 있는 경우
				if (stage1_gildong[j].arrX == stage1_gildong[i].arrX + dx && stage1_gildong[j].arrY == stage1_gildong[i].arrY + dy) {
					walkCnt--;
					gildong_run(i); // 길동이 도망가는 에니메이션
					stage1_gildong[i].posX += dx * CELL_WIDTH * 1000;
					stage1_gildong[i].posY += dy * CELL_WIDTH * 1000;
					stage1_gildong[i].arrX += dx * 2;
					stage1_gildong[i].arrY += dy * 2;
					return 1;
				}
			}

			for (int j = 0; j < 4; j++) { // 길동 뒤에 바위가 있는 경우
				if (stage1_rocks[j].arrX == stage1_gildong[i].arrX + dx && stage1_rocks[j].arrY == stage1_gildong[i].arrY + dy)

					if (stage1_rocks[j].arrX == stage1_gildong[i].arrX + dx && stage1_rocks[j].arrY == stage1_gildong[i].arrY + dy) {
						walkCnt--;
						gildong_run(i); // 길동이 도망가는 에니메이션
						stage1_gildong[i].posX += dx * CELL_WIDTH * 1000;
						stage1_gildong[i].posY += dy * CELL_WIDTH * 1000;
						stage1_gildong[i].arrX += dx * 2;
						stage1_gildong[i].arrY += dy * 2;
						return 1;
					}
			}


			// 충돌한 길동은 한 칸 밀려야 함
			stage1_gildong[i].posX += dx * CELL_WIDTH;
			stage1_gildong[i].posY += dy * CELL_WIDTH;
			stage1_gildong[i].arrX += dx;
			stage1_gildong[i].arrY += dy;
			walkCnt--;
			return 1;

		}
	}
	return 0;
}

// pc와 냉장고 충돌 (스테이지 클리어)
int collision_pc_refrigerator() {
	if (stage1_refrigerator.arrX == pc.arrX && stage1_refrigerator.arrY == pc.arrY)
		return 1;
	return 0;
}


void drawStage1(int isGildongRun, int idx) {

	drawTexture(map1_img, 0, 0);
	drawTexture(refrigerator_img, stage1_refrigerator.posX, stage1_refrigerator.posY);
	drawTexture(roundCnt_img, 1062, 485);

	drawTexture(pc_img, pc.posX, pc.posY);

	if (!isGildongRun) {
		for (int i = 0; i < 3; i++) {
			drawTexture(gildong_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
		}
	}

	else {
		for (int i = 0; i < 3; i++) {
			if (idx == i) continue;
			drawTexture(gildong_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
		}
	}

	for (int i = 0; i < 4; i++) {
		drawTexture(rock_img, stage1_rocks[i].posX, stage1_rocks[i].posY);
	}

	if (walkCnt >= 0 && walkCnt <= 24)
		drawTexture(walkCnt_imgs[walkCnt], 136, 485);

}


void drawStage3(int isGildongRun, int idx) {

	drawTexture(map3_img, 0, 0);
	drawTexture(refrigerator_img, stage1_refrigerator.posX, stage1_refrigerator.posY);
	drawTexture(roundCnt_img, 1062, 485);

	drawTexture(pc_img, pc.posX, pc.posY);

	if (!isGildongRun) {
		for (int i = 0; i < 2; i++) {
			drawTexture(gildong_img, stage3_gildong[i].posX, stage3_gildong[i].posY);
		}
	}

	else {
		for (int i = 0; i < 2; i++) {
			if (idx == i) continue;
			drawTexture(gildong_img, stage3_gildong[i].posX, stage3_gildong[i].posY);
		}
	}


	if (walkCnt >= 0 && walkCnt <= 24)
		drawTexture(walkCnt_imgs[walkCnt], 136, 485);

}

void pc_melting() {
	if (direction_flag == 1) {
		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_right_melt2.png");
		drawStage1(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);

		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_right_melt3.png");
		drawStage1(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);
	}
	else {
		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_left_melt2.png");
		drawStage1(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);

		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_left_melt3.png");
		drawStage1(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);
	}
	pc_img = loadTexture("./assets/pc_left.png");
}

void gildong_run(int i) {

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_1.png");
	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_2.png");
	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_3.png");
	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_4.png");
	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_5.png");
	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

}



SDL_Event event;
int processKeyInput() {
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
			case 1073741903: // right
				direction_flag = 1;
				pc_img = loadTexture("./assets/pc_right.png");
				if (collision_pc_map( 1, 0)) break;
				if (collision_pc_rock(1, 0)) break;
				if (collision_pc_gogildong(1, 0) == 1) break;
				walkCnt--;
				pc.posX += CELL_WIDTH;
				pc.arrX++;
				break;
			case 1073741904: // left
				direction_flag = 0;
				pc_img = loadTexture("./assets/pc_left.png");
				if (collision_pc_map( -1, 0)) break;
				if (collision_pc_rock(-1, 0)) break;
				if (collision_pc_gogildong(-1, 0)) break;
				walkCnt--;
				pc.posX -= CELL_WIDTH;
				pc.arrX--;
				return 3;
				break;
			case 1073741905: // down
				if (collision_pc_map( 0, 1)) break;
				if (collision_pc_rock(0, 1)) break;
				if (collision_pc_gogildong(0, 1)) break;
				walkCnt--;
				pc.posY += CELL_WIDTH;
				pc.arrY++;
				break;
			case 1073741906: // up
				if (collision_pc_map( 0, -1)) break;
				if (collision_pc_rock(0, -1)) break;
				if (collision_pc_gogildong(0, -1)) break;
				walkCnt--;
				pc.posY -= CELL_WIDTH;
				pc.arrY--;
				break;
			case 27: // ESC
				exit(0);
				break;
			case 114: // R
				return -1;
				break;
			}
		return 1;
	}
}
