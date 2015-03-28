#include "Player.h"

using namespace std;

Player::Player(SDL_Renderer* renderer, const char* imgName, int x, int y, int direction)
: Actor(renderer, imgName, x, y, 20, 20, 0) {
    this->score = 0;
    this->up = 0;
    this->down = 0;
    this->left = 0;
    this->right = 0;
    this->isHuman = false;
    this->shootFrequency = 20;
    this->timeSinceLastBullet = this->shootFrequency;
    this->shootSpeed = 4;
}

void Player::setInput(int up, int down, int left, int right, int shoot, int rotateLeft, int rotateRight) {
    
    this->isHuman = true;
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
    this->shoot = shoot;
    this->rotateLeft = rotateLeft;
    this->rotateRight = rotateRight;
}

void Player::handleInput(SDL_Renderer* renderer, const Uint8* keys) {
    
    if (keys[up])
        this->y -= 1;
    if (keys[down])
        this->y += 1;
    if (keys[left])
        this->x -= 1;
    if (keys[right])
        this->x += 1;
    if (keys[shoot] && timeSinceLastBullet > this->shootFrequency) {
        this->timeSinceLastBullet = 0;
        Bullet b1(renderer, "wall.png", this->x + (this->w / 2), this->y + (this->h / 2), 1, 0, this->shootSpeed, 0);
        bulletList.push_back(b1);
    }
    if (keys[rotateLeft]) {
        this->dir = (this->dir - 2);
        if(this->dir < 0)
            this->dir += 360;
    }
    if (keys[rotateRight])
        this->dir = (this->dir + 2) % 360;
    
    cout << this->dir << endl;
}

void Player::renderView(SDL_Renderer* renderer, vector<Player*> playerList, vector<Actor*> wallList, int x, int y, int w, int h) {
    
    SDL_Rect playerViewport;
    
    playerViewport.x = x;
    playerViewport.y = y;
    playerViewport.w = w;
    playerViewport.h = h;
    SDL_RenderSetViewport(renderer, &playerViewport );
    
    SDL_Rect r;
    r.x = 0;
    r.y = 0;
    r.w = w;
    r.h = h;
    SDL_SetRenderDrawColor( renderer, 255, 250, 240, 255 );
    // Render rect
    SDL_RenderFillRect( renderer, &r );
    
    
    //render all players
    for (auto it2 = begin (playerList); it2 != end (playerList); ++it2) {
        (*it2)->render(renderer, this->x + (this->w / 2), this->y + (this->h / 2), w, h);
        
        //render all bullets for the player
        vector<Bullet> bList;
        bList = (*it2)->bulletList;
        
        for (auto itB = begin(bList); itB != end(bList); ++itB) {
            itB->render(renderer, this->x + (this->w / 2), this->y + (this->h / 2), w, h);
        }
        
    }
    //render all walls
    for (auto itWall = begin (wallList); itWall != end (wallList); ++itWall) {
        (*itWall)->render(renderer, this->x + (this->w / 2), this->y + (this->h / 2), w, h);
    }
}

void Player::update() {
    timeSinceLastBullet ++;
}

bool Player::collidesWith(Actor* actor) {
    if  (this->x > 100) {
        return true;
    }
    else {
        return false;
    }
}
