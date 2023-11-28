#pragma once
#include <Windows.h>

int collision_pc_map(int dx, int dy);
int collision_pc_rock(int dx, int dy);
int collision_pc_gogildong(int dx, int dy);
int collision_pc_refrigerator();
int processKeyInput();
void gildong_run(int i);
void pc_melting();
void drawStage(int isGildongRun, int idx);

int direction_flag = 1;
int key_flag = 0;


// pc와 맵 충돌
int collision_pc_map(int dx, int dy) {
	if (maps[curStage][pc.arrY + dy][pc.arrX + dx] == 1) return 1;
	return 0;
}


// pc와 바위 충돌
int collision_pc_rock(int dx, int dy) {
	for (int i = 0; i < MAX_NUM_NPC; i++) { // 바위를 순회하며 각각 pc와 충돌검사
		if (rocks[i].arrX == pc.arrX + dx && rocks[i].arrY == pc.arrY + dy) {
			if (maps[curStage][rocks[i].arrY + dy][rocks[i].arrX + dx] == 1) { // 바위 뒤에 벽이 있는 경우
				return 1;
			}
			for (int j = 0; j < MAX_NUM_NPC; j++) { // 바위 뒤에 다른 바위가 있는 경우
				if (rocks[j].arrX == rocks[i].arrX + dx && rocks[j].arrY == rocks[i].arrY + dy)
					return 1;
			}

			for (int j = 0; j < MAX_NUM_NPC; j++) { // 바위 뒤에 길동이 있는 경우
				if (gildongs[j].arrX == rocks[i].arrX + dx && gildongs[j].arrY == rocks[i].arrY + dy)
					return 1;
			}


			// 충돌한 바위는 한칸 밀려야 함
			rocks[i].posX += dx * CELL_WIDTH;
			rocks[i].posY += dy * CELL_WIDTH;
			rocks[i].arrX += dx;
			rocks[i].arrY += dy;
			walkCnt--;
			return 1;
		}
	}
	return 0;
}




void pc_damage() {

	// pc의 색이 변함
	pc_img = direction_flag == 1 ? loadTexture("./assets/pc_right_damage.png") : loadTexture("./assets/pc_left_damage.png");

	// 키 입력 받으면서 시간때우기
	for (int i = 0; i < 20; i++) {
		SDL_RenderClear(renderer);
		drawStage(0, -1);
		SDL_RenderPresent(renderer);
		processKeyInput();
		Sleep(20);
	}

	// 원래 색깔로 돌아옴
	pc_img = direction_flag == 1 ? loadTexture("./assets/pc_right.png") : loadTexture("./assets/pc_left.png");

}

//pc 와 게 충돌
int collision_pc_crab() {
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		if (crabs[i].arrX == pc.arrX && crabs[i].arrY == pc.arrY) {
			walkCnt--;
			pc_damage(); // pc가 붉은색으로 변하는 애니메이션
			return 1;
		}
	}
	return 0;
}

int collision_pc_gogildong(int dx, int dy) { // pc와 길동 충돌


	for (int i = 0; i < MAX_NUM_NPC; i++) {
		if (gildongs[i].arrX == pc.arrX + dx && gildongs[i].arrY == pc.arrY + dy) {
			if (maps[curStage][gildongs[i].arrY + dy][gildongs[i].arrX + dx] == 1) { // 길동 뒤에 벽 (사라짐)
				walkCnt--;
				gildong_run(i); // 길동이 도망가는 에니메이션
				gildongs[i].posX += dx * CELL_WIDTH * 1000;
				gildongs[i].posY += dy * CELL_WIDTH * 1000;
				gildongs[i].arrX += dx;
				gildongs[i].arrY += dy;
				return 1;
			}
			for (int j = 0; j < MAX_NUM_NPC; j++) { // 길동 뒤에 다른 길동이 있는 경우
				if (gildongs[j].arrX == gildongs[i].arrX + dx && gildongs[j].arrY == gildongs[i].arrY + dy) {
					walkCnt--;
					gildong_run(i); // 길동이 도망가는 에니메이션
					gildongs[i].posX += dx * CELL_WIDTH * 1000;
					gildongs[i].posY += dy * CELL_WIDTH * 1000;
					gildongs[i].arrX += dx * 2;
					gildongs[i].arrY += dy * 2;
					return 1;
				}
			}

			for (int j = 0; j < MAX_NUM_NPC; j++) { // 길동 뒤에 바위가 있는 경우
				if (rocks[j].arrX == gildongs[i].arrX + dx && rocks[j].arrY == gildongs[i].arrY + dy)

					if (rocks[j].arrX == gildongs[i].arrX + dx && rocks[j].arrY == gildongs[i].arrY + dy) {
						walkCnt--;
						gildong_run(i); // 길동이 도망가는 에니메이션
						gildongs[i].posX += dx * CELL_WIDTH * 1000;
						gildongs[i].posY += dy * CELL_WIDTH * 1000;
						gildongs[i].arrX += dx * 2;
						gildongs[i].arrY += dy * 2;
						return 1;
					}
			}


			// 충돌한 길동은 한 칸 밀려야 함
			gildongs[i].posX += dx * CELL_WIDTH;
			gildongs[i].posY += dy * CELL_WIDTH;
			gildongs[i].arrX += dx;
			gildongs[i].arrY += dy;
			walkCnt--;
			return 1;

		}
	}
	return 0;
}


// pc와 냉장고 충돌 (스테이지 클리어)
int collision_pc_refrigerator() {
	if (refrigerator.arrX == pc.arrX && refrigerator.arrY == pc.arrY)
		return 1;
	return 0;
}

// pc와 키 충돌검사
void collision_pc_key() {
	if (key.arrX == pc.arrX && key.arrY == pc.arrY) {
		key_flag = 1;
		key.arrX = -1;
		key.arrY = -1;
		key.posX = -100;
		key.posY = -100;
		return;
	}
}

// pc와 문 충돌검사
int collision_pc_door(int dx, int dy) {
	if (door.arrX == pc.arrX + dx && door.arrY == pc.arrY + dy) {
		if (key_flag == 0)
			return 1;
		if (key_flag == 1) {
			door.posX = -100;
			door.posY = -100;
			door.arrX = -1;
			door.arrY = -1;
			return 0;
		}
	}
	return 0;
}

void drawStage(int isGildongRun, int idx) {

	switch (curStage) {
	case 1:
		drawTexture(map1_img, 0, 0);
		break;

	case 2:
		drawTexture(map2_img, 0, 0);
		break;

	case 3:
		drawTexture(map3_img, 0, 0);
		break;
	}

	drawTexture(refrigerator_img, refrigerator.posX, refrigerator.posY);
	drawTexture(roundCnt_img[curStage], 1062, 485);
	drawTexture(key_img, key.posX, key.posY);
	drawTexture(door_img, door.posX, door.posY);


	// 바위 그리기
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		drawTexture(rock_img, rocks[i].posX, rocks[i].posY);
	}

	// 게 그리기
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		drawTexture(crab_img, crabs[i].posX, crabs[i].posY);
	}



	drawTexture(pc_img, pc.posX, pc.posY);

	// 길동 그리기
	if (!isGildongRun) {
		for (int i = 0; i < MAX_NUM_NPC; i++) {
			drawTexture(gildong_img, gildongs[i].posX, gildongs[i].posY);
		}
	}

	else {
		for (int i = 0; i < MAX_NUM_NPC; i++) {
			if (idx == i) continue;
			drawTexture(gildong_img, gildongs[i].posX, gildongs[i].posY);
		}
	}

	if(walkCnt >= 0) 
		drawTexture(walkCnt_imgs[walkCnt], 136, 485);
}

void pc_melting() {

	if (direction_flag == 1) {
		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_right_melt2.png");
		drawStage(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);

		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_right_melt3.png");
		drawStage(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);
	}
	else {
		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_left_melt2.png");
		drawStage(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);

		SDL_RenderClear(renderer);
		pc_img = loadTexture("./assets/pc_left_melt3.png");
		drawStage(0, -1);
		SDL_RenderPresent(renderer);
		Sleep(1000);
	}
	pc_img = loadTexture("./assets/pc_left.png");
}


void gildong_run(int i) {

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_1.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_2.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_3.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_4.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_5.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
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
				if (collision_pc_map(1, 0)) break;
				if (collision_pc_rock(1, 0)) break;
				if (collision_pc_gogildong(1, 0) == 1) break;
				if (collision_pc_door(1, 0)) break;
				walkCnt--;
				pc.posX += CELL_WIDTH;
				pc.arrX++;
				collision_pc_crab();
				collision_pc_key();
				break;
			case 1073741904: // left
				direction_flag = 0;
				pc_img = loadTexture("./assets/pc_left.png");
				if (collision_pc_map(-1, 0)) break;
				if (collision_pc_rock(-1, 0)) break;
				if (collision_pc_gogildong(-1, 0)) break;
				if (collision_pc_door(-1, 0)) break;
				walkCnt--;
				pc.posX -= CELL_WIDTH;
				pc.arrX--;
				collision_pc_crab();
				collision_pc_key();
				break;
			case 1073741905: // down
				if (collision_pc_map(0, 1)) break;
				if (collision_pc_rock(0, 1)) break;
				if (collision_pc_gogildong(0, 1)) break;
				if (collision_pc_door(0, 1)) break;
				walkCnt--;
				pc.posY += CELL_WIDTH;
				pc.arrY++;
				collision_pc_crab();
				collision_pc_key();
				break;
			case 1073741906: // up
				if (collision_pc_map(0, -1)) break;
				if (collision_pc_rock(0, -1)) break;
				if (collision_pc_gogildong(0, -1)) break;
				if (collision_pc_door(0, -1)) break;
				walkCnt--;
				pc.posY -= CELL_WIDTH;
				pc.arrY--;
				collision_pc_crab();
				collision_pc_key();
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
