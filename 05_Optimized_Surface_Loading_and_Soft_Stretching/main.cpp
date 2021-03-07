#include <iostream>
#include <SDL2/SDL.h>
#include "../MySdlFunctions.hpp"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc,char* args[]){
    SDL_Window* win = nullptr;
    SDL_Surface* screen_surface = nullptr;
    SDL_Surface* image_surface = nullptr;
    if(!init(win,screen_surface,SCREEN_WIDTH,SCREEN_HEIGHT,"Surface Loading and Soft Stretching")){
        std::cerr << "SDL failed to initialize!\n";
    }else{
        image_surface = optimize_load_surface(screen_surface,"stretch.bmp",ImageType::Bmp_File);
        if(!image_surface){
            std::cerr << "Image failed to load!\n";
        }else {
            SDL_Event e;
            bool running = true;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        running = false;
                    }
                }
                SDL_Rect stretch_rect;
                stretch_rect.x = 0;
                stretch_rect.y = 0;
                stretch_rect.w = SCREEN_WIDTH;
                stretch_rect.h = SCREEN_HEIGHT;
                SDL_BlitScaled(image_surface,nullptr,screen_surface,&stretch_rect);
                SDL_UpdateWindowSurface(win);
            }
        }
    }
    close(win,image_surface);
    return 0;
}
