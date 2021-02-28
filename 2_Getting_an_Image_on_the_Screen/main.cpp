#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init(SDL_Window **win,SDL_Surface **surf){
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
        success = false;
    }else{
        *win = SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(!*win){
            std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
            success = false;
        }else{
            *surf = SDL_GetWindowSurface(*win);
        }
    }
    return success;
}

bool load_media(const char* filepath,SDL_Surface **surf){
    bool success = true;
    *surf = SDL_LoadBMP(filepath);
    if(!*surf){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        success = false;
    }
    return success;
}

void close(SDL_Window **win,SDL_Surface **surf){
    SDL_FreeSurface(*surf);
    *surf = nullptr;
    SDL_DestroyWindow(*win);
    *win = nullptr;
    SDL_Quit();
}

int main(){
    SDL_Window* win = nullptr;
    SDL_Surface* screen_surface = nullptr;
    SDL_Surface* shini_surface = nullptr;
    if(!init(&win,&screen_surface)){
        std::cerr << "Failed to Initialize!\n";
    }else{
        if(!load_media("shinidev.bmp",&shini_surface)){
            std::cerr << "Failed to load media!\n";
        }else{
            SDL_BlitSurface(shini_surface,nullptr,screen_surface,nullptr);
            SDL_UpdateWindowSurface(win);
            SDL_Delay(2000);
        }
    }
    close(&win,&shini_surface);
    return 0;
}
