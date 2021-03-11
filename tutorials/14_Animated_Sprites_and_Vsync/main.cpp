#include <iostream>
#include <vector>
#include <LTexture.hpp>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    SDL_Window* win = nullptr;
    SDL_Renderer* win_renderer = nullptr;
    LTexture sprite_sheet;
    std::vector<SDL_Rect> frames;
    if(!init(win,win_renderer,SCREEN_WIDTH,SCREEN_HEIGHT,"Animated Sprties and Vsync")){
        std::cerr << "SDL failed to initialize!\n";
    }else{
        if(!sprite_sheet.load_from_file_trans(win_renderer,appendBasePath("foo.png"),0x00,0xff,0xff)){
            std::cerr << "Image failed to load!\n";
        }else{
            load_sprite_sheet(frames,64,205,sprite_sheet.get_width(),sprite_sheet.get_height());
            bool running = true;
            const int FRAME_SPEED = 600;
            int frame = 0,x = 0, y = 0;
            SDL_Event e;
            SDL_Rect* current_frame = nullptr;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        running = false;
                    }else if(e.type == SDL_KEYDOWN){
                        auto key = e.key.keysym.sym;
                        if(key==SDLK_w){
                            y-=10;
                        }else if(key==SDLK_s){
                            y+=10;
                        }else if(key==SDLK_a){
                            x-=10;
                        }else if(key==SDLK_d){
                            x+=10;
                        }
                    }
                }
                SDL_SetRenderDrawColor(win_renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(win_renderer);

                current_frame = &frames[frame/FRAME_SPEED];
                sprite_sheet.render(win_renderer,x,y,current_frame);

                SDL_RenderPresent(win_renderer);

                frame++;
                if(frame / FRAME_SPEED >= frames.size()){
                    frame = 0;
                }
            }
        }
    }
    sprite_sheet.free();
    close(win,win_renderer);
    return 0;
}
