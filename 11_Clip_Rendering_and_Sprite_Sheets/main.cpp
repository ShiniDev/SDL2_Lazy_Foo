#include "../WrapperClasses/LTexture.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc,char* args[]){
    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    LTexture img;
    std::vector<SDL_Rect> r;
    if(!init(win,rend,SCREEN_WIDTH,SCREEN_HEIGHT,"Clip Rendering and Sprite Sheets")){
        std::cerr << "Failed to initialize SDL!\n";
    }else{
        if(!img.load_from_file_trans(rend,"sprites.png",0x00,0xff,0xff)){
            std::cerr << "Failed to load image!\n";
        }else{
            load_sprite_sheet(r,100,100,img.get_width(),img.get_height());
            bool running = true;
            SDL_Event e;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT)running = false;
                }
                SDL_SetRenderDrawColor(rend,0xff,0xff,0xff,0xff);
                SDL_RenderClear(rend);

                img.render(rend,0,0,&r[0]);
                img.render(rend,SCREEN_WIDTH-r[1].w,0,&r[1]);
                img.render(rend,0,SCREEN_HEIGHT-r[2].h,&r[2]);
                img.render(rend,SCREEN_WIDTH-r[3].w,SCREEN_HEIGHT-r[3].h,&r[3]);

                SDL_RenderPresent(rend);
            }
        }
    }
    img.free();
    close(win,rend);
    return 0;
}
