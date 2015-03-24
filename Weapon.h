#ifndef __rpg__Weapon__
#define __rpg__Weapon__

#pragma once

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "Bullet.h"
#include <vector>

#endif /* defined(__rpg__Weapon__) */

using namespace std;

class Weapon {
public:
    Weapon(int);
    int bulletsLeft;
    vector<Bullet*> firedBullets;
};