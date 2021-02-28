#include <iostream>
#include <SDL2/SDL.h>
#include "../MySdlFunctions.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]){
    SDL_Window* win = nullptr;
    SDL_Surface* screen_surface = nullptr;
    SDL_Surface* shini_surface = nullptr;
    if(!init(win,screen_surface,SCREEN_WIDTH,SCREEN_HEIGHT,"Image on Screen")){
        std::cerr << "Failed to Initialize!\n";
    }else{
        if(!load_media(shini_surface,"shinidev.bmp",ImageType::BMP_FILE)){
            std::cerr << "Failed to load media!\n";
        }else{
            SDL_BlitSurface(shini_surface,nullptr,screen_surface,nullptr);
            SDL_UpdateWindowSurface(win);
            SDL_Delay(2000);
        }
    }
    close(win,shini_surface);
    return 0;
}
