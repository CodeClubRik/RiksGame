#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "Player.h"
#include <vector>
#include <iostream>
#include "Bullet.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    const int BORDER_WIDTH = 15;
    const int VIEW_WIDTH = 300;
    const int VIEW_HEIGHT = 300;
    
    int playerNum = 4;
    
    int screenWidth = (2 * VIEW_WIDTH) + (3 * BORDER_WIDTH);
    int screenHeight = (2 * VIEW_HEIGHT) + (3 * BORDER_WIDTH );
    
    vector<Player*> playerList;
    vector<Actor*> wallList;
    
    bool quit = false;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("4player RPG!", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    
    if (window == NULL)
        return 0;
    
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    Player p1(renderer, "p1.png", 10, 10, 90);
    Player p2(renderer, "p2.png", 60, 10, 180);
    Player p3(renderer, "p3.png", 10, 60, 270);
    Player p4(renderer, "p4.png", 60, 60, 0);

    Bullet b1(renderer, "wall.png", 10, 10, 1, 0, 0);
    p1.bulletList.push_back(b1);
    
    Actor wall1(renderer, "wall.png", -100, -100, 300, 20);
    wallList.push_back(&wall1);

    Actor wall2(renderer, "wall.png", -100, -100, 20, 300);
    wallList.push_back(&wall2);
    
    Actor wall3(renderer, "wall.png", 180, -100, 20, 300);
    wallList.push_back(&wall3);
    
    Actor wall4(renderer, "wall.png", -100, 180, 300, 20);
    wallList.push_back(&wall4);
    
    if (playerNum > 0) {
        playerList.push_back(&p1);
        p1.setInput(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_F);
    }
    if (playerNum > 1)
        playerList.push_back(&p2);
        p2.setInput(SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE);
    if (playerNum > 2)
        playerList.push_back(&p3);
    if (playerNum > 3)
        playerList.push_back(&p4);
    
    SDL_Event mainEvent;
    
    while (!quit && mainEvent.type != SDL_QUIT) {
        
        SDL_PollEvent(&mainEvent);
        
        const Uint8* keys = SDL_GetKeyboardState(NULL);
            
        //draw bg
            
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        int positionX = 0;
        int positionY = 0;
            
        //handle players
        for (auto itIn = begin (playerList); itIn != end (playerList); ++itIn) {
                
            //handle human player input
            if ((*itIn)->isHuman == true)
                (*itIn)->handleInput(renderer, keys);
                
            //render player views
            (*itIn)->renderView(renderer, playerList, wallList, (VIEW_WIDTH * positionX) + (BORDER_WIDTH * (positionX+1)), (BORDER_WIDTH * (positionY+1)) + (VIEW_HEIGHT * positionY), VIEW_WIDTH, VIEW_HEIGHT);
                
            positionX++;
                
            if (positionX >= 2) {
                positionX = 0;
                positionY++;
            }
            
            for (auto itB = begin((*itIn)->bulletList); itB != end((*itIn)->bulletList); ++itB) {
                itB->update();
            }
        
        }
        
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        
    }
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
