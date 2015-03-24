#ifndef __rpg__Bullet__
#define __rpg__Bullet__

#pragma once

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "Actor.h"
#include "Player.h"

#endif /* defined(__rpg__Bullet__) */

class Bullet: public Actor  {
public:
    //Bullet(int, int, int);
    Bullet(SDL_Renderer*, const char*, int, int, int, int, int);
    int speed;
    int direction;
    int properties;
    Player* bulletOwner;
};