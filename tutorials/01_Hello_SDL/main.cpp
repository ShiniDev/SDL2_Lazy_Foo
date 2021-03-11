#include <iostream>
#include <SDL2/SDL.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[]){
    SDL_Window* win = nullptr;
    SDL_Surface* screen_surface = nullptr;
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << '\n';
    }else{
        win = SDL_CreateWindow("Hello SDL",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(!win){
            std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        }else{
            screen_surface = SDL_GetWindowSurface(win);
            SDL_FillRect(screen_surface,nullptr,SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(win);
            SDL_Delay(2000);
        }
    }
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
