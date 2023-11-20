#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"

void loadImg(){

player = loadTexture("./assets/player.png");
map1 = loadTexture("./assets/map1.png");
refrigerator = loadTexture("./assets/refrigerator.png");
gogildong1 = loadTexture("./assets/gogildong.png");
gogildong2 = loadTexture("./assets/gogildong.png");
gogildong3 = loadTexture("./assets/gogildong.png");
rock1 = loadTexture("./assets/rock.png");
rock2 = loadTexture("./assets/rock.png");
rock3 = loadTexture("./assets/rock.png");
rock4 = loadTexture("./assets/rock.png");

}