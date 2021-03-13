#include <LTimer.hpp>
#include <LTexture.hpp>
#include <MySdlFunctions.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <string>


int main(int argc,char* argv[])
{
    std::string s = SDL_GetBasePath();
    constexpr int SCREEN_WIDTH = 640;
    constexpr int SCREEN_HEIGHT = 480;
    SDL_Window* window = nullptr; 
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    LTexture startInstructions,pauseInstructions,timeTexture;
    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,"Advanced Timers"))
    {
        std::cerr << "Failed to initialize window and renderer!\n";
    }
    else 
    {
        font = TTF_OpenFont(appendString(s,"lazy.ttf").c_str(),32);
        if(!font)
        {
            std::cerr << "Failed to initialize lazy.ttf!\n";
        }
        else 
        {
            bool running = true; 

            SDL_Event event;
            SDL_Color color = {0,0,0,255};
            startInstructions.load_from_rendered_text(renderer,font,"S to start/stop",color);
            pauseInstructions.load_from_rendered_text(renderer,font,"P to pause/unpause",color);

            LTimer timer;

            std::stringstream text;
            while(running)
            {
                while(SDL_PollEvent(&event))
                {
                    if(event.type==SDL_QUIT)
                    {
                        running = false;
                    }
                    else if(event.type==SDL_KEYDOWN)
                    {
                        auto key = event.key.keysym.sym;
                        if(key==SDLK_s)
                        {
                            if(timer.isStarted())
                            {
                                timer.stop();
                            }
                            else
                            {
                                timer.start();
                            }
                        }
                        else if(key==SDLK_p)
                        {
                            if(timer.isPaused())
                            {
                                timer.unpause();
                            }
                            else
                            {
                                timer.pause();
                            }
                        }
                    }
                }
                text.str("");
                text << "Seconds since start time " << (timer.getTicks()/1000.0);
                if(!timeTexture.load_from_rendered_text(renderer,font,text.str(),color)) 
                {
                    std::cerr << "Unable to render text!\n";
                }
                SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff);
                SDL_RenderClear(renderer);
                startInstructions.render(renderer,(SCREEN_WIDTH-startInstructions.get_width())/2,0);
                pauseInstructions.render(renderer,(SCREEN_WIDTH-pauseInstructions.get_width())/2,pauseInstructions.get_height());
                timeTexture.render(renderer,(SCREEN_WIDTH-timeTexture.get_width())/2,(SCREEN_HEIGHT-timeTexture.get_height())/2);
                SDL_RenderPresent(renderer);
            }
        }
    }
    close(window,renderer);
    return 0;
}