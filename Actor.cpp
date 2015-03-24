#include "Actor.h"

using namespace std;


Actor::Actor(SDL_Renderer* renderer, const char* imgName, int x, int y, int w, int h) {
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    this->texture = NULL;
    this->texture = IMG_LoadTexture(renderer, imgName);
    
}

void Actor::render(SDL_Renderer* renderer, int offsetX, int offsetY, int width, int height) {
    
    SDL_Rect rect;
    rect.x = ((width / 2) - offsetX + this->x);
    rect.y = ((height / 2) - offsetY + this->y);
    rect.w = this->w;
    rect.h = this->h;
    
    SDL_RenderCopy(renderer, this->texture, NULL, &rect);
    
}
