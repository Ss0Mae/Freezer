#pragma once
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int collision_pc_map(int dx, int dy);
int collision_pc_rock(int dx, int dy);
int collision_pc_gogildong(int dx, int dy);
int collision_pc_refrigerator();
int processKeyInput();
void gildong_run(int i);
void pc_melting();
void drawStage(int isGildongRun, int idx);
void crabUpDown();
void collision_pc_crab();
void pc_damage();

int direction_flag = 1;
int key_flag = 0;
int poison_flag = 0;
int shield_flag = 0;
int poison_cnt = 0;

void crabUpDown() {
	walkForcrab--;
	SDL_RenderClear(renderer);
	if (curStage >= 4) {
		// 게가 올라오고 내려오고
		if (walkForcrab % 2 == 0) {
			crab_img = loadTexture("./assets/crab_up.png");
			for (int i = 0; i < MAX_NUM_NPC; i++)
				drawTexture(crab_img, crabs[i].posX, crabs[i].posY);
		}
		else {
			crab_img = loadTexture("./assets/crab_down.png");
			for (int i = 0; i < MAX_NUM_NPC; i++)
				drawTexture(crab_img, crabs[i].posX, crabs[i].posY);
		}
		drawStage(0, -1);
		SDL_RenderPresent(renderer);
	}
}

// pc와 맵 충돌
int collision_pc_map(int dx, int dy) {
	if (maps[curStage][pc.arrY + dy][pc.arrX + dx] == 1) return 1;
	return 0;
}

void pc_poison() {
	if (poison_flag == 1)
		poison_cnt++;
	if (poison_cnt == 3 || poison_cnt == 6) {
		walkCnt--;
		pc_damage(); // pc가 붉은색으로 변함
		if (poison_cnt == 6) {
			poison_cnt = 0;
			poison_flag = 0;
		}
		return;
	}
}
// pc와 바위 충돌
int collision_pc_rock(int dx, int dy) {
	for (int i = 0; i < MAX_NUM_NPC; i++) { // 바위를 순회하며 각각 pc와 충돌검사
		if (rocks[i].arrX == pc.arrX + dx && rocks[i].arrY == pc.arrY + dy) {


			if (maps[curStage][rocks[i].arrY + dy][rocks[i].arrX + dx] == 1) { // 바위 뒤에 벽이 있는 경우
				return 1;
			}
			for (int j = 0; j < MAX_NUM_NPC; j++) { // 바위 뒤에 다른 바위가 있는 경우
				if (rocks[j].arrX == rocks[i].arrX + dx && rocks[j].arrY == rocks[i].arrY + dy) {
					return 1;
				}
			}

			for (int j = 0; j < MAX_NUM_NPC; j++) { // 바위 뒤에 길동이 있는 경우
				if (gildongs[j].arrX == rocks[i].arrX + dx && gildongs[j].arrY == rocks[i].arrY + dy) {
					return 1;
				}
			}
			if (door.arrX == rocks[i].arrX + dx && door.arrY == rocks[i].arrY + dy) { // 바위뒤에 상자
				return 1;
			}

			// 충돌한 바위는 한칸 밀려야 함
			rocks[i].posX += dx * CELL_WIDTH;
			rocks[i].posY += dy * CELL_WIDTH;
			rocks[i].arrX += dx;
			rocks[i].arrY += dy;
			walkCnt--;
			pc_poison();
			crabUpDown();
			collision_pc_crab();
			return 1;
		}
	}
	return 0;
}




void pc_damage() {

	SDL_RenderClear(renderer);
	// pc의 색이 변함
	pc_img = direction_flag == 1 ? loadTexture("./assets/pc_right_damage.png") : loadTexture("./assets/pc_left_damage.png");
	drawStage(0, -1);
	SDL_RenderPresent(renderer);
	Sleep(150);
	pc_img = direction_flag == 1 ? loadTexture("./assets/pc_right.png") : loadTexture("./assets/pc_left.png");

}

//pc 와 게 충돌
void collision_pc_crab() {
	
	for (int i = 0; i < MAX_NUM_NPC; i++) {

		if (crabs[i].arrX == pc.arrX && crabs[i].arrY == pc.arrY ) { // 게의위치와 pc의위치가 같다면
			if (shield_flag == 1 && (walkForcrab % 2 == 0 || curStage <= 3)) {
				shield_flag = 0;
				return;
			}
			if (walkForcrab % 2 == 0 && (curStage >= 4)) { // 올라와있는 게만 충돌처리
				walkCnt--;
				pc_damage(); // pc가 붉은색으로 변함
				return;
			}
			if (curStage <= 3) {
				walkCnt--;
				pc_damage(); // pc가 붉은색으로 변함
				return;
			}

		}
	}
	
}

int collision_pc_gogildong(int dx, int dy) { // pc와 길동 충돌

	for (int i = 0; i < MAX_NUM_NPC; i++) {
		if (gildongs[i].arrX == pc.arrX + dx && gildongs[i].arrY == pc.arrY + dy) {
			crabUpDown();
			collision_pc_crab();
			//collision_gildongs_crab();
			if (maps[curStage][gildongs[i].arrY + dy][gildongs[i].arrX + dx] == 1) { // 길동 뒤에 벽 (사라짐)
				walkCnt--;
				gildong_run(i); // 길동이 도망가는 에니메이션
				gildongs[i].posX = -100;
				gildongs[i].posY = -100;
				gildongs[i].arrX = -1;
				gildongs[i].arrY = -1;
				return 1;
			}
			for (int j = 0; j < MAX_NUM_NPC; j++) { // 길동 뒤에 다른 길동이 있는 경우
				if (gildongs[j].arrX == gildongs[i].arrX + dx && gildongs[j].arrY == gildongs[i].arrY + dy) {
					walkCnt--;
					gildong_run(i); // 길동이 도망가는 에니메이션
					gildongs[i].posX = -100;
					gildongs[i].posY = -100;
					gildongs[i].arrX = -1;
					gildongs[i].arrY = -1;

					return 1;
				}
			}

			for (int j = 0; j < MAX_NUM_NPC; j++) { // 길동 뒤에 바위가 있는 경우
				if (rocks[j].arrX == gildongs[i].arrX + dx && rocks[j].arrY == gildongs[i].arrY + dy) {
					walkCnt--;
					gildong_run(i); // 길동이 도망가는 에니메이션
					gildongs[i].posX = -100;
					gildongs[i].posY = -100;
					gildongs[i].arrX = -1;
					gildongs[i].arrY = -1;

					return 1;
				}

			}
			//for (int j = 0; j < MAX_NUM_NPC; j++) { //길동뒤에 게가 있고 게가 나와있을때
			//	if (crabs[j].arrX == gildongs[i].arrX + dx && crabs[j].arrY == gildongs[i].arrY + dy && (walkForcrab % 2 == 0 || curStage <= 3)) {
			//		gildongs[i].posX += dx * CELL_WIDTH;
			//		gildongs[i].posY += dy * CELL_WIDTH;
			//		gildongs[i].arrX += dx;
			//		gildongs[i].arrY += dy;
			//		gildong_run(i); // 길동이 도망가는 에니메이션
			//		gildongs[i].posX = -100;
			//		gildongs[i].posY = -100;
			//		gildongs[i].arrX = -1;
			//		gildongs[i].arrY = -1;
			//		return 1;
			//	}
			//}
	
			if (door.arrX == gildongs[i].arrX + dx && door.arrY == gildongs[i].arrY + dy) { //상자 뒤에 길동
				return 1;
			}




			// 충돌한 길동은 한 칸 밀려야 함
			gildongs[i].posX += dx * CELL_WIDTH;
			gildongs[i].posY += dy * CELL_WIDTH;
			gildongs[i].arrX += dx;
			gildongs[i].arrY += dy;
			pc_poison();
			walkCnt--;
			return 1;

		}
	}
	return 0;
}
//
///*추가된 부분 */
//void collision_gildong_crabs(int dx, int dy) {
//	for (int i = 0; i < MAX_NUM_NPC; i++) {
//		for (int j = 0; j < MAX_NUM_NPC; j++){ //길동뒤에 게가 있고 게가 나와있을때
//				if (crabs[j].arrX == gildongs[i].arrX + dx && crabs[j].arrY == gildongs[i].arrY + dy && (walkForcrab % 2 == 0 || curStage <= 3)) {
//					gildongs[i].posX += dx * CELL_WIDTH;
//					gildongs[i].posY += dy * CELL_WIDTH;
//					gildongs[i].arrX += dx;
//					gildongs[i].arrY += dy;
//					gildong_run(i); // 길동이 도망가는 에니메이션
//					gildongs[i].posX = -100;
//					gildongs[i].posY = -100;
//					gildongs[i].arrX = -1;
//					gildongs[i].arrY = -1;
//					return;
//				}
//				if (gildongs[i].arrX == crabs[j].arrX && gildongs[i].arrY == crabs[j].arrY)
//				{
//					gildong_run(i); // 길동이 도망가는 에니메이션
//					gildongs[i].posX = -100;
//					gildongs[i].posY = -100;
//					gildongs[i].arrX = -1;
//					gildongs[i].arrY = -1;
//					return;
//				}
//			}
//	}
//}
/*추가된 부분 끝*/


// pc와 냉장고 충돌 (스테이지 클리어)
int collision_pc_refrigerator() {
	if (refrigerator.arrX == pc.arrX && refrigerator.arrY == pc.arrY)
		return 1;
	return 0;
}

//void collision_gildongs_crab() {
//	int i = 0;
//	for (int j = 0; j < 10; j++) {
//		if (gildongs[i].arrX == crabs[j].arrX && gildongs[i].arrY == crabs[j].arrY && (curStage <= 3 || walkForcrab % 2 == 0)) {
//			gildong_run(i); // 길동이 도망가는 에니메이션
//			gildongs[i].posX = -100;
//			gildongs[i].posY = -100;
//			gildongs[i].arrX = -1;
//			gildongs[i].arrY = -1;
//		}
//		i++;
//	}
//}

// pc와 아이템 충돌검사
void collision_pc_item() {

	// 키 충돌
	if (key.arrX == pc.arrX && key.arrY == pc.arrY) {
		key_flag = 1;
		key.arrX = -1;
		key.arrY = -1;
		key.posX = -100;
		key.posY = -100;
		return;
	}

	// 쉴드 충돌
	if (shield.arrX == pc.arrX && shield.arrY == pc.arrY) {
		shield_flag = 1;
		shield.arrX = -1;
		shield.arrY = -1;
		shield.posX = -100;
		shield.posY = -100;
		return;
	}

	// 독 충돌
	if (poison.arrX == pc.arrX && poison.arrY == pc.arrY) {
		poison_flag = 1;
		poison.arrX = -1;
		poison.arrY = -1;
		poison.posX = -100;
		poison.posY = -100;
		return;
	}

	// 신발 충돌
	if (shoe.arrX == pc.arrX && shoe.arrY == pc.arrY) {
		walkCnt += 2; // 걸음수 하나 증가
		shoe.arrX = -1;
		shoe.arrY = -1;
		shoe.posX = -100;
		shoe.posY = -100;
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
			pc_poison();
			crabUpDown();
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

	case 4:
		drawTexture(map4_img, 0, 0);
		break;

	case 5:
		drawTexture(map5_img, 0, 0);
		break;

	case 6:
		drawTexture(map6_img, 0, 0);
		break;

	case 7:
		drawTexture(map7_img, 0, 0);
		break;

	case 8:
		drawTexture(map8_img, 0, 0);
		break;
	}


	// 바위 그리기
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		drawTexture(rock_img, rocks[i].posX, rocks[i].posY);
	}

	drawTexture(refrigerator_img, refrigerator.posX, refrigerator.posY);
	drawTexture(key_img, key.posX, key.posY);
	drawTexture(poison_img, poison.posX, poison.posY);
	drawTexture(shield_img, shield.posX, shield.posY);
	drawTexture(door_img, door.posX, door.posY);


	// 게 그리기
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		drawTexture(crab_img, crabs[i].posX, crabs[i].posY);
	}


	// pc 그리기
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

	// 신발 그리기
	drawTexture(shoe_img, shoe.posX, shoe.posY);


	// 걸음수 그리기
	if (walkCnt >= 0)
		drawTexture(walkCnt_imgs[walkCnt], 100, 463);
	drawTexture(roundCnt_img[curStage], 1018, 463);

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
	while (_kbhit()) {
		int k = _getch();
	}
	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_2.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);
	while (_kbhit()) {
		int k = _getch();
	}
	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_3.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);
	while (_kbhit()) {
		int k = _getch();
	}
	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_4.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);
	while (_kbhit()) {
		int k = _getch();
	}
	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_5.png");
	drawStage(1, i);
	drawTexture(gildong_run_img, gildongs[i].posX, gildongs[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);
	while (_kbhit()) {
		int k = _getch();
	}
}


SDL_Event event;
int processKeyInput() {
	if (SDL_PollEvent(&event)) {

		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
			case 1073741903: // right
				direction_flag = 1;
				if (collision_pc_map(1, 0)) break;
				if (collision_pc_gogildong(1, 0) == 1) break;
				if (collision_pc_door(1, 0)) break;
				if (collision_pc_rock(1, 0)) break;
				crabUpDown();
				pc_poison();
				walkCnt--;
				pc.posX += CELL_WIDTH;
				pc.arrX++;
				collision_pc_crab();
				collision_pc_item();
				break;
			case 1073741904: // left
				direction_flag = 0;
				if (collision_pc_map(-1, 0)) break;
				if (collision_pc_gogildong(-1, 0)) break;
				if (collision_pc_door(-1, 0)) break;
				if (collision_pc_rock(-1, 0)) break;
				crabUpDown();
				pc_poison();
				walkCnt--;
				pc.posX -= CELL_WIDTH;
				pc.arrX--;
				collision_pc_crab();
				collision_pc_item();
				break;
			case 1073741905: // down
				if (collision_pc_map(0, 1)) break;
				if (collision_pc_gogildong(0, 1)) break;
				if (collision_pc_door(0, 1)) break;
				if (collision_pc_rock(0, 1)) break;
				crabUpDown();
				pc_poison();
				walkCnt--;
				pc.posY += CELL_WIDTH;
				pc.arrY++;
				collision_pc_crab();
				collision_pc_item();
				break;
			case 1073741906: // up
				if (collision_pc_map(0, -1)) break;
				if (collision_pc_gogildong(0, -1)) break;
				if (collision_pc_door(0, -1)) break;
				if (collision_pc_rock(0, -1)) break;
				crabUpDown();
				pc_poison();
				walkCnt--;
				pc.posY -= CELL_WIDTH;
				pc.arrY--;
				collision_pc_crab();
				collision_pc_item();
				break;
			case 27: // ESC
				exit(0);
				break;
			case 114: // R
				return -1;
				break;
			}
	}
		SDL_PollEvent(&event);
		pc_img = direction_flag == 1 ? loadTexture("./assets/pc_right.png") : loadTexture("./assets/pc_left.png");
		if (direction_flag == 1 && shield_flag == 1) pc_img = loadTexture("./assets/pc_right_shield.png");
		else if (direction_flag == 0 && shield_flag == 1) pc_img = loadTexture("./assets/pc_left_shield.png");
		return 1;
}
