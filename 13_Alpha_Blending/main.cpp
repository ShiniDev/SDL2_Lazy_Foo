#include <iostream>
#include "../WrapperClasses/LTexture.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc,char* args[]){
    SDL_Window* win = nullptr;
    SDL_Renderer* render = nullptr;
    LTexture background_img,modulated_img;
    if(!init(win,render,SCREEN_WIDTH,SCREEN_HEIGHT,"Alpha Blending")){
        std::cerr << "SDL failed to initialize!\n";
    }else{
        if(!modulated_img.load_from_file(render,"fadeout.png")){
            std::cerr << "Failed to load fadeout.png!\n";
        }else{
            if(!background_img.load_from_file(render,"fadein.png")){
                std::cerr << "Failed to load fadein.png!\n";
            }else{
                modulated_img.set_blend_mode(SDL_BLENDMODE_BLEND);
                bool running = true;
                SDL_Event e;
                Uint8 alpha = 255;
                while(running){
                    while(SDL_PollEvent(&e)!=0){
                        if(e.type==SDL_QUIT){
                            running = false;
                        }else if(e.type==SDL_KEYDOWN){
                            if(e.key.keysym.sym==SDLK_w){
                                if(alpha+32>255){
                                    alpha = 255;
                                }else{
                                    alpha+=32;
                                }
                            }else if(e.key.keysym.sym==SDLK_q){
                                if(alpha-32<0){
                                    alpha = 0;
                                }else{
                                    alpha-=32;
                                }
                            }
                        }
                    }
                    SDL_SetRenderDrawColor(render,0xff,0xff,0xff,0xff);
                    SDL_RenderClear(render);

                    background_img.render(render,0,0);

                    modulated_img.set_alpha(alpha);
                    modulated_img.render(render,0,0);

                    SDL_RenderPresent(render);
                }
            }
        }
    }
    background_img.free();
    modulated_img.free();
    close(win,render);
    return 0;
}
