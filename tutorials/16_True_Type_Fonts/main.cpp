#include <LTexture.hpp>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    LTexture text_texture;
    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,"True Type Fonts")){
        std::cerr << "SDL failed to initialize!\n";
    }else{
        font = TTF_OpenFont(appendBasePath("lazy.ttf").c_str(),24);
        if(!font){
            std::cerr << "Failed to load lazy.ttf!\n";
        }else{
            if(!text_texture.load_from_rendered_text(renderer,font,"Hi Im ShiniDev",SDL_Color{0,0,0})){
                std::cerr << "Failed to render text texture!\n";
            }else{
                bool running = true;
                SDL_Event e;
                while(running){
                    while(SDL_PollEvent(&e)!=0){
                        if(e.type==SDL_QUIT){
                            running = false;
                        }
                    }
                    SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                    SDL_RenderClear(renderer);

                    text_texture.render(renderer,(SCREEN_WIDTH-text_texture.get_width())/2,(SCREEN_HEIGHT-text_texture.get_height())/2);

                    SDL_RenderPresent(renderer);
                }
            }
        }
    }
    text_texture.free();
    close(window,renderer,font);
    return 0;
}
