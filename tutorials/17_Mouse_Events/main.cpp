#include "../MySdlFunctions.hpp"
#include <LTexture.hpp>
#include <LButton.hpp>
#include <iostream>
#include <vector>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    SDL_Window * window = nullptr;
    SDL_Renderer* renderer = nullptr;
    LTexture button;
    std::vector<SDL_Rect> frames;
    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,"Mouse Events")){
        std::cerr << "SDL failed to initialize!\n";
    }else{
        if(!button.load_from_file(renderer,appendBasePath("button.png"))){
            std::cerr << "Failed to load button.png!\n";
        }else{
            load_sprite_sheet(frames,300,200,button.get_width(),button.get_height());
            LButton but1(button,frames);
            std::cout << "Hi!\n";
            LButton but2(button,frames);
            LButton but3(button,frames);
            LButton but4(button,frames);
            but1.set_position(0,0);
            but2.set_position(300,0);
            but3.set_position(0,200);
            but4.set_position(300,200);
            bool running = true;
            SDL_Event e;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        running = false;
                    }
                    but1.handle_event(&e);
                    but2.handle_event(&e);
                    but3.handle_event(&e);
                    but4.handle_event(&e);
                }

                SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(renderer);

                but1.render(renderer);
                but2.render(renderer);
                but3.render(renderer);
                but4.render(renderer);

                SDL_RenderPresent(renderer);
            }
        }
    }
    button.free();
    close(window,renderer);
    return 0;
}
