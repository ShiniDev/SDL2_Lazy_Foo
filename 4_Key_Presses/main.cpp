#include <iostream>
#include <SDL2/SDL.h>
#include "MySdlFunctions.hpp"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc,char* args[]){
    SDL_Window* win = nullptr;
    SDL_Surface* screen_surface = nullptr;
    SDL_Surface* current_key_surface = nullptr;
    SDL_Surface* key_surface[KEY_PRESS_SURFACE_TOTAL];
    if(!init(win,screen_surface,SCREEN_WIDTH,SCREEN_HEIGHT)){
        std::cerr << "Failed to initialize SDL!\n";
    }else{
        if(!load_media(key_surface)){
            std::cerr << "Failed to load key images!\n";
        }else{
            bool running = true;
            SDL_Event e;
            current_key_surface = key_surface[KEY_PRESS_SURFACE_DEFAULT];
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        running = false;
                    }else if(e.type==SDL_KEYDOWN){
                        switch(e.key.keysym.sym){
                            case SDLK_UP:
                                current_key_surface = key_surface[KEY_PRESS_SURFACE_UP];
                                break;
                            case SDLK_DOWN:
                                current_key_surface = key_surface[KEY_PRESS_SURFACE_DOWN];
                                break;
                            case SDLK_LEFT:
                                current_key_surface = key_surface[KEY_PRESS_SURFACE_LEFT];
                                break;
                            case SDLK_RIGHT:
                                current_key_surface = key_surface[KEY_PRESS_SURFACE_RIGHT];
                                break;
                            default:
                                current_key_surface = key_surface[KEY_PRESS_SURFACE_DEFAULT];
                                break;
                        }
                    }
                }
                SDL_BlitSurface(current_key_surface,nullptr,screen_surface,nullptr);
                SDL_UpdateWindowSurface(win);
            }
        }
    }
    for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++){
        if(key_surface[i]==current_key_surface)continue;
        delete key_surface[i];
    }
    close(win,current_key_surface);
    return 0;
}
