#include "../MySdlFunctions.hpp"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* args[]){
    SDL_Window* win = nullptr;
    SDL_Surface* win_surface = nullptr;
    SDL_Surface* img_surface = nullptr;
    if(!init(win,win_surface,SCREEN_WIDTH,SCREEN_HEIGHT,"Extension Libraries and Loading Other Image Formats")){
        std::cerr << "SDL could not be initialized! SDL Error: " << SDL_GetError() << '\n';
    }else{
        img_surface = optimize_load_surface(win_surface,"1.jpg",ImageType::OTHER_IMG_FILE);
        if(!img_surface){
            std::cerr << "Image could not be loaded! SDL Error: " << SDL_GetError() << '\n';
        }else{
            bool running = true;
            SDL_Event e;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        running = false;
                    }
                }
                SDL_BlitScaled(img_surface,nullptr,win_surface,nullptr);
                SDL_UpdateWindowSurface(win);
            }
        }
    }
    return 0;
}
