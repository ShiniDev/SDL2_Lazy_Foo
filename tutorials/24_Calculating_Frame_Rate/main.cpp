#include <MySdlFunctions.hpp>
#include <LTexture.hpp>
#include <LTimer.hpp>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <sstream>
#include <string>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc,char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    
    LTexture fpsRenderer;
    TTF_Font* font = nullptr;

    //Get base path
    std::string basePath = SDL_GetBasePath();

    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_WIDTH,"Calculating Frame Rate"))
    {
        std::cerr << "Failed to initialize SDL! SDL Error: " << SDL_GetError() << '\n';
    }
    else 
    {
        //Basepath is important so that the resources are always found
        font = TTF_OpenFont(appendString(basePath,"lazy.ttf").c_str(),28);
        if(!font)
        {
            std::cerr << "Failed to load lazy.ttf! SDL Error: " << SDL_GetError() << '\n';
        }
        else
        {
            LTimer timer;            

            SDL_Event e;
            Uint32 frames = 0;

            std::stringstream fpsText;

            bool quit = false;

            timer.start();
            while(!quit)
            {
                while(SDL_PollEvent(&e))
                {
                    if(e.type==SDL_QUIT)
                    {
                        quit = true;
                    }
                    else if(e.key.keysym.sym==SDLK_ESCAPE)
                    {
                        quit = true;
                    }
                }
                float fps = frames / (timer.getTicks()/1000.0f);
                if(fps>240000)
                {
                    fps = 0;
                }

                fpsText.str("");
                fpsText << "Average frame rate per second " << fps;

                fpsRenderer.load_from_rendered_text(renderer,font,fpsText.str().c_str(),SDL_Color{0,0,0});

                SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(renderer);

                fpsRenderer.render(renderer,(SCREEN_WIDTH-fpsRenderer.get_width())/2,(SCREEN_HEIGHT-fpsRenderer.get_height())/2);

                SDL_RenderPresent(renderer);

                ++frames;
            }
        }
        TTF_CloseFont(font);
        font = nullptr;
    }
    close(window,renderer);
    return 0;
}