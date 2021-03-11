#include <MySdlFunctions.hpp>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc,char* args[]){
    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    SDL_Texture* img = nullptr;
    if(!init(win,rend,SCREEN_WIDTH,SCREEN_HEIGHT,"The Viewport")){
        std::cerr << "Failed to initialize SDL!\n";
    }else{
        img = load_texture(rend,appendBasePath("pixeltv.png"),ImageType::Other_Img_File);
        if(!img){
            std::cerr << "Failed to load image!\n";
        }else{
            bool running = true;
            SDL_Event e;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT)running = false;
                }
                SDL_Rect top_left_viewport,top_right_viewport,bottom_viewport;
                top_left_viewport.x = 0;
                top_left_viewport.y = 0;
                top_left_viewport.w = SCREEN_WIDTH/2;
                top_left_viewport.h = SCREEN_HEIGHT/2;
                SDL_RenderSetViewport(rend,&top_left_viewport);
                SDL_RenderCopy(rend,img,nullptr,nullptr);

                top_right_viewport.x = SCREEN_WIDTH/2;
                top_right_viewport.y = 0;
                top_right_viewport.w = SCREEN_WIDTH/2;
                top_right_viewport.h = SCREEN_HEIGHT/2;
                SDL_RenderSetViewport(rend,&top_right_viewport);
                SDL_RenderCopy(rend,img,nullptr,nullptr);

                bottom_viewport.x = 0;
                bottom_viewport.y = SCREEN_HEIGHT/2;
                bottom_viewport.w = SCREEN_WIDTH;
                bottom_viewport.h = SCREEN_HEIGHT/2;
                SDL_RenderSetViewport(rend,&bottom_viewport);
                SDL_RenderCopy(rend,img,nullptr,nullptr);
                SDL_RenderPresent(rend);
            }
        }
    }
    return 0;
}
