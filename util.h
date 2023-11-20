#pragma once

SDL_Event event;

void processKeyInput() {
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
}