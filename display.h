#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"


SDL_Texture* player;
SDL_Texture* map1;
SDL_Texture* refrigerator;
SDL_Texture* gogildong1;
SDL_Texture* gogildong2;
SDL_Texture* gogildong3;
SDL_Texture* rock1;
SDL_Texture* rock2;
SDL_Texture* rock3;
SDL_Texture* rock4;

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


