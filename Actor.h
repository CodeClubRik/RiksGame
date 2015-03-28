#ifndef __rpg__Actor__
#define __rpg__Actor__

#pragma once

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#endif /* defined(__rpg__Actor__) */

class Actor {
public:
    Actor(SDL_Renderer*, const char*, int, int, int, int,int);
    void render(SDL_Renderer*, int, int, int, int);
    int x;
    int y;
    int w;
    int h;
    int dir;
    SDL_Texture* texture;
};
