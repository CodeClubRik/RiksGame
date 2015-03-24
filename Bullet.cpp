#include "Bullet.h"

using namespace std;

Bullet::Bullet(SDL_Renderer* renderer, const char* imgName, int x, int y, int speed, int direction, int properties)
: Actor(renderer, imgName, x, y, 5, 5) {
    this->speed = speed;
    this->direction = direction;
    this->properties = properties;
    
}
