#include <MySdlFunctions.hpp>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc,char* args[]){
    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    SDL_Texture* text = nullptr;
    if(!init(win,rend,SCREEN_WIDTH,SCREEN_HEIGHT,"Texture Loading and Rendering")){
        std::cerr << "Failed to initialize!\n";
    }else{
        text = load_texture(rend,appendBasePath("5.jpg"),ImageType::Other_Img_File);
        if(!text){
            std::cerr << "Failed to load texture!\n";
        }else{
            bool running = true;
            SDL_Event e;
            while(running){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT)running = false;
                }
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend,text,nullptr,nullptr);
                SDL_RenderPresent(rend);
            }
        }
    }
    close(win,text,rend);
    return 0;
}
