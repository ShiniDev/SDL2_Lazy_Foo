#include <iostream>
#include <SDL2/SDL.h>
#include "../MySdlFunctions.hpp"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* args[]){
    SDL_Window* win = nullptr;
    SDL_Surface* screen_surface = nullptr;
    SDL_Surface* image_surface = nullptr;
    SDL_Event e;
    bool running = true;
    if(!init(win,screen_surface,SCREEN_WIDTH,SCREEN_HEIGHT,"Event Driven")){
        std::cerr << "Failed to initialize!\n";
    }else{
        if(!load_media(image_surface,"ubuntu-icon-2.bmp",ImageType::BMP_FILE)){
            std::cerr << "Failed to load image!\n";
        }else{
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        running = false;
                    }
                }
                SDL_BlitSurface(image_surface,nullptr,screen_surface,nullptr);
                SDL_UpdateWindowSurface(win);
            }
        }
    }
    close(win,image_surface);
    return 0;
}
