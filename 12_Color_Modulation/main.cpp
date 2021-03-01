#include "../WrapperClasses/LTexture.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    LTexture img;
    if(!init(win,rend,SCREEN_WIDTH,SCREEN_HEIGHT,"Color Modulation")){
        std::cerr << "SDL failed to initialize!\n";
    }else{
        if(!img.load_from_file(rend,"3.jpeg")){
            std::cerr << "Image failed to load!\n";
        }else{
            bool running = true;
            SDL_Event e;
            Uint8 r = 255;
            Uint8 g = 255;
            Uint8 b = 255;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT)running = false;
                    else if(e.type==SDL_KEYDOWN){
                        switch(e.key.keysym.sym){
                            case SDLK_q:
                                r-=15;
                                break;
                            case SDLK_w:
                                g-=15;
                                break;
                            case SDLK_e:
                                b-=15;
                                break;
                            case SDLK_a:
                                r+=15;
                                break;
                            case SDLK_s:
                                g+=15;
                                break;
                            case SDLK_d:
                                b+=15;
                                break;
                            case SDLK_ESCAPE:
                                running = false;
                                break;
                            default:
                                break;
                        }
                    }
                }

                SDL_SetRenderDrawColor(rend,0xff,0xff,0xff,0xf);
                SDL_RenderClear(rend);

                img.render(rend,0,0);
                img.set_color(r,g,b);

                SDL_RenderPresent(rend);
            }
        }
    }
    img.free();
    close(win,rend);
    return 0;
}
