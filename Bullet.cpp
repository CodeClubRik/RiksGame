#include "Bullet.h"

using namespace std;

Bullet::Bullet(SDL_Renderer* renderer, const char* imgName, int x, int y, int speed, int direction, int bSpeed, int properties)
: Actor(renderer, imgName, x, y, 5, 5, direction) {
    this->speed = speed;
    this->direction = direction;
    this->properties = properties;
    this->bulletSpeed = bSpeed;
}

void Bullet::update() {
    this->x += this->bulletSpeed;
    this->y += this->bulletSpeed;
}