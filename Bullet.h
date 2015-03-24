#ifndef __rpg__Bullet__
#define __rpg__Bullet__

#pragma once

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#endif /* defined(__rpg__Bullet__) */

class Bullet {
public:
    Bullet(int, int, int);
    int speed;
    int direction;
    int properties;
};