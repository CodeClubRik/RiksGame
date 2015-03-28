#ifndef __rpg__Player__
#define __rpg__Player__

#pragma once

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <vector>
#include "Bullet.h"

#endif /* defined(__rpg__Player__) */

using namespace std;

class Player: public Actor {
public:
    //Player(int,int);
    Player(SDL_Renderer*, const char*, int, int, int);
    int score;
    int direction;
    int up;
    int down;
    int left;
    int right;
    int shoot;
    bool isHuman;
    vector<Bullet> bulletList;
    void setInput(int,int,int,int,int);
    void handleInput(SDL_Renderer*, const Uint8*);
    void renderView(SDL_Renderer*, std::vector<Player*>, std::vector<Actor*>, int, int, int, int);
    bool collidesWith(Actor*);
};