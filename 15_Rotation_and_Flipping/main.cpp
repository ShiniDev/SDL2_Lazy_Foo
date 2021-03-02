#include <iostream>
#include "../WrapperClasses/LTexture.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    LTexture arrow_img;
    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,"Rotation and Flipping")){
        std::cerr << "SDL failed to initialize!\n";
    }else{
        if(!arrow_img.load_from_file(renderer,"arrow.png")){
            std::cerr << "Failed to load arrow.png!\n";
        }else{
            bool running = true;
            SDL_Event e;

            double degrees = 0.0;
            int xpos = 0, ypos = 0;
            SDL_RendererFlip flip_type = SDL_FLIP_NONE;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        running = false;
                    }else if(e.type==SDL_KEYDOWN){
                        auto key = e.key.keysym.sym;
                        switch(key){
                            case SDLK_q:
                                flip_type = SDL_FLIP_VERTICAL;
                                break;
                            case SDLK_w:
                                flip_type = SDL_FLIP_NONE;
                                break;
                            case SDLK_e:
                                flip_type = SDL_FLIP_HORIZONTAL;
                                break;
                            case SDLK_a:
                                degrees+=30;
                                break;
                            case SDLK_d:
                                degrees-=30;
                                break;
                            case SDLK_UP:
                                ypos -= 10;
                                break;
                            case SDLK_DOWN:
                                ypos += 10;
                                break;
                            case SDLK_LEFT:
                                xpos -= 10;
                                break;
                            case SDLK_RIGHT:
                                xpos += 10;
                                break;
                            case SDLK_ESCAPE:
                                running = false;
                                break;
                            default:
                                break;
                        }
                    }
                }
                SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(renderer);
                arrow_img.render(renderer,xpos,ypos,nullptr,degrees,nullptr,flip_type);
                SDL_RenderPresent(renderer);
            }
        }
    }
    arrow_img.free();
    close(window,renderer);
    return 0;
}
