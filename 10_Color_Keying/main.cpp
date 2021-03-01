#include "../WrapperClasses/LTexture.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc,char* args[]){
    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    LTexture stickman;
    LTexture background;
    int x = 0, y = 0;
    if(!init(win,rend,SCREEN_WIDTH,SCREEN_HEIGHT,"Color Keying")){
        std::cerr << "Failed to initialize SDL!\n";
    }else{
        if(!stickman.load_from_file_trans(rend,"foo.png",0x00,0xFF,0xFF)){
            std::cerr << "Failed to load foo.png!\n";
        }else{
            if(!background.load_from_file_trans(rend,"background.png",0x00,0xFF,0xFF)){
                std::cerr << "Failed to load background.png!\n";
            }else{
                bool running = true;
                SDL_Event e;
                while(running){
                    while(SDL_PollEvent(&e)!=0){
                        if(e.type==SDL_QUIT)running = false;
                        else if(e.type==SDL_KEYDOWN){
                            switch(e.key.keysym.sym){
                                case SDLK_UP:
                                    y--;
                                    break;
                                case SDLK_DOWN:
                                    y++;
                                    break;
                                case SDLK_RIGHT:
                                    x++;
                                    break;
                                case SDLK_LEFT:
                                    x--;
                                    break;
                                case SDLK_ESCAPE:
                                    running = false;
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    SDL_SetRenderDrawColor(rend,0xFF,0xFF,0xFf,0xFF);
                    SDL_RenderClear(rend);

                    background.render(rend,0,0);
                    stickman.render(rend,x,y);

                    SDL_RenderPresent(rend);
                }
            }
        }
    }
    stickman.free();
    background.free();
    close(win,rend);
    return 0;
}
