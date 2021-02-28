#ifndef MYSDLFUNCTIONS_HPP
#define MYSDLFUNCTIONS_HPP
#include <iostream>
#include <SDL2/SDL.h>

inline bool init(SDL_Window **win,SDL_Surface **surf,int SCREEN_WIDTH,int SCREEN_HEIGHT){
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

inline bool load_media(const char* filepath,SDL_Surface **surf){
    bool success = true;
    *surf = SDL_LoadBMP(filepath);
    if(!*surf){
        std::cerr << "Unable to load image " << filepath << "! SDL Error: " << SDL_GetError() << '\n';
        success = false;
    }
    return success;
}

inline void close(SDL_Window **win,SDL_Surface **surf){
    SDL_FreeSurface(*surf);
    *surf = nullptr;
    SDL_DestroyWindow(*win);
    *win = nullptr;
    SDL_Quit();
}
#endif
